import numpy as np
from matplotlib import pyplot as plt


x1,y1 = np.loadtxt('Medidas/BubbleSortcc.txt' , delimiter=' ' , unpack=True)
x2,y2 = np.loadtxt('Medidas/CountSortcc.txt' , delimiter=' ' , unpack=True)
x3,y3 = np.loadtxt('Medidas/HeapSortcc.txt' , delimiter=' ' , unpack=True)
x4,y4 = np.loadtxt('Medidas/InsertionSortcc.txt' , delimiter=' ' , unpack=True)
x5,y5 = np.loadtxt('Medidas/MergeSortcc.txt' , delimiter=' ' , unpack=True)
x6,y6 = np.loadtxt('Medidas/QuickSortcc.txt' , delimiter=' ' , unpack=True)
x7,y7 = np.loadtxt('Medidas/SeleccionSortcc.txt' , delimiter=',' , unpack=True)

plt.plot(x1,y1*25,color="red",label="BubbleSort")
plt.plot(x2,y2,color="blue",label="CountSort")
plt.plot(x3,y3,color="yellow",label="HeapSort")
plt.plot(x4,y4*25,color="pink",label="InsertionSort")
plt.plot(x5,y5,color="purple",label="MergeSort")
plt.plot(x6,y6,color="green",label="QuickSort")
plt.plot(x7,y7,color="skyblue",label="SeletionSort")

plt.legend()
plt.title('Algoritmos en C++')
plt.xlabel('Cantidad de datos')
plt.ylabel('Tiempo de ejecucion (segundos)')
plt.show()