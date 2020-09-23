#include <iostream>
using namespace std;

template < typename Type >
void BubbleSort( Type *arr, int n );
template < typename Type >
Type getMax(Type array[], int size);
template < typename Type >
void countSort(Type *array, int size);
template < typename Type>
void Heapify ( Type *, int , int );
template < typename Type>
void HeapSort ( Type *, int );
template < typename Type >
void InsertionSort( Type *, int );
template < typename Type >
void Merge( Type *, int, int, int );
template < typename Type >
void MergeSort( Type *, int );
template < typename Type >
void MergeSort( Type *, int, int );
template < typename Type >
void QuickSort( Type *, int );
template < typename Type >
void QuickSort( Type *, int, int );

template < typename Type >
void Imprimir( Type *, int );
template < typename Type >
void Swap( Type &, Type & );
// BUBBLE SORT

template < typename Type >
void BubbleSort( Type *arr, int size ) {
    for ( int i = size - 1; i > 0; i-- )       
        for ( int j = 0; j < i; j++ )
            if( arr[ j ] > arr[ j + 1 ]) 
                Swap( arr[ j ], arr[ j + 1 ]); 
}

// COUNTING SORT

template < typename Type >
Type getMax(Type array[], int size) {
   Type max = array[1];
   for(int i = 2; i<=size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max; 
}

template < typename Type >
void countSort(Type *array, int size) {
   Type output[size+1];
   Type max = getMax(array, size);
   Type count[max+1];     
   for(int i = 0; i<=max; i++)
      count[i] = 0;     
   for(int i = 1; i <=size; i++)
      count[array[i]]++;     
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];    
   for(int i = size; i>=1; i--) {
      output[count[array[i]]] = array[i];
      count[array[i]] -= 1; 
   }
   for(int i = 1; i<=size; i++) {
      array[i] = output[i]; 
    }
}

// HEAP SORT

template <typename Type>
void Heapify ( Type * array, int size, int indice){
	int largest = indice;
	int l = 2 * indice + 1;
	int r = 2 * indice + 2;

	if(l < size && array[l] > array[largest])
			largest = l;

	if(r < size && array[r] > array[largest])
			largest = r;

	if(largest != indice){
		swap<Type>(array[indice], array[largest]);
		Heapify<Type>(array, size, largest);
	}
}

template <typename Type>
void HeapSort(Type *array, int size){
	for(int i = size / 2 - 1; i >= 0; i--)
		Heapify<Type>(array, size, i);

	for(int i = size - 1; i > 0; i--){
		Swap<Type>(array[0], array[i]);
		Heapify<Type>(array, i, 0);
	}
}

// INSERTION SORT

template < typename Type >
void InsertionSort( Type *arr, int size ) { 
    for ( int i = 1, j, k; i < size; i++ ) { 
        k = arr[ i ]; 
        j = i - 1; 
        while ( j >= 0 && arr[ j ] > k ) { 
            arr[ j + 1 ] = arr[ j ]; 
            j--; 
        } 
        arr[ j + 1 ] = k; 
    } 
}

//MERGE SORT

template < typename Type >
void Merge( Type *arr, int left, int mid, int right ) {

    Type *temp = new Type[ right - left + 1 ];
    int i = left;
    int j = mid + 1;
    int k = 0;

    while( i <= mid && j <= right ) {
        if( arr[ i ] <= arr[ j ])
            temp[ k++ ] = arr[ i++ ];
        else
            temp[ k++ ] = arr[ j++ ];
    }

    while( i <= mid )
        temp[ k++ ] = arr[ i++ ];
    while( j <= right )
        temp[ k++ ] = arr[ j++ ];
    for( k = 0, i = left; i <= right; ++i, ++k )
        arr[ i ] = temp[ k ];
 
    delete[] temp;
}

template < typename Type >
void MergeSort( Type *arr, int size ) {
    
    MergeSort( arr, 0, size - 1 );
}

template < typename Type >
void MergeSort( Type *arr, int left, int right ) {
    
    int mid = ( left + right ) / 2;

    if( left < right ) {
        MergeSort( arr, left, mid );
        MergeSort( arr, mid + 1, right );
        Merge( arr, left, mid, right );
    }
}

// QUICKSORT

template < typename Type >
void QuickSort( Type arr[], int size ) {

    QuickSort( arr, 0, size - 1 );
}

template < typename Type >
void QuickSort( Type arr[], int left, int right ) {

    int i = left, j = right;
    int pivot = arr[( left + right ) / 2 ];

    while( i <= j ) {
        while ( arr[ i ] < pivot )
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            Swap( arr[ i ], arr[ j ]);
                i++;
                j--;
        }
    }

    if (left < j)
        QuickSort( arr, left, j );
    if (i < right)
        QuickSort( arr, i, right );
}


//SELECCION SORT

template < typename Type >
void selectionSort(Type *arr, int n) {  
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++) {  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        swap(arr[min_idx], arr[i]);  
    }  
}  


// OTRAS FUNCIONES

template < typename Type >
void Swap( Type &a, Type &b ) {
    Type temp = a;
    a = b;
    b = temp;
}

template < typename Type >
void Imprimir( Type *arr, int size ) {

    for( int i = 0; i < size; ++i ) {
        cout << *( arr + i ) << " ";
    }
    cout << endl;
}