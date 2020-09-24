from io import open
from time import time

def mergeSort(arr): 
	if len(arr) >1: 
		mid = len(arr)//2
		L = arr[:mid] 
		R = arr[mid:] 

		mergeSort(L) 
		mergeSort(R) 

		i = j = k = 0

		while i < len(L) and j < len(R): 
			if L[i] < R[j]: 
				arr[k] = L[i] 
				i+= 1
			else: 
				arr[k] = R[j] 
				j+= 1
			k+= 1

		while i < len(L): 
			arr[k] = L[i] 
			i+= 1
			k+= 1
		
		while j < len(R): 
			arr[k] = R[j] 
			j+= 1
			k+= 1



tam = [100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000]
times = [0,0,0,0,0,0,0,0,0,0]
f=open("Salidas/MergeSort/salida1py.txt","w")

for j in range(10):            
    file = open("Entradas/aleatorio1.txt","r")
    A = file.readlines()
    file.close()

    for i in range(tam[j]):
        A[i]=int(A[i])

    t0=time()
    mergeSort(A) 
    tiempo = time()-t0
    tiempo = round(tiempo,3)

    A.clear()
    f.write(str(tam[j])+" "+str(tiempo)+"\n")
