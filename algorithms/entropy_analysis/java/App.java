import java.io.File;
import java.io.FileNotFoundException;
import java.util.Formatter;
import java.util.Scanner;

public class App {

    private static final int SAME_SIZE_VECTORS  = 5;
    private static final String INSTANCE_PATH = "//...//entropy_analysis//instancias//"; // FULL PATH here to access parent folder.
    private static final String STATISTICAL_FILE_PATH = "results//statistic.txt"; 
    //private static final String SORTED_PATH = "results//sorted_vectors//"; 
    private static Formatter statisticalFormatter = null;
    
    public static void main(String[] args) {
        final int type = Integer.valueOf(args[0]);
        
        File f = new File(STATISTICAL_FILE_PATH);
        try {
            statisticalFormatter = new Formatter(f);
        } catch (FileNotFoundException ex) {
            ex.printStackTrace();
        }
	 
        // All files have n-1 elements.
        final int size1 = 100000; // Ex.: 99.999.
        final int size2 = 500000;
        final int size3 = 1000000;
        final int sort1 = 10;
        final int sort2 = 50;
        final int sort3 = 90;

        sortVectorFromFile(INSTANCE_PATH, sort1, size1-1, type);
        sortVectorFromFile(INSTANCE_PATH, sort1, size2-1, type);
        sortVectorFromFile(INSTANCE_PATH, sort1, size3-1, type);
        statisticalFormatter.format("%s", "\n-----------------------------------------\n");

        sortVectorFromFile(INSTANCE_PATH, sort2, size1-1, type);
        ortVectorFromFile(INSTANCE_PATH, sort2, size2-1, type);
        sortVectorFromFile(INSTANCE_PATH, sort2, size3-1, type);
        statisticalFormatter.format("%s", "\n-----------------------------------------\n");

        sortVectorFromFile(INSTANCE_PATH, sort3, size1-1, type);
        sortVectorFromFile(INSTANCE_PATH, sort3, size2-1, type);
        sortVectorFromFile(INSTANCE_PATH, sort3, size3-1, type);
        
        statisticalFormatter.close();
    }

    /*
	Runs one algorithm at a time accoding to parameter 'type'.

	@param path from file of the vector to be sorted.
	@param sortedLevel is the percentage of the vector already sorted.
	@param size of the vector.
	@param type is the choice of the algorithm.
     */
    public static void sortVectorFromFile(String path, int sortedLevel, int size, int type) {
        int v[] = new int[size];
	    long begin, end;
        long elapsedSeconds; // Elapsed time to sort one vector.
        long averageSeconds = 0; // Average time to sort SAME_SIZE_VECTORS.

        for (int i = 1; i <= SAME_SIZE_VECTORS; i++) {
            // Open input vector file.
            File inFile = new File(path + sortedLevel + "." + (size+1) + "." + i + ".in");
            
            Scanner fileScanner = null;
            try {
                fileScanner = new Scanner(inFile);
            } catch (FileNotFoundException ex) {
                ex.printStackTrace();
            }
            // fileScanner.hasNextInt()
            for (int j = 0; j<size-1; j++) { // Reads vector from current file.
                v[j] = fileScanner.nextInt();
            }

            begin = System.currentTimeMillis();
            switch (type) {

                case 1:
                    SortingAlgorithms.insertionSort(v);
                    break;
                case 2:
                    SortingAlgorithms.selection_sort(v);
                    break;
                case 3:
                        new MergeSort(size).sort(v, 0, size-1);
                    break;
                case 4:
                    SortingAlgorithms.quick_sort_last(v, 0, size-1);
                    break;
                case 5:
                    SortingAlgorithms.heapsort(v, size-1);
                    break;
            }

            end = System.currentTimeMillis();
            elapsedSeconds = (end - begin); // Elapsed time to sort current vector.
            //System.out.println("elapsed time: "+ elapsedSeconds);
/*
            // ------- Writes current sorted vector. --------
            try {
                File sortedFile = new File(SORTED_PATH+ sortedLevel+"."+ (size+1)+"."+i+"."+type+".txt");    
                Formatter sortedFormatter = new Formatter(sortedFile);

                for(int k=0; k<size; k++){
                    sortedFormatter.format("%s\n", String.valueOf(v[k]))  ;
                }
                sortedFormatter.close();
            } catch (FileNotFoundException ex) {
                ex.printStackTrace();
            }
*/   
    
            // Writes statistical data of the current vector.
            statisticalFormatter.format("%s\n", "Algorithm " + type + "; Vector " + i + "; Sorted " + sortedLevel + "%; Size " + (size+1)+
                    "; Elapsed time " + elapsedSeconds + " ms");
            averageSeconds += elapsedSeconds;

            fileScanner.close();
        }

        // Writes average elapsed time to run SAME_SIZE_VECTORS.
        averageSeconds /= SAME_SIZE_VECTORS;
        statisticalFormatter.format("%s\n\n", "Average time: " + averageSeconds + " ms");
    }
}
