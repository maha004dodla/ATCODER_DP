#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int spoiler(int ind,vector<int>&arr,int n,int k)
{
	if(ind>=n-1)
	{
		return 0;
	}
	if(dp[ind]!=-1)
	{
		return dp[ind];
	}
	int ans=INT_MAX;
	for(int i=1; i<=k; i++)
	{
		if(ind+i<=n-1)
		{
			ans=min(ans,abs(arr[ind]-arr[ind+i])+spoiler(ind+i,arr,n,k));
		}
	}
	return dp[ind]=ans;
}
int main()
{
	int n,k,a,i;
	cin>>n>>k;
	vector<int>arr;
	for(i=0; i<n; i++)
	{
		cin>>a;
		arr.push_back(a);
	}
	memset(dp,-1,sizeof(dp));
	cout<<spoiler(0,arr,n,k);
}