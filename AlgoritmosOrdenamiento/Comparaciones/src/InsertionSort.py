from io import open
from time import time

def insertionSort(arr): 
    for i in range(1, len(arr)): 
        key = arr[i] 
        j = i-1
        while j >= 0 and key < arr[j] : 
                arr[j + 1] = arr[j] 
                j -= 1
        arr[j + 1] = key 

tam = [100000, 300000, 500000, 700000, 1000000]
times = [0,0,0,0,0]
f=open("Salidas/InsertionSort/salida1py.txt","w")

for j in range(5):            
    file = open("Entradas/aleatorio1.txt","r")
    A = file.readlines()
    file.close()

    for i in range(tam[j]):
        A[i]=int(A[i])

    t0=time()
    insertionSort(A) 
    tiempo = time()-t0
    tiempo = round(tiempo,3)

    A.clear()
    f.write(str(tam[j])+" "+str(tiempo)+"\n")
