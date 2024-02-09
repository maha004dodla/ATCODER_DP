#include<bits/stdc++.h>
using namespace std;
long long dp[10000001];
long long spoiler(long long n,long long val,vector<long long>&arr)
{
	if(val==0)
	{
		return 0;
	}
	if(dp[val]!=-1)
	{
		return dp[val];
	}
	long long ans=INT_MAX;
	for(int i=0; i<n; i++)
	{
		if(arr[i]<=val)
		{
			ans=min(ans,1+spoiler(n,val-arr[i],arr));
		}
	}
	return dp[val]=ans;
}
int main()
{
	long long n,i,a,val;
	cin>>n>>val;
	vector<long long>arr;
	for(i=0; i<n; i++)
	{
		cin>>a;
		arr.push_back(a);
	}
	memset(dp,-1,sizeof(dp));
	int res=spoiler(n,val,arr);
	if(res==INT_MAX)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<res<<endl;
	}
}