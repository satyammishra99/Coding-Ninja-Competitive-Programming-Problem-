/*


Problem statement
Given the 'start' and the 'end'' positions of the array 'input'. Your task is to sort the elements between 'start' and 'end' using quick sort.



Note :
Make changes in the input array itself.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 2 3 5 7
Sample Output 2 :
1 2 3 5 7 
Constraints :
1 <= N <= 10^3
0 <= input[i] <= 10^9



*/

int partition(int*input,int si,int ei){
    int pivot=input[si];
    int countsmaller=0;
    for(int i=si+1;i<=ei;i++){
        if(input[i]<=pivot){
            countsmaller++;
        }
   }
    int pivotIndex=si+countsmaller;
    input[si]=input[pivotIndex];
    input[pivotIndex]=pivot;
    int i=si,j=ei;
     while(i<pivotIndex&&j>pivotIndex){
         if(input[i]<=pivot){
             i++;
         }
         else if(input[j]>pivot){
             j--;
         }
         else{
             int temp=input[i];
             input[i]=input[j];
             input[j]=temp;
             i++;
             j--;
         }
     }
   /* while(i<pivotIndex &&j>pivotIndex){
        while(input[i]<=pivot){
            i++;
        }
        while(input[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            int temp=input[i];
            input[i]=input[j];
            input[j]=temp;
            i++;
            j--;
        }
    }*/
    return pivotIndex;
}
void quick_sort(int*input,int si,int ei){
    if(si>=ei){
        return;
    }
    int pi=partition(input,si,ei);
    quick_sort(input,si,pi-1);
    quick_sort(input,pi+1,ei);;

}
void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    return quick_sort(input,0,size-1);

}
