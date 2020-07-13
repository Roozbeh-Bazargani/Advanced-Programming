import os
import numpy as np
import random

# making texts
for repeat in range(1,8):
    ar_random = np.array([[random.randint(-50,49) for x in range(5)] for y in range(10)])
    np.savetxt("Text"+repeat.__str__()+".txt", ar_random, delimiter=", ", newline="\n", fmt="%s")

# put files in array
texts = [file for file in os.listdir(os.getcwd()) if file.endswith('.txt')]
texts.append("Text.txt")

# processing texts
for text in texts:
    if not os.path.exists(text): # text does exist?
        print("File '{}' does not exists!".format(text))
        break;

    lastavg, sum, vrnc = 0, 0, 0
    file = open(text, "r") # reading file

    # extract numbers
    lines = file.read().replace(', ', ' ').replace('\n',' ').split()

    # for all numbers
    for num in range (0,50):
        sum += int(lines[num])
    avg = sum / 50

    # last column
    for num in range (4,50,5):
        lastavg += int(lines[num])
    lastavg /= 10

    # variance
    for num in range (0,50):
        vrnc += (int(lines[num]) - avg) ** 2
        vrnc /= 50

    # showing results
    print("File '{}' -> last line average = {}  , Variance = {}".format(text, lastavg, vrnc))
    file.close()
