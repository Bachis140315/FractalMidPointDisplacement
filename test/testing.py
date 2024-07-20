import subprocess
import os
import matplotlib.pyplot as plt
import numpy as np

import seaborn as sns


diamondSquare = []
midPoint = [] 

exe_name = "testing.exe"

src_path = "build/test/"
def Arraytest(n,t):
    current_dir = os.path.dirname(os.path.abspath(__file__))
    os.chdir(current_dir)
    os.chdir("..")
    current_dir = os.getcwd()
    current_dir = os.path.join(current_dir, src_path)
    os.chdir(current_dir)
    exe_path = os.path.join(current_dir, exe_name)
    args = [str(n), str(t)]
    result = subprocess.run([exe_path] + args, capture_output=True, text=True)
    print("Salida estándar:", result.stdout)
    print("Error estándar:", result.stderr)
    if result.returncode == 0: 
        print(result.stdout)
        
        if t == 0:
            midPoint.append(float(result.stdout.split("\n")[0]))
        else:
            diamondSquare.append(float(result.stdout.split("\n")[0]))

        


def Plotting():
    nTotal = []
    for i in range(2,4):
        Arraytest(2**i,0)
        Arraytest(2**i,1)
        nTotal.append(i)
    

            #print(line)
    print(midPoint)
    print(diamondSquare)
    plt.plot(nTotal,midPoint,"-",label='MidPoint')
    plt.plot(nTotal,diamondSquare,"-",label='DiamondSquare')
    plt.title('Comparacion de algoritmos')
    plt.xlabel('Numero de iteraciones (2^n)')
    plt.ylabel('Tiempo (ms)')
    plt.legend()
    plt.show()

Plotting()

