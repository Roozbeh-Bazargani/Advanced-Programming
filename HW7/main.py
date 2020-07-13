import re
import numpy as np
from io import StringIO


with open('Q1.txt','r') as read_handle:
    file = read_handle.read()

file = file + '\n'

lis = list(file)
nplis = np.array(lis)

mat = np.reshape(nplis,[-1,4])
mat2 = mat.transpose()
print(mat2)
s=''
for item in np.nditer(mat2.T.copy(order = 'F')):
    s += str(item)
pat1 = re.compile((r'([^A-z]{2})?[A-z]+([^A-z]{2})?'))
sr = re.finditer(pat1,s )
s = ''
for i in sr:
    s += i.group(0)
print(s)

pat2 = re.compile(r'[A-z]+')
ss=''
srr = re.finditer(pat2,s)
for i in srr:
    ss += i.group(0)
    ss += ' '

print(ss)








