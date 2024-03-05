/*
Problem statement
Shreya loves to eat momos. Her mother gives her money to buy vegetables but she manages to save some money out of it daily. After buying vegetables, she goes to "Momos Market", where there are ‘n’ number of shops of momos. Each of the shops of momos has a rate per momo. She visits the market and starts buying momos (one from each shop) starting from the first shop. She will visit the market for ‘q’ days. You have to tell that how many momos she can buy each day if she starts buying from the first shop daily. She cannot use the remaining money of one day on some other day. But she will save them for other expenses in the future, so, you also need to tell the sum of money left with her at the end of each day.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= n <= 10^5
1 <= q <= 10^5
1 <= X <= 10^9
Output:
There will be ‘q’ lines of output each having two space separated integers denoting number of momos she can buy and amount of money she saved each day.
Sample Input:
4
2 1 6 3
1
11
Sample Output:
3 2
Explanation:
Shreya visits the "Momos Market" for only one day. She has 11 INR to spend. She can buy 3 momos, each from the first 3 shops. She would 9 INR (2 + 1 + 6) for the same and hence, she will save 2 INR.
*/


#include<iostream>
using namespace std;
typedef long long int ll;
bool check(ll *arr, ll n, ll mid, ll target)
{
	if(arr[mid]<=target)
	{
		return true;
	}
	return false;
}
void momos(ll *arr, ll n, ll target){
	int s=0,e=n-1,a;
	ll mid;
	while(s<=e){
		mid = (s+e)/2;
		if(check(arr ,n,mid,target)){
			a=mid;
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}
	if(e==-1){
		cout<<"0"<<" "<<target<<endl;
	}
	else
		cout<<a+1<<" "<<target-arr[a]<<endl;
}

int main(){
	ll n;
	cin>>n;
	ll *prices=new ll [n];
	for(ll i=0; i<n; i++)
	{
		cin>>prices[i];
	}
	ll q;//number of days.
	cin>>q;
	ll *money=new ll [q];
	for(ll i=0; i<q; i++)
	{
		cin>>money[i];
	}
	ll *prefix_sum_prices=new ll [n];
	ll sum=0;
	for(ll i=0; i<n; i++)
	{
		sum+=prices[i];
		prefix_sum_prices[i]=sum;
	}
	for(ll i=0; i<q; i++)
	{
		momos(prefix_sum_prices, n, money[i]);
	}
}