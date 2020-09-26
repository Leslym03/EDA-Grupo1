import numpy as np
from matplotlib import pyplot as plt

x1,y1 = np.loadtxt('Medidas/MergeSortcc.txt' , delimiter=' ' , unpack=True)
x2,y2 = np.loadtxt('Medidas/MergeSortjav.txt' , delimiter=' ' , unpack=True)
x3,y3 = np.loadtxt('Medidas/MergeSortpy.txt' , delimiter=' ' , unpack=True)

plt.plot(x1,y1,color="blue",label="MergeSort en C++")
plt.plot(x2,y2,color="yellow",label="MergeSort en  Java")
plt.plot(x3,y3,color="red",label="MergeSort en  Python")

plt.legend()
plt.title('Algoritmo MergeSort')
plt.xlabel('Cantidad de datos')
plt.ylabel('Tiempo de ejecucion (segundos)')
plt.text(220000,2.5,r'$O(nlogn)$', fontsize=12)
plt.show()