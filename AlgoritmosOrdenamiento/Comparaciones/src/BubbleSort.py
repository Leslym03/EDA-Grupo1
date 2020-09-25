from io import open
from time import time

def bubbleSort(arr):
   n = len(arr)
   for i in range(n):
      for j in range(0, n-i-1):
         if int(arr[j]) > int(arr[j+1]) :
            arr[j], arr[j+1] = arr[j+1], arr[j]

tam = [100000, 300000, 500000, 700000, 1000000]
times = [0,0,0,0,0]
f=open("Salidas/BubbleSort/salida1py.txt","w")

for j in range(5):            
    file = open("Entradas/aleatorio1.txt","r")
    A = file.readlines()
    file.close()

    B=[0]*tam[j]

    for i in range(tam[j]):
        B[i]=int(A[i])

    t0=time()
    bubbleSort(A) 
    tiempo = time()-t0
    tiempo = round(tiempo,3)

    A.clear()
    f.write(str(tam[j])+" "+str(tiempo)+"\n")