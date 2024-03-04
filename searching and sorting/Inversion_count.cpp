/*
Problem statement
For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.

An inversion is defined for a pair of integers in the array/list when the following two conditions are met.

A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 10^5 
1 <= ARR[i] <= 10^9

Where 'ARR[i]' denotes the array element at 'ith' index.

Time Limit: 1 sec
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation of Sample Output 1:
We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4
Explanation of Sample Output 1:
We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).
*/

#include <bits/stdc++.h> 
long long merge(long long *arr,int l,int mid,long long r){
	int i = l,j=mid,k=0;
	long long count=0;
	long long temp[r-l+1];
	while(i<mid && j<=r){
		if(arr[i]<=arr[j]){
			temp[k++]=arr[i++];
		}else{
			temp[k++]=arr[j++];
			count+=mid-i;
			
		}
	}
	while(i<mid){
			temp[k++]=arr[i++];
	}
	while(j<=r){
		temp[k++]=arr[j++];
	}
	for(long long i=l,k=0;i<=r;i++,k++){
		arr[i]=temp[k];
	}
	return count;

}

 long long int merge_sort(long long *arr ,int  left,int right){
	long long count=0;
	if(right>left){
		int mid = (left +right)/2;
		long long lsum = merge_sort(arr,left,mid);
		long long rsum = merge_sort(arr,mid+1,right);
		long long mysum = merge(arr,left,mid+1,right);
		return lsum+rsum+mysum;
	}
	return count;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    long long ans= merge_sort(arr,0,n-1);
    return ans;
}
