import pefile
import sys
import os

directory = sys.argv[1]

my_dict = {}

for filename in os.listdir(directory):
    if filename.endswith(".exe"):         
        # Open file
        pe = pefile.PE(os.path.join(directory, filename))
        
        for section in pe.sections:
            # Permission
            if (section.IMAGE_SCN_MEM_EXECUTE):
                teste = str(section.Name.decode('utf-8'))
                my_dict[filename] = teste


    # Close file
    pe.close() 

print('\n')
print('Nome do binário : [seções executáveis]\n')
for k, v in my_dict.items():
    print(k,':', v, '\n')
print('\n')