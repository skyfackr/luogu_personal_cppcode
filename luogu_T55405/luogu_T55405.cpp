#include<bits/stdc++.h>
#include<climits>
using namespace std;
bool tu[1001][1001]={false};
int n,m;
char ch;
struct Dian
{
	int x,y;
};
int maxx=-1,minn=INT_MAX;
void fuck(Dian now,int guaied,int lastfangxiang)//1:you,0:xia
{
	if (now.x>m||now.y>n||tu[now.x][now.y]==true) return ;
	if (now.x==m&&now.y==n)
	{
		maxx=max(maxx,guaied);
		minn=min(minn,guaied);
		return ;
	}
	switch (lastfangxiang)
	{
		case 0:
			now.x++;
			fuck(now,guaied,0);
			now.x--;
			now.y++;
			fuck(now,guaied+1,1);
			break;
		case 1:
			now.y++;
			fuck(now,guaied,1);
			now.y--;
			now.x++;
			fuck(now,guaied+1,0);
			break;
	}
	return ;
}
int main()
{
	cin>>m>>n;
	for (register int i=1;i<=m;i++)
	{
		for (register int j=1;j<=n;j++)
		{
			cin>>ch;
			if (ch=='#') tu[i][j]=true;
		}
	}
	if (m==1&&n==1) 
	{
		cout<<"0 0\n";
		return 0;
	}
	Dian first;
	if (m!=1)
	{
		first.x=2;
		first.y=1;
		fuck(first,0,0);
	}
	if (n!=1)
	{
		first.x=1;
		first.y=2;
		fuck(first,0,1);
	}
	if (maxx==-1)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<maxx<<" "<<minn<<endl;
	return 0;
}
