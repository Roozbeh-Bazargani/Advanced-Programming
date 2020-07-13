import ctypes as ct
import os
import matplotlib.pyplot as plt
from time import process_time
# find dll path
dll_path = os.path.join("Project1.dll")
# load dll
dll = ct.cdll.LoadLibrary(dll_path)

Fibonacci = dll.Fibonacci
Fibonacci.argtypes = [ct.c_int64]
Fibonacci.restype = ct.c_char_p


file = open("Q2.txt", "r") # reading file
numbers = file.read().replace('\n',' ').split()
ptime = []
for num in numbers:
    # run dll
    t0 = process_time()
    fib = int(Fibonacci(int(num)))
    t1 = process_time() * 1000000 - t0 * 1000000
    ptime.append(t1)
    print("Fibonacci({})= {} -> Took: {:.6} microseconds".format(num ,fib, t1))
# reading cpp runtimes
runtimefile = open('Fibonacci_C++_runtime.txt')
runtimes = runtimefile.read().replace('\n',' ').split()
runtime = []
for i in range(1,len(runtimes),3):
    runtime.append(int(runtimes[i]))

# plot
plt.scatter(numbers,runtime)
plt.show()

plt.scatter(numbers,ptime)
plt.show()