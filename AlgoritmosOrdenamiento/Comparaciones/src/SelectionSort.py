from io import open
from time import time

def selectionSort(arr):
    for i in range(len(arr)): 
        min_idx = i 
        for j in range(i+1, len(arr)): 
            if arr[min_idx] > arr[j]: 
                min_idx = j 
        arr[i], arr[min_idx] = arr[min_idx], arr[i] 


tam = [100000, 300000, 500000, 700000, 1000000]
times = [0,0,0,0,0]
f=open("Salidas/SelectionSort/salida1py.txt","w")

for j in range(5):            
    file = open("Entradas/aleatorio1.txt","r")
    A = file.readlines()
    file.close()

    for i in range(tam[j]):
        A[i]=int(A[i])

    t0=time()
    selectionSort(A) 
    tiempo = time()-t0
    tiempo = round(tiempo,3)

    A.clear()
    f.write(str(tam[j])+" "+str(tiempo)+"\n")
