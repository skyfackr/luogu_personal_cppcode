#include<bits/stdc++.h>
using namespace std;
vector<int> edge[10005];
int n,m,i,j,k,ans,a,b;
int bj[10005]={0};
int colour1,colour2;
bool bb;
void get(int x,int y)
{
	edge[x].push_back(y);
	edge[y].push_back(x);
/*	int testc=edge[x].size();
	int testd=edge[y].size();
	int teste=edge[x][testc-1];
	int testf=edge[y][testd-1];*/
	return; 
}
bool dfs(int now,int colour)
{
	if (bj[now]!=0)
	{
		if (bj[now]==colour)  return true;
		else return false;
	}
	bj[now]=colour;
	int nextc;
	switch(colour)
	{
		case 1:
			colour1++;
			nextc=2;
			break;
		case 2:
			colour2++;
			nextc=1;
			break;
	}
	bool ret=true;
//	colour==1?nextc=2:nextc=1;
	for (int i=1;i<=edge[now].size();i++)
	{
/*		int testa=edge[now].size();
		int testb=edge[now][i];*/
		ret=ret&&dfs(edge[now][i-1],nextc);
	}
	return ret;
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>a>>b;
		get(a,b);
	}
	for (i=1;i<=n;i++)
	{
		if (bj[i]!=0) continue;
		colour1=0;
		colour2=0;
		bb=dfs(i,1);
		if (bb==false) 
		{
			cout<<"Impossible"<<endl;
			return 0;
		}
		ans+=min(colour1,colour2);
	}
	cout<<ans<<endl;
	return 0;
} 
