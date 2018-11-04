#include<bits/stdc++.h>
#define regi register int
#define usl unsigned long long
#define mo (unsigned long long)10e9+7
using namespace std;
int n,r,m,a,b,now;
vector<int> tu[10002];
bool dfsbj[10002]={false};
bool bj[10002]={false};
int sonsize[10002];
inline void tlink(int x,int y)
{
	tu[x].push_back(y);
	tu[y].push_back(x);
	return ;
}
usl sondfs(int x)
{
	if (bj[x]==true) return -1;
	bj[x]=true;
//	if (dfsbj[x]==true) return sonsize[x];
//	dfsbj[x]=true;
	int l=tu[x].size();
	for (regi i=0;i<=l-1;i++)
	{
		sonsize[x]+=sondfs(tu[x][i])+1;
	}
	bj[x]=false;
	return sonsize[x];
}
usl ans(usl total,int now)
{
	usl anss=0;
	int l=tu[now].size()-1;
	for (regi i=0;i<=l;i++)
	{
		anss+=(sonsize[tu[now][i]]+1)*(total-sonsize[tu[now][i]]-1);
	}
	ans/=2;
	ans+=total;
	return anss;
}
int main()
{
	cin>>n>>r>>m;
	for (regi i=1;i<=n-1;i++)
	{
		cin>>a>>b;
		tlink(a,b);
	}
	for (regi i=1;i<=m;i++)
	{
		cin>>now;
		int t1;
		t1=ans(sondfs(now),now)%((unsigned long long)10e9+7);
		cout<<t1 <<endl;
	}
	return 0;
}
