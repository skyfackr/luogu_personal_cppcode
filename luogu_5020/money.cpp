#include<bits/stdc++.h>
#define regi register int
#define ll long long
#define maxn 105
//#define int long long
using namespace std;
ll t,n,m,mm;
ll a[maxn];
bool chobj[2500005];
ll cho[maxn];
ll maxmon,minmon;
bool vis[maxn];
void dt(ll now,ll num)
{
	
//	if (chobj[cho[now]]==false) return ;
	num+=cho[now];
	if (num>maxmon) return ;
	if (chobj[num]==true)
	{
		chobj[num]=false;
		m--;
		
	}
	for (regi i=now;i<=mm;i++) dt(i,num);
	return ;
}
inline void dts(ll st)
{
	ll num=cho[st];
	for (regi i=st;i<=mm;i++)
	{
		dt(i,num);
	}
	return ;
}
//#undef int
int main()
{
//	freopen("money.in","r",stdin);
//	freopen("money.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while (t--)//¶¾Áö
	{
		cin>>n;
		m=n;
		for (regi i=1;i<=n;i++) cin>>a[i],chobj[a[i]]=false,vis[a[i]]=false;
		sort(a+1,a+n+1);
		minmon=a[1];maxmon=a[n];
		for (regi i=1;i<=n;i++)
		{
//			if (!vis[a[i]])
//			{
//				for (regi j=a[i];j<=maxmon;j+=a[i]) 
//					vis[j]=true;
				chobj[a[i]]=true;
//				m++;
				cho[i]=a[i];
				
//			}
		}
		mm=m;
		for (regi i=1;i<=mm-1;i++) dts(i);
		cout<<m<<endl;
	} 
	return 0;
}
