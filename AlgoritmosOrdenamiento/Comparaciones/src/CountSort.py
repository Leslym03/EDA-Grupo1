from io import open
from time import time

def countingSort(array):
    size = len(array)
    output = [0] * size

    maxi = int(array[0])

    for i in range(1,size):
        if int(array[i]) > int(maxi):
            maxi = int(array[i]);

    count = [0] * (maxi+1)

    for i in range(0, size):
        count[int(array[i])] += 1

    for i in range(1, maxi+1):
        count[i] += count[i - 1]

    i = size - 1
    while i >= 0:
        output[count[int(array[i])] - 1] = array[i]
        count[int(array[i])] -= 1
        i -= 1

    for i in range(0, size):
        array[i] = output[i]


tam = [100000,200000,300000,400000, 500000,600000,700000,800000,900000, 1000000]
times = [0,0,0,0,0,0,0,0,0,0]
f=open("Salidas/CountSort/salida10py.txt","w")

for j in range(10):            
    file = open("Entradas/aleatorio10.txt","r")
    A = file.readlines()
    file.close()

    B=[0]*tam[j]

    for i in range(tam[j]):
        B[i]=int(A[i])

    t0=time()
    countingSort(A) 
    tiempo = time()-t0
    tiempo = round(tiempo,3)

    A.clear()
    f.write(str(tam[j])+" "+str(tiempo)+"\n")
