#include<bits/stdc++.h>
using namespace std;
#define regi register int
#define maxn 20001
int n,k;
int e[11];
struct W
{
    int id;
    int score;
} w[maxn];
inline int enumber(int x)
{
    return (x-1)%10+1;
}
inline bool cmp(W a,W b)
{
    return a.score==b.score?a.id<b.id:a.score>b.score;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for (regi i=1;i<=10;i++) cin>>e[i];
    for (regi i=1;i<=n;i++)
    {
        w[i].id=i;
        cin>>w[i].score;
    }
    sort(w+1,w+1+n,cmp);
    for (regi i=1;i<=n;i++)
    {
        w[i].score+=e[enumber(i)];
    }
    sort(w+1,w+1+n,cmp);
    for (regi i=1;i<=k;i++)
    {
        cout<<w[i].id<<" ";
    }
    cout<<endl;
    return 0;
}