#include<bits/stdc++.h>
#define regl register long long
#define ll long long
#define maxn 100000
using namespace std;
ll a[maxn+5];
class Tree
{
    private:
        ll tree[maxn<<2],lazytag[maxn<<2]={0};
        ll n;
        inline ll ls(ll x)
        {
            return x<<1;
        }
        inline ll rs(ll x)
        {
            return (x<<1)|1;
        }
        inline void push_up(ll x)
        {
            tree[x]=tree[ls(x)]+tree[rs(x)];
            return ;
        }
        inline void tagpush(ll l,ll r,ll treep,ll sum)
        {
            lazytag[treep]+=sum;
            tree[treep]+=sum*(r-l+1);
            return ;
        }
        inline void push_down(ll treep,ll l,ll r)
        {
            ll mid=(l+r)>>1;
            tagpush(l,mid,ls(treep),lazytag[treep]);
            tagpush(mid+1,r,rs(treep),lazytag[treep]);
            lazytag[treep]=0;
            return ;
        }
        void build(ll treep,ll l,ll r)
        {
            lazytag[treep]=0;
			if (l==r)
            {
                tree[treep]=a[l];
                return ;
            }
            
            ll mid=(l+r)>>1;
            build(ls(treep),l,mid);
            build(rs(treep),mid+1,r);
            push_up(treep);
            return ;
        }
        void update(ll mul,ll mur,ll l,ll r,ll tp,ll sum)
        {
            if (mul<=l&&r<=mur)//����
            {
            //    tagpush(l,r,tp,sum);
                tree[tp]+=sum*(r-l+1);
                lazytag[tp]+=sum;
				return ;
            } 
            push_down(tp,l,r);
            ll mid=(l+r)>>1;
            if (mul<=mid) update(mul,mur,l,mid,ls(tp),sum);
            if (mur>=mid+1) update(mul,mur,mid+1,r,rs(tp),sum);
            push_up(tp);
            return ;
        }
        ll getnum(ll mul,ll mur,ll l,ll r,ll tp)
        {
            if (mul<=l&&r<=mur) return tree[tp];
            ll ans=0;
            ll mid=(l+r)>>1;
            push_down(tp,l,r);
          //  cout<<tp<<" "<<mid<<" "<<mul<<" "<<mur<<" "<<l<<" "<<r<<endl;
            if (mul<=mid) ans+=getnum(mul,mur,l,mid,ls(tp));
            if (mur>=mid+1) ans+=getnum(mul,mur,mid+1,r,rs(tp));
            return ans;
        }
    public:
        inline void maketree(ll a[],ll x)
        {
            n=x;
            build(1,1,n);
            return ;
        }
        inline ll find(ll l,ll r)
        {
            return getnum(l,r,1,n,1);
        }
        inline void insert(ll l,ll r,ll sum)
        {
            update(l,r,1,n,1,sum);
            return ;
        }
};
int n,m,did;
ll l,r,sum;

Tree tree;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (regl i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    tree.maketree(a,n);
    for (regl i=1;i<=m;i++)
    {
        cin>>did;
        switch(did)
        {
            case 1:
                cin>>l>>r>>sum;
                tree.insert(l,r,sum);
                break;
            case 2:
                cin>>l>>r;
                cout<<tree.find(l,r)<<endl;
                break;
        }
    }
    return 0;
}
