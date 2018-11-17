#include<bits/stdc++.h>
#include<climits>
#define regi register int
#define ll long long
using namespace std;
priority_queue<int,vector<int>,greater<int> > tu[5002];
int n,m,u,v;
//int minn[5002];
int last[5002];
int xulie[5002];
void get(int xulien,int cityn,bool ne,int xulie[])
{
	int minn;
	if (xulien==n&&xulie[n]!=INT_MAX)
	{
		for (regi i=1;i<=n;i++)
		{
			cout<<xulie[i]<<" ";
		}
		exit(0);
	}
	if (tu[cityn].empty())
	{
		if (last[cityn]!=-1) get(xulien,last[cityn],false,xulie);
		return ;
	}
		minn=tu[cityn].top();
	bool lastisminn=false;
	if (ne)
	{
		if (xulie[xulien]<cityn) return ;
		if (xulie[xulien]>cityn)
		{
			for (regi i=xulien+1;i<=n;i++) xulie[i]=INT_MAX;
		}
		xulie[xulien]=cityn;
		
	}
	
		if (minn==last[cityn])
		{
			lastisminn=true;
			tu[cityn].pop();
			if (!tu[cityn].empty())
				minn=tu[cityn].top();
		}
	
	if (!tu[cityn].empty()) tu[cityn].pop();
//	xulien++;
	if (minn==last[cityn]) 
		{
			get(xulien,minn,false,xulie) ;
		}
		else
		{
		  if (last[minn]==-1)
		  {
		  	last[minn]=cityn;
		get(xulien+1,minn,true,xulie);
		last[minn]=-1;
		  }
		if (last[cityn]!=-1) get(xulien,last[cityn],false,xulie);
		
		}
	if (minn!=last[cityn]&&lastisminn==true) tu[cityn].push(last[cityn]);
	tu[cityn].push(minn);
	return ;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (regi i=2;i<=n;i++) xulie[i]=INT_MAX;
	for (regi i=1;i<=m;i++)
	{
		cin>>u>>v;
		last[u]=-1;
		last[v]=-1;
		tu[u].push(v);
		tu[v].push(u);
	}
	xulie[1]=1;
	get(1,1,true,xulie);
	
	cout<<endl;
	return 0;
}
