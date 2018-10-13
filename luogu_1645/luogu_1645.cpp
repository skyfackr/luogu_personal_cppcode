#include<bits/stdc++.h>
using namespace std;
int i,j,k,ans,n,li,ri,ci,jwb,sltgp,maxlen;
typedef struct cnm
{
    int l,r,c;
}cnm;
cnm sj[1005];
int jw[1005];
int aac[1005];
bool fuck(const cnm a,const cnm b)
{
    if (a.l==b.l) return a.r<b.r;
    else return a.l<b.l;
}
int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>sj[i].l>>sj[i].r>>sj[i].c;
        maxlen=max(maxlen,sj[i].r);
        aac[sj[i].r]=1;
    }
    sort(sj+1,sj+n+1,fuck);
   // jwb=0;
    for (i=1;i<=n;i++)
    {
        
    }
    for (i=1;i<=maxlen;i++) ans+=jw[i];
    cout<<ans;
    return 0;
} 
