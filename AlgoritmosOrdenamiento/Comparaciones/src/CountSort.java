import java.util.Scanner;
import java.io.*;

class CountSort {
    void countSort(int[] arr) { 
        int max = Arrays.stream(arr).max().getAsInt(); 
        int min = Arrays.stream(arr).min().getAsInt(); 
        int range = max - min + 1; 
        int count[] = new int[range]; 
        int output[] = new int[arr.length]; 
        for (int i = 0; i < arr.length; i++) { 
            count[arr[i] - min]++; 
        } 
  
        for (int i = 1; i < count.length; i++) { 
            count[i] += count[i - 1]; 
        } 
  
        for (int i = arr.length - 1; i >= 0; i--) { 
            output[count[arr[i] - min] - 1] = arr[i]; 
            count[arr[i] - min]--; 
        } 
  
        for (int i = 0; i < arr.length; i++) { 
            arr[i] = output[i]; 
        } 
    } 
    
    public static void main(String args[]){   
        Read acc = new Read();
        Write out= new Write();

        double A;
        int tams[] = {100000, 300000, 500000, 700000, 1000000}; 
        double times[];
        times = new double[5];
        
        for(int i=0;i<5;i++){
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
                        CountSort ob = new CountSort(); 
                        TInicio = System.currentTimeMillis();
                        ob.countSort(A); 
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
            FileWriter escritura=new FileWriter("Salidas/CountSort/salida1jav.txt");
            String tipeo;
            String temp;
            for(int i=0; i<5; i++){
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
