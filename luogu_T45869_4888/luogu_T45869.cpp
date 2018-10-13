#include<bits/stdc++.h>
#define maxlong 0x3f3f3f
using namespace std;
int l,q,ans,i,j,k,ansx,ansy,xbj,ybj,x,y;
bool xd,yd;
char biao[2005][2005];
char dbiao;
int main()
{
	cin>>l>>q;
	for (i=1;i<=l;i++)
	{
		for (j=1;j<=l;j++)
		{
			
			cin>>biao[i][j]; 
		}
	}
	if (l==1)
	{
	
		for (i=1;i<=q;i++) 
		{
			cin>>x>>y;
			cout<<"1"<<endl;
		}
		return 0;
	}
	for (i=1;i<=q;i++)
	{
		cin>>x>>y;
		ans=1;
		ansx=1;
		ansy=1;
		xd=true;
		yd=true;
		xbj=1;
		ybj=1;
		if (x-1==0||x+1==l+1) xd=false;
		if (y-1==0||y+1==l+1) yd=false;
		while (xd)
		{
			if (biao[x-xbj][y]==biao[x+xbj][y]) 
			{
				ansx+=2;
				xbj++;
				if (x-xbj==0||x+xbj==l+1) xd=false;
			}
			else xd=false;
		}
		while (yd)
		{
			if (biao[x][y-ybj]==biao[x][y+ybj])
			{
				ansy+=2;
				ybj++;
				if (y-ybj==0||y+ybj==l+1) yd=false;
			}
			else yd=false;
		}
		ans=max(ansx,ansy);
		cout<<ans<<endl;
	}
	return 0;
}
