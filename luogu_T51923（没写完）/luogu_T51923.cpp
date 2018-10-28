//暂时不想写了以后填坑 
#include<bits/stdc++.h>
#define mod (unsigned int)10e9+7
#define regi register int
using namespace std;
int n,m,k,p,f,nowday;
int llist[305][10],bj[10];//llist:[x][0]存p，后面的依次存吃的 
unsigned long long ans=1;
inline void clearbj()
{
	for (regi i=1;i<=m;i++) bj[i]=0;
	return;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for (regi i=1;i<=k;i++)
	{
		cin>>p;
		llist[i][0]=p;
//		ans*=p*(p+1)/2;
		for (regi j=1;j<=p;j++)
		{
			cin>>f;
			llist[i][j]=f;
		}
	}
	//第一天，吃顿好的
//	unans=1;
	for (regi i=1;i<=llist[1][0];i++)
	{
		bj[llist[1][i]]=1;
	} 
//	nowday=1;
	for (regi i=2;i<=n;i++)
	{
		nowday=(i-1)%k+1;
		int c=0;
		
		for (regi j=1;j<=llist[nowday][0];j++)
		{
			  c+=bj[llist[nowday][j]];
		}
		llist[nowday][0]-=c;
		clearbj();
		for (regi j=1;j<=llist[nowday][0];j++)
		{
			bj[llist[nowday][j]]=1;
		}
	}
	for (regi i=1;i<=n;i++)
	{
		ans*=llist[i][0];
	}
	ans%=mod;
	cout<<ans<<endl;
	return 0;
}
