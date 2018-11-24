#include<bits/stdc++.h>
#define regi register int
#define mo 100000000
#define maxp 13
#define maxn 2001
using namespace std;
int dp[maxp][maxn];
bool able[maxn][maxn]={false};
int dpmap[maxn];
int origin[maxp];
int n,m,dpnum,maxnum;
inline bool isablex(int a)
{
	if ((a&(a>>1))==0) return true;
	return false;
}
inline void getorigin(int i)
{
	origin[i]=0;
	int x;
	for (regi j=1;j<=n;j++)
	{
		cin>>x;
		origin[i]<<=1;
		origin[i]+=x;
	}
//	maxnum=max(maxnum,origin[i]);
	return ;
}
inline void isabley()
{
	for (regi i=1;i<=dpnum;i++)
	{
		for (regi j=i;j<=dpnum;j++)
		{
			if ((dpmap[i]&dpmap[j])==0) able[i][j]=true,able[j][i]=true;
		}
	}
	return ;
}
inline bool mapable(int a,int b)
{
	return ((a|b)==b);
}
int main()
{
	cin>>m>>n;
	for (regi i=1;i<=m;i++)
	{
		getorigin(i);
	}
	dpnum=0;
	for (regi i=1;i<=(1<<n)-1;i++)
	{
		if (isablex(i))
		{
			dpnum++;
			dpmap[dpnum]=i;
		}
	}
	isabley();
	dp[0][1]=1;
	for (regi i=1;i<=m;i++)
	{
		for (regi j=1;j<=dpnum;j++)
		{
			if (!mapable(dpmap[j],origin[i]))
				dp[i][j]=-1;
			else
			{
				for (regi k=1;k<=dpnum;k++)
				{
					if (dp[i-1][k]!=-1&&able[j][k]) dp[i][j]=(dp[i][j]+dp[i-1][k])%mo;
				}
			}
		}
	}
	int ans=0;
	for (regi i=1;i<=dpnum;i++)
		if (dp[m][i]!=-1) ans=(ans+dp[m][i])%mo;
	cout<<ans<<endl;
	return 0;
}
