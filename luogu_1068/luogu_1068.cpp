#include<bits/stdc++.h>
using namespace std;
#define regi register int
#define ll long long
struct sData
{
    int id,score;
} sdata[5001];
int n,k,s,m,deadline,peoplealive;
inline bool cmp(sData a,sData b)
{
    return a.score==b.score?a.id<=b.id:a.score>b.score;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (regi i=1;i<=n;i++)
    {
        cin>>k>>s;
        sdata[i].id=k;
        sdata[i].score=s;
    }
    sort(sdata+1,sdata+n+1,cmp);
    peoplealive=m*1.5;
    deadline=sdata[peoplealive].score;
    while (sdata[peoplealive+1].score==deadline) peoplealive++;
    cout<<deadline<<" "<<peoplealive<<endl;
    for (regi i=1;i<=peoplealive;i++)
    {
        cout<<sdata[i].id<<" "<<sdata[i].score<<endl;
    }
    return 0;
}