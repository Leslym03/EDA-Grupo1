def bubbleSort(arr):
   n = len(arr)
   for i in range(n):
   for j in range(0, n-i-1):
      if arr[j] > arr[j+1] :
         arr[j], arr[j+1] = ar[j+1], ar[j]
arr = ['t','u','t','o','r','i','a','l']
bubbleSort(arr)
print ("Sorted array is:")
for i in range(len(arr)):
   print (arr[i])