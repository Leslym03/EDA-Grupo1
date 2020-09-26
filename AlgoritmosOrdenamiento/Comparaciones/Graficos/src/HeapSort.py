import numpy as np
from matplotlib import pyplot as plt

x1,y1 = np.loadtxt('Medidas/HeapSortcc.txt' , delimiter=' ' , unpack=True)
x2,y2 = np.loadtxt('Medidas/HeapSortjav.txt' , delimiter=' ' , unpack=True)
x3,y3 = np.loadtxt('Medidas/HeapSortpy.txt' , delimiter=' ' , unpack=True)

plt.plot(x1,y1,color="blue",label="HeapSort en C++")
plt.plot(x2,y2,color="yellow",label="HeapSort en  Java")
plt.plot(x3,y3,color="red",label="HeapSort en  Python")

plt.legend()
plt.title('Algoritmo HeapSort')
plt.xlabel('Cantidad de datos')
plt.ylabel('Tiempo de ejecucion (segundos)')
plt.text(160000,8.5,r'$O(nlogn)$', fontsize=12)
plt.show()