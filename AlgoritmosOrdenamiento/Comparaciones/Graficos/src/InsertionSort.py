import numpy as np
from matplotlib import pyplot as plt

x1,y1 = np.loadtxt('Medidas/InsertionSortcc.txt' , delimiter=' ' , unpack=True)
x2,y2 = np.loadtxt('Medidas/InsertionSortjav.txt' , delimiter=' ' , unpack=True)
x3,y3 = np.loadtxt('Medidas/InsertionSortpy.txt' , delimiter=' ' , unpack=True)

plt.plot(x1,y1*25,color="blue",label="InsertionSort en C++")
plt.plot(x2,y2*25,color="yellow",label="InsertionSort en  Java")
plt.plot(x3,y3*25,color="red",label="InsertionSort en  Python")

plt.legend()
plt.title('Algoritmo InsertionSort')
plt.xlabel('Cantidad de datos')
plt.ylabel('Tiempo de ejecucion (segundos)')
plt.text(240000,18000,r'$O(n^2)$', fontsize=12)
plt.show()