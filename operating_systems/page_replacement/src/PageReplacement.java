import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Simulates the concept of page replacement for virtual memory in operating
 * systems.
 */
public class PageReplacement {

    public static ArrayList<Integer> inputList;

    public static void main(String[] args) {
        inputList = readFile("input1.txt");
        fifo();
        opt();
        lru();
    }

    /**
     * The most simple algorithm for page replacement. Follows the FIFO concept.
     * When a page must be replaced, the oldest page is selected.
     */
    public static void fifo() {
        int missingPages = 0;
        int numberOfFrames = inputList.get(0);
        ArrayDeque<Integer> frames = new ArrayDeque<>(numberOfFrames);

        for (int i = 1; i < inputList.size(); i++) {
            Integer value = inputList.get(i);
            if (!frames.contains(value)) {
                missingPages++;
                if (frames.size() == numberOfFrames) {
                    frames.removeFirst();
                }
                frames.addLast(value);
            }

            // prints all frames
            /* 
            for (Integer n : frames) {
                System.out.print(n + " ");
            }
            System.out.println();
             */
        }
        System.out.println("FIFO " + missingPages);
    }

    /**
     * The OPT algorithm replaces the page that won't be used for the longest
     * period of time. It ensures the possible lowest error rates of page for a
     * fixed number of frames. Requires advance knowledge of the reference
     * sequence of pages, similar to SJF algorithm for CPU scheduling.
     */
    public static void opt() {
        int missingPages = 0;
        int numberOfFrames = inputList.get(0);
        ArrayList<Integer> frames = new ArrayList<>(numberOfFrames);

        for (int i = 1; i < inputList.size(); i++) {
            Integer value = inputList.get(i);
            if (!frames.contains(value)) {
                missingPages++;
                if (frames.size() == numberOfFrames) { // list of frames is full

                    int iLast = -1; // -1 is an invalid index
                    List<Integer> subList = inputList.subList(i, inputList.size());

                    /**
                     * If page exists in subList, executes the corresponding
                     * conditional statement. Otherwise, replaces the current
                     * page by the new page.
                     */
                    boolean pageExistsInSublist = true;

                    // Finds the page that wont be used for the longest period of time
                    for (int j = 0; j < frames.size(); j++) {

                        Integer frameValue = frames.get(j);

                        if (!subList.contains(frameValue)) { // if this page doens't exist in subList
                            frames.set(j, value); // uses current index(j) to store the current page (inputList[i])
                            pageExistsInSublist = false;
                            break;
                        } else {
                            // finds, in inputList, the index of the first ocurrence of frames[j]
                            int result = subList.indexOf(frameValue);
                            if (result > iLast) {
                                iLast = result;
                            }
                            pageExistsInSublist = true;
                        }
                    }

                    if (iLast >= 0 && pageExistsInSublist) { // at least one valid index was found

                        int subListValue = subList.get(iLast);
                        int iLastFrameToBeUsed = frames.indexOf(subListValue);
                        if (iLastFrameToBeUsed >= 0) {
                            frames.set(iLastFrameToBeUsed, value);
                        }
                    }
                } else {
                    frames.add(value); // add at the end of the list
                }
            }
            // prints all frames
            /*
            for (Integer n : frames) {
                System.out.print(n + " ");
            }
            System.out.println();
             */
        }
        System.out.println("OPT " + missingPages);
    }

    /**
     * The LRU replacement associates each page to the time it was used for the
     * last time. When a page must be replaced, the LRU algorithm selects the
     * page that wasn't used for the longest period of time. LRU is better than
     * FIFO and worse than OPT/MIN (great algorithm). This implementation uses
     * the concept of a counter, that is the clock variable below, and every
     * time a page is referenced its clock is updated.
     */
    public static void lru() {
        int missingPages = 0;
        int numberOfFrames = inputList.get(0);
        ArrayList<Integer> frames = new ArrayList<>(numberOfFrames);
        int[] pagesFrequency = new int[numberOfFrames];
        int clock = 0;

        for (int i = 1; i < inputList.size(); i++) {
            clock++;
            Integer value = inputList.get(i);
            if (!frames.contains(value)) {
                missingPages++;
                if (frames.size() == numberOfFrames) { // list of frames is full

                    /**
                     * Looks for the least frequent page used at pagesFrequency
                     * according to clock;
                     */
                    int lru = pagesFrequency[0];
                    int lruIndex = 0;
                    for (int j = 1; j < pagesFrequency.length; j++) {
                        if (pagesFrequency[j] < lru) {
                            lru = pagesFrequency[j];
                            lruIndex = j;
                        }
                    }
                    frames.set(lruIndex, value); // sets the new page at the index of the lru page
                    pagesFrequency[lruIndex] = clock; // sets the first clock of the new page

                } else {
                    frames.add(value); // add at the end of the list
                    pagesFrequency[frames.size() - 1] = clock; // sets the first clock for the new page
                }
            } else {
                pagesFrequency[frames.indexOf(value)] = clock; // updates pagesFrenquency according to clock
            }
            // prints all frames
            /*
            for (Integer n : frames) {
                System.out.print(n + " ");
            }
            System.out.println();
             */
        }
        System.out.println("LRU " + missingPages);
    }

    /**
     * Reads the input file and stores its data to a list
     *
     * @param fileName the name of the file with its extension, i.e, "text.txt"
     * @return list of input data read from file
     */
    private static ArrayList<Integer> readFile(String fileName) {
        ArrayList<Integer> list = new ArrayList<>();
        Scanner scanner = null;

        try {
            scanner = new Scanner(new File(fileName));

        } catch (FileNotFoundException ex) {
            ex.printStackTrace();
        }

        while (scanner.hasNext()) {
            list.add(scanner.nextInt());
        }
        scanner.close();
        return list;
    }
}
