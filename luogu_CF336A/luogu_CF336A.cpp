#include<bits/stdc++.h>
using namespace std;
#define e0 exit(0);
int x,y;
void out1()
{
    int ans=x+y;
    cout<<"0 "<<ans<<" "<<ans<<" 0"<<endl;
    e0
}
void out2()
{
    int ans=-1*x+y;
    cout<<-1*ans<<" 0 0 "<<ans<<endl;
    e0
}
void out3()
{
    int ans=-1*x-y;
    cout<<-1*ans<<" 0 0 "<<-1*ans<<endl;
    e0
}
void out4()
{
    int ans=x-y;
    cout<<"0 "<<-1*ans<<" "<<ans<<" 0"<<endl;
    e0
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>x>>y;
    if (x>=0&&y>=0) out1();
    if (x<0&&y>=0) out2();
    if (x<0&&y<0) out3();
    if (x>=0&&y<0) out4();
    return 0;
}
