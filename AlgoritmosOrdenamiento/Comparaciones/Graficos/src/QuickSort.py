import numpy as np
from matplotlib import pyplot as plt

x1,y1 = np.loadtxt('Medidas/QuickSortcc.txt' , delimiter=' ' , unpack=True)
x2,y2 = np.loadtxt('Medidas/QuickSortjav.txt' , delimiter=' ' , unpack=True)
x3,y3 = np.loadtxt('Medidas/QuickSortpy.txt' , delimiter=' ' , unpack=True)

plt.plot(x1,y1*1000,color="blue",label="QuickSort en C++")
plt.plot(x2,y2*1000,color="yellow",label="QuickSort en  Java")
plt.plot(x3,y3*1000,color="red",label="QuickSort en  Python")

plt.legend()
plt.title('Algoritmo QuickSort')
plt.xlabel('Cantidad de datos')
plt.ylabel('Tiempo de ejecucion (milisegundos)')
plt.show()