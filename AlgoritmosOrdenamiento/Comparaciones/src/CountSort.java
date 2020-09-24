import java.util.Scanner;
import java.io.*;

class CountSort {
    void countSort(int array[], int size) {
        int[] output = new int[size + 1];
    
        int max = array[0];
        for (int i = 1; i < size; i++) {
          if (array[i] > max)
            max = array[i];
        }
        int[] count = new int[max + 1];
    
        for (int i = 0; i < max; ++i) {
          count[i] = 0;
        }
    
        for (int i = 0; i < size; i++) {
          count[array[i]]++;
        }
    
        for (int i = 1; i <= max; i++) {
          count[i] += count[i - 1];
        }
    
        for (int i = size - 1; i >= 0; i--) {
          output[count[array[i]] - 1] = array[i];
          count[array[i]]--;
        }
    
        for (int i = 0; i < size; i++) {
          array[i] = output[i];
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
            ento = new FileReader("Entradas/aleatorio10.txt");
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
                        ob.countSort(A, A.length); 
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
            FileWriter escritura=new FileWriter("Salidas/CountSort/salida10jav.txt");
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
