#include<bits/stdc++.h>
#include<cctype>
#include<queue>
#include<climits>
#define ll long long
#define regi register int
#define maxn (int)10e7
using namespace std;
ll maxlevel,mp,minlevel=INT_MAX;
int n,aii;
priority_queue<int,vector<int>,greater<int> > obj[maxn];
inline void levelup(int x)
{
	int now1=obj[x].top();
	obj[x].pop();
	int now2=obj[x].top();
	obj[x].pop();
	x++;
	maxlevel=max(maxlevel,(ll)x);
	mp+=now1+now2;
	obj[x].push(2*max(now1,now2));
	return ;
} 
inline void read(int &x)
{
     char ch;x=0;
     while(!isdigit(ch))   ch=getchar();
     while(isdigit(ch))   x=x*10+ch-'0',ch=getchar();
}
void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}

ll inv(ll a, ll p)
{
    ll d, x, y;
    exgcd(a, p, d, x, y);
    return d == 1 ? (x+p)%p : -1;
}
inline void getk()
{
	
	cout<<inv(maxlevel,mp)<<endl;
	return ;
}
int main()
{
	read(n);
	for (regi i=1;i<=n;i++)
	{
		read(aii);
		maxlevel=max(maxlevel,(ll)aii);
		minlevel=min(minlevel,(ll)aii);
		obj[aii].push(1);
	}
	int i=minlevel;
	while (i<=maxlevel)
	{
		while (i<=maxlevel&&obj[i].size()/2==0) i++;
		if (i<=maxlevel&&obj[i].size()/2) mp=0;
		while (i<=maxlevel&&obj[i].size()/2)
		{
			levelup(i);
			i++;
		}
	}
	getk();
	return 0;
}
