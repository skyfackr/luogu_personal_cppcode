#include<bits/stdc++.h>
using namespace std;
#define regi register int
#define ll long long
ll n,last,x;
ll ans;
int main()
{
    cin>>n;
    cin>>last;
    ans=last;
    for (regi i=2;i<=n;i++)
    {
        cin>>x;
        ans+=max((ll)0,x-last);
        last=x;
    }
    cout<<ans<<endl;
    return 0;
}