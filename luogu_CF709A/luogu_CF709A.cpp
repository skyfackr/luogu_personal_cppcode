#include<bits/stdc++.h>
using namespace std;
int n,b,d,ans;
#define regi register int
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>b>>d;
    int now,box=0;
    for (regi i=1;i<=n;i++)
    {
        cin>>now;
        if (now>b) continue;
        box+=now;
        if (box>d)
        {
            ans++;
            box=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
