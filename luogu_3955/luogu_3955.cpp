#include<bits/stdc++.h>
using namespace std;
#define regi register int
#define maxn 1001
#define ll long long
ll isbn[maxn];
string member;
int n,q;
/*class bookfound:public exception
{
    public:
        bookfound()
        {
            exception();
        }
};*/
string to_string_mine(ll x)
{
    stringstream s;
    s<<x;
    return s.str();
}
void findbook(string member,ll memlen)
{
    string nowbook;
    for (regi i=1;i<=n;i++)
    {
        nowbook=to_string_mine(isbn[i]);
        ll nowbooklen=nowbook.length();
        ll bookfounded=nowbook.rfind(member);
        bool youok=(bookfounded==(nowbooklen-memlen));
        if (youok)
        {
            cout<<isbn[i]<<endl;
            return ;
//            throw bookfound();
        }
    }
    cout<<"-1"<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for (regi i=1;i<=n;i++)
    {
        cin>>isbn[i];
    }
    sort(isbn+1,isbn+n+1);
    
    ll memlen;
    for (regi i=1;i<=q;i++)
    {
        cin>>memlen;
        cin>>member;
//        try
  //      {
            findbook(member,memlen);
    //    }
      //  catch(bookfound){continue;}
    }
    return 0;
}