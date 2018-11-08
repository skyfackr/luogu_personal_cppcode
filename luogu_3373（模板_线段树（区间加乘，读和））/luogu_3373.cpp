#include<bits/stdc++.h>
#define regi register int
#define ll long long
#define maxn 100000
using namespace std;
ll n,m,p;
ll a[maxn+5];
class Tree
{
	ll tree[maxn<<2];
	inline ll getmid(ll x,ll y)
	{
		return (x+y)>>1;
	}
	struct lazytag
	{
		queue<ll> tag;
		queue<bool> zt;//f:¼Ó t:³Ë 
	} tag[maxn<<2];
	inline void tagpush(ll l,ll r,ll tp,ll sum,bool zt)
	{
		if (zt) tree[tp]*=sum; else tree[tp]+=(r-l+1)*sum;
		tag[tp].tag.push(sum);
		tag[tp].zt.push(zt);
		return ; 
	}
	inline ll ls(ll tp)
	{
		return tp<<1;
	}
	inline ll rs(ll tp)
	{
		return (tp<<1)|1;
	}
	inline void push_up(ll tp)
	{
		tree[tp]=tree[ls(tp)]+tree[rs(tp)];
		return ;
	}
	inline void push_down(ll l,ll r,ll tp)
	{
		ll mid=getmid(l,r);
		while (!tag[tp].tag.empty())
		{
			ll nowtag=tag[tp].tag.front();
			tag[tp].tag.pop();
			bool nowzt=tag[tp].zt.front();
			tag[tp].zt.pop();
			tagpush(l,mid,ls(tp),nowtag,nowzt);
			tagpush(mid+1,r,rs(tp),nowtag,nowzt);
		}
		return ;
	}
	void build(ll tp,ll l,ll r)
	{
		if (l==r)
		{
			tree[tp]=a[l];
			return ;
		}
		ll mid=getmid(l,r);
		build(ls(tp),l,mid);
		build(rs(tp),mid+1,r);
		push_up(tp);
	}
	void update(ll mul,ll mur,ll l,ll r,ll tp,ll sum,bool zt)
	{
		if (mul<=l&&r<=mur)
		{
			tagpush(l,r,tp,sum,zt);
			return ;
		}
		push_down(l,r,tp);
		ll mid=getmid(l,r);
		if (mul<=mid) update(mul,mur,l,mid,ls(tp),sum,zt);
		if (mur>=mid+1) update(mul,mur,mid+1,r,rs(tp),sum,zt);
		push_up(tp);
		return ;
	}
	ll getnum(ll mul,ll mur,ll l,ll r,ll tp)
	{
		if (mul<=l&&r<=mur) return tree[tp];
		ll ans=0;
		ll mid=getmid(l,r);
		push_down(l,r,tp);
		if (mul<=mid) ans+=getnum(mul,mur,l,mid,ls(tp));
		ans%=p;
		if (mur>=mid+1) ans+=getnum(mul,mur,mid+1,r,rs(tp));
		ans%=p;
		return ans;
	}
	public:
		inline void maketree()
		{
			build(1,1,n);
			return ;
		}
		inline void insert(ll l,ll r,ll sum,bool zt)
		{
			update(l,r,1,n,1,sum,zt);
			return ;
		}
		inline ll find(ll l,ll r)
		{
			return getnum(l,r,1,n,1);
		}
};
Tree tree;
int did,x,y,z;
int main()
{
	cin>>n>>m>>p;
	for (regi i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	tree.maketree();
	for (regi i=1;i<=m;i++)
	{
		cin>>did;
		switch (did)
		{
			case 1:
				cin>>x>>y>>z;
				tree.insert(x,y,z,true);
				break;
			case 2:
				cin>>x>>y>>z;
				tree.insert(x,y,z,false);
				break;
			case 3:
				cin>>x>>y;
				cout<<tree.find(x,y)<<endl;
				break;
		}
	}
	return 0;
}
