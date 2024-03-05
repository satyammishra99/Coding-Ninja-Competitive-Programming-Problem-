/*
Problem statement
Taj Mahal is one of the seven wonders of the world. Aahad loves to travel places and wants to visit Taj Mahal. He visited Agra to view Taj Mahal. There is a ticketing system at Taj Mahal. There are total ‘n’ windows which provide the tickets to get entry into Taj Mahal. There are ‘Ai’ people already present at each window to get the tickets. Each window gives ticket to one person in one minute. Initially, Aahad stands in front of the first window. After each minute, if he didn’t get the ticket, he moves on to the next window to get the ticket. If he is at window 1, he will move to 2. If at 2nd, he will move to 3rd. If he is at last window, he will move to 1st again and so on. Find the window number at which he will get the ticket.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= n <= 10^5
1 <= Ai <= 10^9
Sample Input:
4
2 3 2 0
Sample Output:
3
Explanation:
Aahad at Window 1: [2, 3, 2, 0]
Aahad at Window 2: [1, 2, 1, 0]
Aahad at Window 3: [0, 1, 0, 0]
So, when Aahad is at window 3, he got zero people before him. Hence, he will get the ticket at window 3.

*/

#include<bits/stdc++.h>
using namespace std;
typedef  long long int ll;
ll ans=-1;
bool check(ll arr[] , ll mid, ll n){
	for(ll i=0;i<n;i++){
		if(i+(mid*n)>=arr[i]){
			ans =i+1;
			return true;
		}
	}
	return false;
}

ll solve(ll arr[],ll n){
	ll s=0,e=1000000000;
	while(s<=e){
		ll mid = (s+e)/2;
		if(check(arr,mid,n)){
			e=mid-1;
		}
		else s =mid+1;
	}
	return ans;
}
int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	// ll a = solve(arr,n);  // this is one solution 
	// cout<<a;
 // 2nd approach solution

	ll t[n];
	for(ll i=0;i<n;i++){
		if((arr[i]-i)%n == 0){
			t[i]=(arr[i]-i)/n;
		}
		else if (arr[i]-i<0){
			t[i]=0;
		}
		else{
			t[i]=(arr[i]-i)/n +1;
		}
	}
	ll min_value=INT_MAX;
	ll index=-1;
	for(ll i=0;i<n;i++){
		if(t[i]<min_value){
			min_value=t[i];
			index=i+1;
		}
	}
	cout<<index;
	
	
    
	return 0;
}
