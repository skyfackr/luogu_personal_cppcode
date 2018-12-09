//成绩
#include<bits/stdc++.h>
#define ll unsigned long long
#define regi register int
using namespace std;
ll nows,n,minuss;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    ll ds;
    for (regi i=1;i<=n;i++)
    {
        cin>>ds;
        nows+=ds*3;
        minuss+=ds;
    }
    for (regi i=1;i<=n;i++)
    {
        cin>>ds;
        nows-=ds*2;
        minuss-=ds;
    }
    cout<<fixed<<setprecision(6)<<(double)(nows/minuss)<<endl;
    return 0;
}