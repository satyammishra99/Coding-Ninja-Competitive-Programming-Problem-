/*
Problem statement
You are given the starting 'l' and the ending 'r' positions of the array 'ARR'.



You must sort the elements between 'l' and 'r'.



Note:
Change in the input array itself. So no need to return or print anything.
Example:
Input: ‘N’ = 7,
'ARR' = [2, 13, 4, 1, 3, 6, 28]

Output: [1 2 3 4 6 13 28]

Explanation: After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
7
2 13 4 1 3 6 28
Sample Output 1:
1 2 3 4 6 13 28
Explanation of Sample Output 1:
After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].
Sample Input 2:
5
9 3 6 2 0
Sample Output 2:
0 2 3 6 9
Explanation of Sample Output 2:
After applying 'merge sort' on the input array, the output is [0 2 3 6 9].
Constraints :
1 <= N <= 10^3
0 <= ARR[i] <= 10^9
*/

void merge(int* input,int s,int e)
{
    int mid=(s+e)/2;
    int* temp = new int(e-s+1);

    int i=s;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=e)
    {
        if(input[i]<input[j])
        {
            temp[k]=input[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=input[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        temp[k++]=input[i++];
    }
    while(j<=e)
    {
        temp[k++]=input[j++];
    }

    for(int i=s,k=0;i<=e;i++,k++)
    {
        input[i]=temp[k];
    }

    return;
}


void merge_sort(int* input,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid=(s+e)/2;
    merge_sort(input,s,mid);
    merge_sort(input,mid+1,e);
    merge(input,s,e);
    return;
}




void mergeSort(int input[], int size)
{
    return merge_sort(input,0,size-1);
}
