#include<bits/stdc++.h>
using namespace std;
int spoiler(vector<vector<int>>&arr,int n,vector<vector<int>>&dp)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<3; j++)
		{
			dp[i][j]=max(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3])+arr[i-1][j];
		}
	}
	return max({dp[n][0],dp[n][1],dp[n][2]});
}
int main()
{
	int n,i,j;
	cin>>n;
	vector<vector<int>>arr(n,vector<int>(3,0));
	for(i=0; i<n; i++)
	{
		for(j=0; j<3; j++)
		{
			cin>>arr[i][j];
		}
	}
	vector<vector<int>>dp(n+1,vector<int>(3,0));
	cout<<spoiler(arr,n,dp);
}





