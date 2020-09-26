import numpy as np

from matplotlib import pyplot as plt

x,y = np.loadtxt('Medidas/SeleccionSortcc.txt' , delimiter=',' , unpack=True)
x1,y1 = np.loadtxt('Medidas/SeleccionSortjav.txt' , delimiter=',' , unpack=True)
x2,y2 = np.loadtxt('Medidas/SeleccionSortpy.txt' , delimiter=',' , unpack=True)

plt.plot(x,y,color="blue",label="Seleccion Sort en C++")
plt.plot(x1,y1,color="yellow",label="Seleccion Sort en Java")
plt.plot(x2,y2,color="red",label="Seleccion Sort en Python")

plt.legend()
plt.title('Algoritmo SelectionSort')
plt.xlabel('Cantidad de datos')
plt.ylabel('Tiempo de ejecucion (segundos)')
plt.text(220000,55000,r'$O(n^2)$', fontsize=12)
plt.show()
