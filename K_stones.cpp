#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,i,j;
	cin>>n>>k;
	int arr[n];
	for(i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int dp[k+1];
	for(i=0; i<=k; i++)
	{
		dp[i]=0;
	}
	for(i=0; i<=k; i++)
	{
		for(j=0; j<n; j++)
		{
			if(i<arr[j])
			{
				continue;
			}
			else
			{
				if(dp[abs(i-arr[j])]==0)
				{
					dp[i]=1;
					break;
				}
			}
		}
	}
	if(dp[k]==1)
	{
		cout<<"First"<<endl;
	}
	else
	{
		cout<<"Second"<<endl;
	}
}