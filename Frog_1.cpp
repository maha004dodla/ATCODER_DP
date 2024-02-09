#include<bits/stdc++.h>
using namespace std;
// int spoiler(int ind,vector<int>&arr,int n)//recursion
// {
// 	if(ind==n-1)
// 	{
// 		return 0;
// 	}
// 	int left=abs(arr[ind]-arr[ind+1])+spoiler(ind+1,arr,n);
// 	int right=INT_MAX;
// 	if(ind+2<=n-1)
// 	{
// 		right=abs(arr[ind]-arr[ind+1])+spoiler(ind+2,arr,n);
// 	}
// 	return min(left,right);
// }
int dp[100001];
int spoiler(int ind,vector<int>&arr,int n)
{
	if(ind==n-1)
	{
		return 0;
	}
	if(dp[ind]!=-1)
	{
		return dp[ind];
	}
	int left=abs(arr[ind]-arr[ind+1])+spoiler(ind+1,arr,n);
	int right=INT_MAX;
	if(ind+2<=n-1)
	{
		right=abs(arr[ind]-arr[ind+2])+spoiler(ind+2,arr,n);
	}
	return dp[ind]=min(left,right);
}
int main()
{
	int n,i,a;
	cin>>n;
	vector<int>arr;
	for(i=0; i<n; i++)
	{
		cin>>a;
		arr.push_back(a);
	}
	memset(dp,-1,sizeof(dp));
	int ans=spoiler(0,arr,n);
	cout<<ans<<endl;
}