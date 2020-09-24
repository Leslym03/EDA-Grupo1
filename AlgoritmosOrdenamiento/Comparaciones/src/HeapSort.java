import java.util.Scanner;
import java.io.*;

class HeapSort {
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
                        HeapSort ob = new HeapSort(); 
                        TInicio = System.currentTimeMillis();
                        ob.heapSort(A, A.length); 
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
            FileWriter escritura=new FileWriter("Salidas/HeapSort/salida1jav.txt");
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
