#include<bits/stdc++.h>
#include<climits>
#define regi register int
using namespace std;
#define maxn 100005
#define ll long long
vector<int> lu[maxn];
int lunum[maxn],mon[maxn];
string baoli;
bool bj[maxn];
bool def[maxn];
int n,m,a,b,mincity,minlu=INT_MAX,u,v;
bool azt,bzt;
ll ans;
void ado(int a,int b,bool zt)//Êý¾ÝÎª1 zt=true 
{
	if ((a-b)%2==0)
	{
		if (a%2==1)
		{
			int now=1;
			for (regi i=1;i<=n;i+=2)
			{
				ans+=mon[now];
				now=lu[now][0];
				now=lu[now][0];
			}
			cout<<ans<<endl;
			exit(0);
		}
		int now=2;
		for (regi i=2;i<=n;i+=2)
		{
			ans+=mon[now];
			now=lu[now][0];
			now=lu[now][0];
			
		}
		cout<<ans<<endl;
		exit(0);
	}
	
		int now=1;
			for (regi i=1;i<=n;i+=2)
			{
				ans+=mon[now];
				now=lu[now][0];
				now=lu[now][0];
			}
			if (zt)
			{
			
				cout<<ans<<endl;
				exit(0);
			}
			ll ansn;
			now=2;
		for (regi i=2;i<=n;i+=2)
		{
			ansn+=mon[now];
			now=lu[now][0];
			now=lu[now][0];
			
		}
		cout<<min(ansn,ans)<<endl;
		exit(0);
	
	
}
inline void ab2(int a,bool azt,int b,bool bzt)
{
	if (azt==bzt&&azt==0)
	{
		cout<<"-1"<<endl;
		exit(0);
	}
}
inline void getmincity(int x)
{
	if (lunum[x]<minlu)
	{
		minlu=lunum[x];
		mincity=x;
	}
	return ;
}
ll dfs(int now)
{
	ll ans=mon[now];
	if (lu[now].size()==1) return ans;
	bj[now]=true;
	if (now==a||now==b) 
	{
		ll anss=LLONG_MAX;
		for (regi i=1;i<=lu[now].size();i++)
		{
			if (!bj[lu[now][i-1]]) anss=min(anss,dfs(lu[now][i-1]));
		}
		return ans+anss;
	}
	bool zt=false;
	for (regi i=1;i<=lu[now].size();i++)
	{
		if (def[lu[now][i-1]]==true)
		{
			zt=true;
			break;
		}
	}
	def[now]=true;
	ll anss=LLONG_MAX;
	for (regi i=1;i<=lu[now].size();i++)
		{
			if (!bj[lu[now][i-1]]) anss=min(anss,dfs(lu[now][i-1]));
		}
		def[now]=false;
	if (zt)
	{
		for (regi i=1;i<=lu[now].size();i++)
		{
			if (!bj[lu[now][i-1]]) anss=min(anss,dfs(lu[now][i-1]));
		}
	}
	bj[now]=false;
	return ans+anss;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>baoli;
	for (regi i=1;i<=n;i++) cin>>mon[i];
	if (baoli[0]=='B') mincity=1;else
	for (regi i=1;i<=n-1;i++)
	{
		cin>>u>>v;
		lunum[u]++;
		lunum[v]++;
		lu[u].push_back(v);
		lu[v].push_back(u);
	}
	for (regi i=1;i<=n;i++) getmincity(i);
	for (regi i=1;i<=m;i++)
	{
		cin>>a>>azt>>b>>bzt;
		if (baoli[1]=='2') ab2(a,azt,b,bzt);
		if (baoli[0]=='A')
		{
			bool zt=false;
			if (baoli[1]==1) zt=true;
			ado(a,b,zt);
		}
		cout<<dfs(mincity)<<endl;
	}
	return 0;
}
