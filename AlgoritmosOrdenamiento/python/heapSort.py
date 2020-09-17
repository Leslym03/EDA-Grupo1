def heapify (array, size, indice):
    largest = indice
    l = 2 * indice + 1
    r = 2 * indice + 2
    if l < size and array[l] > array[largest]:
        largest = l;
    if r < size and array[r] > array[largest]:
        largest = r;
    if largest != indice:
        array[indice], array[largest] = array[largest], array[indice]
        heapify(array, size, largest)

def heapSort(array, size):
    for i in range (int(size / 2) - 1, -1, -1):
        heapify(array, size , i);
    for i in range (size - 1, 0, -1):
        array[0], array[i] = array[i], array[0]
        heapify(array, i, 0)

array = [12,11,1,3,13,5,6,7]
n = len(array)
heapSort(array,n)
print("Array ordenado: ")
for i in range(n):
    print (array[i])

