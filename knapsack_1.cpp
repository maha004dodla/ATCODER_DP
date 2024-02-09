#include<bits/stdc++.h>
using namespace std;
long long int spoiler(long long int ind,vector<pair<long long int,long long int>>&arr,long long int n,long long int w,vector<vector<long long int>>&dp)
{
	if(ind>=n or w==0)
	{
		return 0;
	}
	if(dp[ind][w]!=-1)
	{
		return dp[ind][w];
	}
	long long int pick=0,non_pick=0;
	if(arr[ind].first<=w)
	{
		pick=arr[ind].second+spoiler(ind+1,arr,n,w-arr[ind].first,dp);
		non_pick=spoiler(ind+1,arr,n,w,dp);
		return dp[ind][w]=max(pick,non_pick);
	}
	return dp[ind][w]=spoiler(ind+1,arr,n,w,dp);     
}
int main()
{
	long long int n,w,a,b,i;
	cin>>n>>w;
	vector<pair<long long int,long long int>>arr;
	for(i=0; i<n; i++)
	{
		cin>>a>>b;
		arr.push_back({a,b});
	}
	vector<vector<long long int>>dp(n+1,vector<long long int>(w+1,-1));
	cout<<spoiler(0,arr,n,w,dp)<<endl;
}











