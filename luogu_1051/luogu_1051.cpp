#include<bits/stdc++.h>
using namespace std;
#define regi register int
#define ll long long
string maxid;
ll maxmoney,totalmoney;
inline bool isthatok()
{
    char ch;
    cin>>ch;
    if (ch=='Y') return true;
    return false;
}
ll finalscore,classscore,article;
bool western,manager;
inline ll yuanshi()
{
    if ((finalscore>80)&&(article>=1))
        return 8000;
    return 0; 
}
inline ll redteenager()
{
    if ((finalscore>85)&&(classscore>80)) return 4000;
    return 0;
}
inline ll goodstu()
{
    if (finalscore>90) return 2000;
    return 0;
}
inline ll westernstu()
{
    if ((finalscore>85)&&western) return 1000;
    return 0;
}
inline ll goodman()
{
    if ((classscore>80)&&manager) return 850;
    return 0;
}
inline ll getmoney()
{
    return yuanshi()+redteenager()+goodstu()+westernstu()+goodman();
}
ll n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (regi i=1;i<=n;i++)
    {
        string name;
        cin>>name>>finalscore>>classscore;
        manager=isthatok();
        western=isthatok();
        cin>>article;
        ll hismoney=getmoney();
        if (hismoney>maxmoney)
        {
            maxid=name;
            maxmoney=hismoney;
        }
        totalmoney+=hismoney;
    }
    cout<<maxid<<endl<<maxmoney<<endl<<totalmoney<<endl;
    return 0;
}