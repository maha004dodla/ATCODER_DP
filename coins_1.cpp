#include<bits/stdc++.h>
using namespace std;
double dp[3001][3001];
double spoiler(int n,int heads,double arr[])
{
	if(heads==0) return 1.00;
	if(n==0) return 0.00;
	if(dp[n][heads]!=-1.00)
	{
		return dp[n][heads];
	}
	dp[n][heads]=arr[n-1]*spoiler(n-1,heads-1,arr)+(1-arr[n-1])*spoiler(n-1,heads,arr);
	return dp[n][heads];
}
int main()
{
	int n,i,j;
	cin>>n;
	double arr[n];
	for(i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int heads=(n+1)/2;
	for(i=0; i<=n; i++)
	{
		for(j=0; j<=heads; j++)
		{
			dp[i][j]=-1.00;
		}
	}
	double ans=spoiler(n,heads,arr);
	cout<<setprecision(10)<<ans<<endl;
}