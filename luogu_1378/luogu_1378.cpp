#include<bits/stdc++.h>
using namespace std;
double allsquare;
double beginx,beginy,endx,endy,ans;
bool bj[10];
int n,i,j,k;
const double pi=3.1415926535;
struct oils
{
	double x,y;
	double r;
	
} oil[10];
void rget(int i)
	{
		oil[i].r=min(min(abs(oil[i].x-beginx),abs(oil[i].x-endx)),min(abs(oil[i].y-beginy),abs(oil[i].y-endy)));
		for (int j=1;j<=n;j++)
		{
			if (i!=j&&bj[j]==1)
			{
				oil[i].r=min(oil[i].r,max(0.0,sqrt(pow(oil[i].x-oil[j].x,2)+pow(oil[i].y-oil[j].y,2))-oil[j].r));
			}
		}
	}
void dfs(int now,double ansx)
{
	if (now>n)
	{
		ans=max(ans,ansx);
		return ;
	}
	for (int i=1;i<=n;i++)
	{
		if (bj[i]==0)
		{
			bj[i]=1;
			rget(i);
			dfs(now+1,ansx+pow(oil[i].r,2)*pi);
			bj[i]=0;
		}
	}
}
int main()
{
	cin>>n;
	cin>>beginx>>beginy>>endx>>endy;
	for (i=1;i<=n;i++)
	{
		cin>>oil[i].x>>oil[i].y;
	}
	allsquare=abs(beginx-endx)*abs(beginy-endy);
	dfs(1,0);
	cout<<int(allsquare-ans+0.5)<<endl;
	return 0;
}
