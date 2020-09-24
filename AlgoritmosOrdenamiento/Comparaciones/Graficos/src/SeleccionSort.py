import numpy as np

from matplotlib import pyplot as plt

x,y = np.loadtxt('salida1cc.txt' , delimiter=',' , unpack=True)
x1,y1 = np.loadtxt('salida1py.txt' , delimiter=',' , unpack=True)
x2,y2 = np.loadtxt('salida1jav.txt' , delimiter=',' , unpack=True)


plt.plot(x,y,color="blue",label="Seleccion Sort en C++")
plt.plot(x1,y1,color="yellow",label="Seleccion Sort en  Python")
plt.plot(x2,y2,color="red",label="Seleccion Sort en  java")

plt.legend()
plt.title('Algoritmo de  Selection')
plt.xlabel('Cantidad de datos')
plt.ylabel('Tiempo de ejecucion')
plt.text(300000,50000,r'$O(n^2)$', fontsize=12)
plt.show()