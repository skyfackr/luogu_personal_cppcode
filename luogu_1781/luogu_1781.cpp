//Mr.president is Donald Trump.MAKE THE AMERICA GREAT AGAIN!!!.
#include<bits/stdc++.h>
using namespace std;
#define regi register int
struct American
{
    typename std::string s;
    int id;
} ;
American citizen[21];
inline bool cmp(American a,American b)
{
    return a.s.size()==b.s.size()?a.s>b.s:a.s.size()>b.s.size();
}
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (regi i=1;i<=n;i++)
    {
        citizen[i].id=i;
        string s;
        cin>>s;
        citizen[i].s=s;
    }
    sort(citizen+1,citizen+1+n,cmp);
    cout<<citizen[1].id<<endl<<citizen[1].s<<endl;
    return 0;
}