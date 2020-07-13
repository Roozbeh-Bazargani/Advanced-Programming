import re
import numpy as np

# read text
file = open('Q1.txt' , 'r')

# extract words
lines = file.readlines()


size = len(lines[0]) - 1

text = ""

# reading from up to down then left to right
for i in range (0,size):
    for line in lines:
        text += line[i]


# change it to what we want
text1 = re.sub(r'[^A-Za-z]'," ",text)


text2 = re.sub(r'\s\s+',"0",text1)


text3 = re.sub(r'\s',"",text2)


text4 = re.sub(r'\d'," ",text3) + '.'
print(text4)