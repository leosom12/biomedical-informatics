import xmltodict
import sys
import os
import re
import functools

def binarySearch (arr, l, r, x): 
  
    # Check base case 
    if r >= l: 
  
        mid = l + (r - l) // 2
  
        # If element is present at the middle itself 
        if arr[mid] == x: 
            return mid 
          
        # If element is smaller than mid, then it  
        # can only be present in left subarray 
        elif arr[mid] > x: 
            return binarySearch(arr, l, mid-1, x) 
  
        # Else the element can only be present  
        # in right subarray 
        else: 
            return binarySearch(arr, mid + 1, r, x) 
  
    else: 
        # Element is not present in the array 
        return -1
    
directory = sys.argv[1]
# directory = "manifests"

print('\n===================\n')
print('Permissões por APK')
print('\n===================\n')

my_dict = {}

for filename in os.listdir(directory):
    if filename.endswith(".xml"): 
        f = open(os.path.join(directory, filename))
        filename = filename.replace('.xml', '')
        filename = filename.replace('AndroidManifest_', '')
        
        # Convert XML to dict
        to_dict = xmltodict.parse(f.read())
        lista = to_dict['manifest']['uses-permission']
    
        permission_list = []
        
        # Iterate over the list with the permissions
        for n in range(len(lista)):
            string = str(lista[n])
            aux = string.split('.')
            permission = (len(aux)) - 1
            regex = re.compile('\'\)]\)')
            tmp = regex.sub("", str(aux[permission]))
            permission_list.append(tmp)
        
        permission_list.sort()
        my_dict[filename] = permission_list
        
        # Close XML
        f.close()

for k, v in my_dict.items():
    print(k,':', v, '\n')


print('\n===================\n')
print('Permissões únicas por APK')
print('\n===================\n')


for k in my_dict.keys():
    unic_permission = []
    for v in my_dict.values():
        for i in range(len(v)):
            permission = v[i]
            is_unique = 1
            for intern_key, intern_value in my_dict.items():
                if (k != intern_key):
                    found = binarySearch (intern_value, 0, len(intern_value)-1, permission)
                        
                    # Found an equal value, so the permission is not unique
                    if (found != -1):
                        is_unique = 0

            # The permission is unique
            if (is_unique):
                unic_permission.append(permission)

                
    print(k, ':', unic_permission, '\n')
    
print('\n===================\n')
print('Permissões comuns das APK')
print('\n===================\n')
print(functools.reduce(set.intersection, (set(val) for val in my_dict.values())))
print('\n\n\n')