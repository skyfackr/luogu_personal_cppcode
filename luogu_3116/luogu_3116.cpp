#include<bits/stdc++.h>

using namespace std;
int l[105][105],lb[105][105],le[105][105];
int lib[495005],lie[495005];
int i,k,a,b,c,d,n,m;
void findb(int x,int ansn)
{
	int j;
	if (x==n) lib[ansn]=1;
	else
	{
	
	for (j=x+1;j<=n;j++)
		if (lb[x][j]>0) findb(j,ansn+lb[x][j]);
	}
}
void finde(int x,int ansn)
{
	int j;
	if (x==n) lie[ansn]=1;
	else
	{
	
	for (j=1;j<=n;j++)
		if (le[x][j]>0) finde(j,ansn+le[x][j]);
	}
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>a>>b>>c>>d;
		lb[a][b]=c;
		le[a][b]=d;
	}
	findb(1,0);
	finde(1,0);
	k=0;
	for (i=1;i<=495005;i++)
	{
		if (lib[i]==1&&lie[i]==1) 
		{
			k=1;
			cout<<i;
			break;
		}
	}
	if (!k) cout<<"IMPOSSIBLE";
	return 0;
}
