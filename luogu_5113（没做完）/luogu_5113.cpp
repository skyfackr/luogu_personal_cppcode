//Sabbat of the witch
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define regi register int
#define maxn 100001
class SegmentTree
{
    private:
        ll lazytag[maxn<<2];
        ll lazytagtime[maxn<<2];
        ll worknum=0;
        struct Treedata
        {
            private:
                ll treedata=0;
                ll lastnum=0;
                ll worktime=0;
            public:
                inline void back(ll deletetime)
                {
                    if (deletetime==worktime)
                        treedata=lastnum;
                    return;
                }
                inline void give(ll x,ll worknum)
                {
                    lastnum=treedata;
                    treedata=x;
                    worktime=worknum;
                    return ;
                }
                inline ll data()
                {
                    return treedata;
                }
        } tree[maxn<<2];
        inline void addwork()
        {
            worknum++;
            return ;
        }
        inline void workclear()
        {
            worknum=0;
            return ;
        }
        ll n;
        ll *origin;
        inline ll getmid(ll l,ll r)
        {
            return (l+r)>>1;
        }
        inline ll ls(ll x)
        {
            return x<<1;
        }
        inline ll rs(ll x)
        {
            return (x<<1)+1;
        }
        inline void push_up(ll x)
        {
            tree[x].give(tree[ls(x)].data()+tree[rs(x)].data(),worknum);
            return ;
        }
        inline void tagpush(ll l,ll r,ll treep,ll lazy,ll lazytime)
        {
            lazytag[treep]=lazy;
            lazytagtime[treep]=lazytime;
            if (lazy<0) tree[treep].back(-1*lazy);
                else tree[treep].give(lazy*(r-l+1),worknum);
            return ;
        }
        inline void push_down(ll l,ll r,ll treep)
        {
            ll mid=getmid(l,r);
            tagpush(l,mid,ls(treep),lazytag[treep],lazytagtime[treep]);
            tagpush(mid+1,r,rs(treep),lazytag[treep],lazytagtime[treep]);
            lazytag[treep]=0;
            lazytagtime[treep]=0;
            return ;
        }
        void build(ll l,ll r,ll treep)
        {
            lazytag[treep]=0;
            if (l==r)
            {
                tree[treep].give(*(origin+l),worknum);
                return ;
            }
            ll mid=getmid(l,r);
            build(l,mid,ls(treep));
            build(mid+1,r,rs(treep));
            push_up(treep);
            return ;
        }
        void update(ll mul,ll mur,ll l,ll r,ll treep,ll num)
        {
            if (mul<=l&&r<=mur)
            {
                tagpush(l,r,treep,num,worknum);
                return ;
            }
            push_down(l,r,treep);
            ll mid=getmid(l,r);
            if (mul<=mid) update(mul,mur,l,mid,ls(treep),num);
            if (mid+1<=mur) update(mul,mur,mid+1,r,rs(treep),num);
            push_up(treep);
            return ;
        }
        ll solve(ll mul,ll mur,ll l,ll r,ll treep)
        {
            if (mul<=l&&r<=mur) return tree[treep].data();
            ll ans=0,mid=getmid(l,r);
            push_down(l,r,treep);
            if (mul<=mid) ans+=solve(mul,mur,l,mid,ls(treep));
            if (mid+1<=mur) ans+=solve(mul,mur,mid+1,r,rs(treep));
            return ans;
        }
    public:
        inline void maketree(ll a[],ll x)
        {
            workclear();
            n=x;
            origin=a;
            build(1,1,n);
            return ;
        }
        inline ll find(ll l,ll r)
        {
            return solve(l,r,1,n,1);
        }
        inline void change(ll l,ll r,ll num)
        {
            addwork();
            update(l,r,1,n,1,num);
            return ;
        }
        inline void back(ll deletetime)
        {
            update(1,n,1,n,1,-1*deletetime);
            return ;
        }
} tree;
int n,m;
ll a[maxn+5];
ll lastans=0;
inline void work1()
{
    int l,r,v;
    cin>>l>>r>>v;
    l^=lastans;
    r^=lastans;
    tree.change(l,r,v);
    return ;
}
inline void work2()
{
    int l,r;
    cin>>l>>r;
    l^=lastans;
    r^=lastans;
    lastans=tree.find(l,r);
    cout<<lastans<<endl;
    return ;
}
inline void work3()
{
    int x;
    cin>>x;
    x^=lastans;
    tree.back(x);
    return ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (regi i=1;i<=n;i++) cin>>a[i];
    tree.maketree(a,(ll)n);
    for (regi i=1;i<=m;i++)
    {
        int work;
        cin>>work;
        switch(work)
        {
            case 1:
                work1();
                break;
            case 2:
                work2();
                break;
            case 3:
                work3();
                break;
        }
    }
    return 0;
}