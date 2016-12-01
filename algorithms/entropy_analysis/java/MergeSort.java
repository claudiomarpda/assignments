public class MergeSort {

	private int[] helper;// = new int[v.length]; 

	public MergeSort(int size){
		helper = new int[size];
	}
	public void sort(int v[], int start, int end){
		if(start < end){
			int middle = start + ((end-start) / 2);
			sort(v, start, middle); // divide
			sort(v, middle+1, end); // divide
			merge(v, start, middle, end); // conquer and combine
		}
	}

	private void merge(int v[], int start, int middle, int end){
		int i = start, j = middle+1, k = start; 
		//int[] helper = new int[v.length]; 

		for(int c=start; c<=end; c++){
			helper[c] = v[c];
		}

		// Copies the minor values of both partitions to the original vector
		while(i<=middle && j<=end){ 
			if(helper[i] <= helper[j]){
				v[k] = helper[i];
				i++;
			}
			else{
				v[k] = helper[j];
				j++;
			}
			k++;
		}

		// Copies the rest of the left partition
		while(i <= middle){
			v[k] = helper[i];
			i++;
			k++;
		}

		// Copies the rest of the right partition
		while(j <= end){
			v[k] = helper[j];
			j++;
			k++;
		}
	}
}