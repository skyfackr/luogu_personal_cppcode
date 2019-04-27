#include<bits/stdc++.h>
using namespace std;
#define ll int
#define regi register int
ll n,m;
const int maxn=10000005;
bool notprime[maxn]={false};
ll p[maxn];int pnum=0;
void primeget()
{
    
    notprime[0]=notprime[1]=true;
    for (regi i=2;i<=n;i++)
    {
        if (!notprime[i]) p[++pnum]=i;
        for (regi j=1;j<=pnum&&i*p[j]<=n;j++)
        {
            notprime[i*p[j]]=true;
            if (i%p[j]==0) break;
        }
    }
    return;
}
int main()
{
 //   ios::sync_with_stdio(0);
 //   cin.tie(0);
    cin>>n>>m;
    primeget();
    for (regi i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        cout<<(!notprime[x]?"Yes":"No")<<endl;
    }
    return 0;
}