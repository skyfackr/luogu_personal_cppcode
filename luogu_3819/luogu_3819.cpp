#include<bits/stdc++.h>
using namespace std;
#define regi register int
#define maxn 100001
#define ll long long
ll road[maxn],people[maxn];
ll l,r,fuckl,n;
ll ans;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>fuckl>>n;
    for (regi i=1;i<=n;i++)
    {
        cin>>road[i]>>people[i];
    }
    l=1;
    r=n;
    while (l<r)
    {
        if (people[l]<people[r])
        {
            people[r]-=people[l];
            ans+=people[l]*(abs(road[l]-road[r]));
            people[l]=0;
            l++;
        }
        else
        {
            people[l]-=people[r];
            ans+=people[r]*(abs(road[l]-road[r]));
            people[r]=0;
            r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
