#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define regi register int
bool cantgo[21][21]={false};
int n,m,housex,housey;
ll dp[21][21];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>housex>>housey;
    cantgo[housex][housey]=cantgo[housex-2][housey+1]=cantgo[housex-2][housey-1]=cantgo[housex+2][housey-1]=cantgo[housex+2][housey+1]=true;
    for (regi i=0;i<=n;i++)
    {
        for (regi j=1;j<=m;j++)
        {
            
        }
    }
}