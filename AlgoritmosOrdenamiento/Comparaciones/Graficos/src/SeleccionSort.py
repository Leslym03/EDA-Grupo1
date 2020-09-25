import numpy as np

from matplotlib import pyplot as plt

x,y = np.loadtxt('Medidas/SeleccionSortcc.txt' , delimiter=',' , unpack=True)
x1,y1 = np.loadtxt('Medidas/SeleccionSortpy.txt' , delimiter=',' , unpack=True)
x2,y2 = np.loadtxt('Medidas/SeleccionSortjav.txt' , delimiter=',' , unpack=True)


plt.plot(x,y*1000,color="blue",label="Seleccion Sort en C++")
plt.plot(x1,y1*1000,color="yellow",label="Seleccion Sort en Python")
plt.plot(x2,y2*1000,color="red",label="Seleccion Sort en Java")

plt.legend()
plt.title('Algoritmo de  Selection')
plt.xlabel('Cantidad de datos')
plt.ylabel('Tiempo de ejecucion (en milisegundos)')
plt.text(300000,50000000,r'$O(n^2)$', fontsize=12)
plt.show()
