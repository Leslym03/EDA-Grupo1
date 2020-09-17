public class HeapSort{
	static void heapify(int[] array, int size, int indice){
		int temp; // swap variable
		int largest = indice;
		int l = 2 * indice + 1;
		int r = 2 * indice + 2;
		
		if(l < size && array[l] > array[largest])
			largest = l;
		if(r < size && array[r] > array[largest])
			largest = r;
		if(largest != indice){
			temp = array[indice];
			array[indice] = array[largest];
			array[largest] = temp;
			heapify(array, size, largest);
		}
	}
	static void heapSort(int[] array, int size){
		for(int i = size/2 - 1; i >= 0; --i)
			heapify(array, size, i);
		for(int i = size - 1 ; i > 0; --i){
			int temp;
			temp = array[0];
			array[0] = array[i];
			array[i] = temp;
			heapify(array, i, 0);
		}
	}	
	public static void main(String[] args){
		int array[] = { 12, 11, 1, 3, 13, 5, 6, 7};
		int n = array.length;
		heapSort(array, n);
		
		for(int i = 0; i < n; ++i){
			System.out.print(array[i] + " ");
		}
		System.out.print("\n");
	}
}
