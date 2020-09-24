from io import open
from time import time

def count_sort(arr): 
    max_element = int(max(arr)) 
    min_element = int(min(arr)) 
    range_of_elements = max_element - min_element + 1

    count_arr = [0 for _ in range(range_of_elements)] 
    output_arr = [0 for _ in range(len(arr))] 
  
    for i in range(0, len(arr)): 
        count_arr[arr[i]-min_element] += 1
  
    for i in range(1, len(count_arr)): 
        count_arr[i] += count_arr[i-1] 

    for i in range(len(arr)-1, -1, -1): 
        output_arr[count_arr[arr[i] - min_element] - 1] = arr[i] 
        count_arr[arr[i] - min_element] -= 1

    for i in range(0, len(arr)): 
        arr[i] = output_arr[i] 


tam = [100000, 300000, 500000, 700000, 1000000]
times = [0,0,0,0,0]
f=open("Salidas/CountSort/salida1py.txt","w")

for j in range(5):            
    file = open("Entradas/aleatorio1.txt","r")
    A = file.readlines()
    file.close()

    for i in range(tam[j]):
        A[i]=int(A[i])

    t0=time()
    count_sort(A) 
    tiempo = time()-t0
    tiempo = round(tiempo,3)

    A.clear()
    f.write(str(tam[j])+" "+str(tiempo)+"\n")
