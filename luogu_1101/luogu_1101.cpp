#include<bits/stdc++.h>
using namespace std;
const char zd[7]={'y','i','z','h','o','n','g'};
struct yget
{
	int x,y;
} y[100005];
int ans[105][105];
int i,j,k,n,ynum,yx,yy;
char zm[105][105];
bool search(int x,int y,int i,int fx)
{
	bool t=false;
	if (i==6&&zm[x][y]=='g')
	{
		ans[x][y]=1;
		return true;
	}
	if (zm[x][y]==zd[i])
	{
	
	i++;
	switch (fx)
	{
	case 0:
	if (search(x-1,y-1,i,1)) t=true;
	if (search(x-1,y+1,i,2)) t=true;
	if (search(x-1,y,i,3)) t=true;
	if (search(x+1,y-1,i,4)) t=true;
	if (search(x+1,y+1,i,5)) t=true;
	if (search(x+1,y,i,6)) t=true;
	if (search(x,y-1,i,7)) t=true;
	if (search(x,y+1,i,8)) t=true;
	break;
	case 1:
		if (search(x-1,y-1,i,1)) t=true;
		break;
	case 2:
		if (search(x-1,y+1,i,2)) t=true;
		break;
	case 3:
		if (search(x-1,y,i,3)) t=true;
		break;
	case 4:
		if (search(x+1,y-1,i,4)) t=true;
		break;
	case 5:
		if (search(x+1,y+1,i,5)) t=true;
		break;
	case 6:
		if (search(x+1,y,i,6)) t=true;
		break;
	case 7:
		if (search(x,y-1,i,7)) t=true;
		break;
	case 8:
		if (search(x,y+1,i,8)) t=true;
		break;
	}
	}
	
	if (t) 
	{
		ans[x][y]=1;
	}
	return t;
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			cin>>zm[i][j];
			if (zm[i][j]=='y') 
			{
				ynum++;
				y[ynum].x=i;
				y[ynum].y=j;
			}
		}
	}
	for (i=1;i<=ynum;i++)
	{
		yx=y[i].x;
		yy=y[i].y;
		search(yx,yy,0,0);
	} 
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (ans[i][j]==1) cout<<zm[i][j];
			else cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}
