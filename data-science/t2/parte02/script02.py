import sys
import os
import pefile
import sys

exe_1 = sys.argv[2]
exe_2 = sys.argv[3]

directory = sys.argv[1]

# Open file
pe_1 = pefile.PE(os.path.join(directory, exe_1))
pe_2 = pefile.PE(os.path.join(directory, exe_2))


a = []
b = []

for section in pe_1.sections:
    a.append(section.Name)

for section in pe_2.sections:
    b.append(section.Name)


print('\n===================\n')
print('  Seções comuns')
print('\n===================\n')
aux = set(a).intersection(b)

for value in aux:
	print(value.decode('utf-8'))

print('\n============================\n')
print('  Seções únicas por binário')
print('\n============================\n')

aux_a = list(set(a).difference(b))
if (not aux_a):
	print('Não há seções únicas no binário', exe_1, '\n')
else:
	print('Seções presentes apenas no binário', exe_1)
	for value in aux_a:
		print(value.decode('utf-8'))
	print('\n')

aux_b = list(set(b).difference(a))
if (not aux_b):
	print('Não há seções únicas no binário', exe_2, '\n')
else:
	print('Seções presentes apenas no binário', exe_2)
	for value in aux_b:
		print(value.decode('utf-8'))
	print('\n')


# Close file
pe_1.close() 
pe_2.close() 