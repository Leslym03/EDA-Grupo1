from io import open
from time import time

def heapify (array, size, indice):
    largest = indice
    l = 2 * indice + 1
    r = 2 * indice + 2
    if l < size and array[l] > array[largest]:
        largest = l
    if r < size and array[r] > array[largest]:
        largest = r
    if largest != indice:
        array[indice], array[largest] = array[largest], array[indice]
        heapify(array, size, largest)

def heapSort(array, size):
    for i in range (int(size / 2) - 1, -1, -1):
        heapify(array, size , i)
    for i in range (size - 1, 0, -1):
        array[0], array[i] = array[i], array[0]
        heapify(array, i, 0)

tam = [100000,200000,300000,400000, 500000,600000,700000,800000,900000, 1000000]
times = [0,0,0,0,0,0,0,0,0,0]
f=open("Salidas/HeapSort/salida1py.txt","w")

for j in range(10):            
    file = open("Entradas/aleatorio1.txt","r")
    A = file.readlines()
    file.close()

    for i in range(tam[j]):
        A[i]=int(A[i])

    t0=time()
    heapSort(A,tam[j]) 
    tiempo = time()-t0
    tiempo = round(tiempo,3)

    A.clear()
    f.write(str(tam[j])+" "+str(tiempo)+"\n")
