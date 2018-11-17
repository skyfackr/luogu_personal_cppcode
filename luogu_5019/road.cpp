#include<bits/stdc++.h>
#include<climits>
#define regi register int
#define ll long long
#define maxn 100000
using namespace std;
int origin[maxn+5],n;
int tree[maxn<<2];
//bool zero[maxn+5];
class Tree//记录最小值,可进行递减操作 
{
	private:
		
		int lazytag[maxn<<2];
		inline ll ls(ll x)
		{
			return x<<1;
		}
		inline ll rs(ll x)
		{
			return x<<1|1;
		}
		inline void tagpush(ll tp,ll sum)//懒标记生成 
		{
			tree[tp]-=sum;
			lazytag[tp]+=sum;
			return ;
		}
		inline void push_down(ll tp)//懒传递 
		{
			int tag=lazytag[tp];
			tagpush(ls(tp),tag);
			tagpush(rs(tp),tag);
			lazytag[tp]=0;
			return ;
		}
		inline void push_up(ll tp)//生成 
		{
			tree[tp]=min(tree[ls(tp)],tree[rs(tp)]);
			return ;
		}
		inline int getmid(int l,int r)//抱歉我懒 
		{
			return (l+r)>>1;
		}
		void build(int l,int r,ll tp)//递归建树 
		{
			if (l==r)
			{
				tree[tp]=origin[l];
//				zero[l]=true;
//				if (origin[l]==0) zero[l]=true;
				return ;
			}
			ll mid=getmid(l,r);
			build(l,mid,ls(tp));
			build(mid+1,r,rs(tp));
			push_up(tp);
			return ;
		}
		inline void update(int mul,int mur,int l,int r,ll tp,int sum)//递归更新,仅支持减法 
		{
			if (mul<=l&&r<=mur)
			{
				tagpush(tp,sum);
				return ;
			}
			ll mid=getmid(l,r);
			push_down(tp);
			if (mul<=mid) update(mul,mur,l,mid,ls(tp),sum);
			if (mur>=mid+1) update(mul,mur,mid+1,r,rs(tp),sum);
			push_up(tp);
			return ;
		}
		inline int minget(int mul,int mur,int l,int r,ll tp)//目标最小值 
		{
			if (mul<=l&&r<=mur)
			{
				return tree[tp];
			}
			ll mid=getmid(l,r);
			push_down(tp);
			int ans=INT_MAX;
			if (mul<=mid) ans=min(minget(mul,mur,l,mid,ls(tp)),ans);
			if (mur>=mid+1) ans=min(minget(mul,mur,mid+1,r,rs(tp)),ans);
			return ans;
		}
	public:
		inline void maketree() 
		{
			build(1,n,1);
			return ;
		}
		inline void fix(int l,int r,int sum)
		{
			update(l,r,1,n,1,sum);
			return ;
		}
		inline int find(int l,int r)
		{
			return minget(l,r,1,n,1);
		}
};
Tree treee;
ll total,ans;
int main()
{
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
//提交时一定要解除文件度入注释!!! 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (regi i=1;i<=n;i++) cin>>origin[i],total+=origin[i];
	treee.maketree();
	int l=1,r=1;
//	zero[n+1]=true;
	while (total)//需要对拍 
	{
		if (!treee.find(l,l)) 
		{ 
		while (!treee.find(l,l)&&l<=n) 
			l++;
		
		
		} 
		r=l+1;
		while (treee.find(r,r)&&r<=n) 
			r++;
		r--;
		ll minn=treee.find(l,r);
		total-=minn*(r-l+1);
		treee.fix(l,r,minn);
		ans+=minn;
		
	}
	cout<<ans<<endl;
	return 0;
}
