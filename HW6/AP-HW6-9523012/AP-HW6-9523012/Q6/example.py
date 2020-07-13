import GaussSolver as GS
import math
import subprocess as subP
from time import process_time as pr
import matplotlib.pyplot as plt

def f(x):
    x1 = 0.5 * x + 0.5
    return ( x1  ** 3 / (x1 + 1)) * math.cos(x1 ** 2 )

N = 10

pyt_time = []
pyt_ans = []
cpp_time = []

for n in range(1,N+1):
    t1_pyt = pr()
    my_solver = GS.GaussSolver(0, 1, f, n)
    my_solver.exec()
    answer = my_solver.get_result()
    t2_pyt = pr()
    t1_cpp = pr()
    # running cpp code
    subP.call(["ConsoleApplication58.exe", str(n)])
    t2_cpp = pr()
    print("Result of Pyt code (n =  {}): {:.20} \t time:{:.10}".format(n, answer,t2_pyt - t1_pyt))
    print('cpp time: {:.10}'.format(t2_cpp - t1_cpp))
    pyt_time.append(t2_pyt - t1_pyt)
    cpp_time.append(t2_cpp - t1_cpp)
    pyt_ans.append(answer)
    print('\n')

# plotting the time results
plt.figure('Python')
plt.title('Python code')
plt.plot(list(f for f in range(N)), pyt_ans)
plt.figure('C++')
plt.title('C++ code')
plt.plot(list(f for f in range(N)), pyt_time, cpp_time)
plt.show()