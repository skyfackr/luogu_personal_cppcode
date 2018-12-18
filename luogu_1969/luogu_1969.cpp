#include<bits/stdc++.h>
using namespace std;
#define regi register int
#define ll long long
ll n,last,now,ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cin>>last;
    ans=last;
    for (regi i=2;i<=n;i++)
    {
        cin>>now;
        ans+=max((ll)0,now-last);
        last=now;
    }
    cout<<ans<<endl;
    return 0;
}