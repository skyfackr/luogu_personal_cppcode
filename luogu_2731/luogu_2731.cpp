#include<bits/stdc++.h>
#include<queue>
#define maxn 1030
using namespace std;
int zha[maxn][maxn];
int du[maxn];
int n,i,j,k,begin=maxn,end;
stack<int> ans;
void dfs(int now)
{
//	ans.push(now);
	for (int i=1;i<=end;i++)
	{
		if (zha[now][i]!=0)
		{
			zha[now][i]--;
			zha[i][now]--;
			dfs(i);
		}
	}
	ans.push(now);
	return;
}
void get(int x,int y)
{
	begin=min(begin,x);
	begin=min(begin,y);
	end=max(end,x);
	end=max(end,y);
	zha[x][y]++;
	zha[y][x]++;
	du[x]++;
	du[y]++;
	return;
}
int main()
{
//	freopen("testdata2.in","r",stdin);
//	freopen("data2out.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>j>>k;
		get(j,k);
	}
	for (i=begin;i<=end;i++)
       if(du[i]%2==1) 
       {   
           begin=i;
           break;
       }
       dfs(begin);
    while (!ans.empty())
    {
    	cout<<ans.top()<<endl;
    	ans.pop();
    }
    return 0;
}
