import java.util.Scanner;
import java.io.*;

class MergeSort {
    void merge(int arr[], int l, int m, int r) 
	{ 

		int n1 = m - l + 1; 
		int n2 = r - m; 

		int L[] = new int[n1]; 
		int R[] = new int[n2]; 

		for (int i = 0; i < n1; ++i) 
			L[i] = arr[l + i]; 
		for (int j = 0; j < n2; ++j) 
			R[j] = arr[m + 1 + j]; 

		int i = 0, j = 0; 

		int k = l; 
		while (i < n1 && j < n2) { 
			if (L[i] <= R[j]) { 
				arr[k] = L[i]; 
				i++; 
			} 
			else { 
				arr[k] = R[j]; 
				j++; 
			} 
			k++; 
		} 

		while (i < n1) { 
			arr[k] = L[i]; 
			i++; 
			k++; 
		} 

		while (j < n2) { 
			arr[k] = R[j]; 
			j++; 
			k++; 
		} 
    }  
    
    void sort(int arr[], int l, int r) 
	{ 
		if (l < r) { 
			int m = (l + r) / 2; 
			sort(arr, l, m); 
			sort(arr, m + 1, r); 
			merge(arr, l, m, r); 
		} 
    } 
    

    public static void main(String args[]){   
        Read acc = new Read();
        Write out= new Write();

        double A;
        int tams[] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
        double times[];
        times = new double[10];
        
        for(int i=0;i<10;i++){
            A = acc.reading(tams[i]);
            times[i] = A;
        }
        out.writing(tams,times);
    }
}

class Read{
    public double reading(int n){
        double t_1=1.1;
        try{
            ento = new FileReader("Entradas/aleatorio1.txt");
            BufferedReader buffer = new BufferedReader(ento);

            String linea="";
          	double TInicio, TFin;
            int A[];
            A=new int[n];
            int entero,i;
            i=0;

            while(linea!=null){
                linea=buffer.readLine();
                if(linea!=null){
                    linea=linea.substring(0,linea.length()-1);
                    entero = Integer.parseInt(linea);
                    A[i]=entero;
                    i=i+1;
                    if(i==n){
                        MergeSort ob = new MergeSort(); 
                        TInicio = System.currentTimeMillis();
                        ob.sort(A, 0, A.length - 1); 
                        TFin = System.currentTimeMillis();
                        t_1 = (TFin - TInicio)/1000;
                        break;
                    }                
                }
            }           
        }catch (IOException e){
            System.out.println("Error");
        }finally{
            try{
                ento.close();
            }catch (IOException e) {
                e.printStackTrace();
            }
        }
    return t_1;
    }    
    FileReader ento;
}

class Write{
    public void writing(int tams [], double times[]){   
        try {
            FileWriter escritura=new FileWriter("Salidas/MergeSort/salida1jav.txt");
            String tipeo;
            String temp;
            for(int i=0; i<10; i++){
                tipeo = times[i]+"";
                temp = tams[i]+"";
                escritura.write(tams[i]+" "+tipeo+"\n");
            }
            escritura.close(); 
        }catch (IOException e){
            e.printStackTrace();
        }
    }
}
