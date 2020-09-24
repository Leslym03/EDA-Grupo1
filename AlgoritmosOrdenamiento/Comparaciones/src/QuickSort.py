from io import open
from time import time

def partition(arr, low, high):
    i = (low-1)
    pivot = arr[high]
 
    for j in range(low, high):
        if arr[j] <= pivot:
            i = i+1
            arr[i], arr[j] = arr[j], arr[i]
 
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return (i+1)

def quickSort(arr, low, high):
    if len(arr) == 1:
        return arr
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)

tam = [100000,200000,300000,400000, 500000,600000,700000,800000,900000, 1000000]
times = [0,0,0,0,0,0,0,0,0,0]
f=open("Salidas/QuickSort/salida1py.txt","w")

for j in range(10):            
    file = open("Entradas/aleatorio1.txt","r")
    A = file.readlines()
    file.close()

    for i in range(tam[j]):
        A[i]=int(A[i])

    t0=time()
    quickSort(A,0,tam[j]-1) 
    tiempo = time()-t0
    tiempo = round(tiempo,3)

    A.clear()
    f.write(str(tam[j])+" "+str(tiempo)+"\n")
