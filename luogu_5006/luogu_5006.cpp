#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define regi register int
using namespace std;
int tu[102][102];//1£º¿É×ß2£ºhp3£ºstr4£ºdef 5:monster
ll diehp, nowstr,nowdef,nowx,nowy;
struct Monster
{
    ll str,def,hp;
} mon;
inline ll fight()
{
    return max((ll)1,(ll)(ceil((double)mon.hp/(max((ll)1,(ll)nowstr-(ll)mon.def)))*max((ll)1,(ll)mon.str-(ll)nowdef)));
}
inline void print()
{
    cout<<diehp<<" "<<nowstr<<" "<<nowdef<<endl;
    return ;
}
void go()
{
    char ch;
    cin>>ch;
    if (ch=='W') nowy--;
    if (ch=='E') nowy++;
    if (ch=='N') nowx--;
    if (ch=='S') nowx++;
    switch (tu[nowx][nowy])
    {
        case 1:
            break;
        case 2:
            diehp=max((ll)0,diehp-10);
            break;
        case 3:
            nowstr+=5;
            break;
        case 4:
            nowdef+=5;
            break;
        case 5:
            diehp+=fight();
            break;
    }
    return ;
}
ll n,m,q;
char ch,did;
int main()
{
    cin>>n>>m;
    for (regi i=1;i<=n;i++)
    {
        for (regi j=1;j<=m;j++)
        {
            cin>>ch;
            if (ch=='.') tu[i][j]=1;
            if (ch=='R') tu[i][j]=2;
            if (ch=='Q') tu[i][j]=3;
            if (ch=='Y') tu[i][j]=4;
            if (ch=='M') tu[i][j]=5;
        }
    }
    cin>>mon.hp>>mon.str>>mon.def;
    cin>>nowx>>nowy;
    cin>>nowstr>>nowdef;
    cin>>q;
    for (regi i=1;i<=q;i++)
    {
        cin>>did;
        if (did=='M') go();
        if (did=='Q') print();
    }
    return 0;
}
