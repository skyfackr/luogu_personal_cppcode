#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define regi register int
ll a1,n,x;
void geta1()
{
    if ((x & 1)==1) n=1;
    for (regi i=2;i<=sqrt(x-1);i++)
    {
        if ((x-1)%i==0)
        {
            a1=i;
            n+=(x-1)/i;
            return ;
        }
    }
    cout<<x<<" "<<x<<endl;
    exit(0);
}
int main()
{
    cin>>x;
    geta1();
    if (n%2==0)
    {
        cout<<x<<" "<<x<<endl;
        return 0;
    }
    n/=2;
    cout<<a1<<" "<<a1+n<<endl;
    return 0;
}