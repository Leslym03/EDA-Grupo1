public class QuickSort {
    public void quickSort(int[] arr) {
        quickSort(arr, 0, arr.length - 1);
    }

    private void quickSort(int[] arr, int low, int high) {
        if(low < high + 1) {
            int p = partition(arr, low, high);
            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
    }

    private int partition(int[] arr, int low, int high) {
        int x = arr[high];
        int i = low - 1;
        
        for(int j = low; j <= high - 1; ++j) {
            if(arr[j] <= x) {
                swap(arr, ++i, j);
            }
        }
        
        swap(arr, i + 1, high);
        return i + 1;
    }

    private void swap(int arr[], int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp; 
    }

    public static void main(String[] args) {
        QuickSort qs = new QuickSort();
        int arr[] = { 5, 4, 2, 3, 1};  
        qs.quickSort(arr);

        for(int i = 0; i < arr.length; ++i) {  
            System.out.print(arr[i] + " ");  
        }
        System.out.print("\n");
    }  
}