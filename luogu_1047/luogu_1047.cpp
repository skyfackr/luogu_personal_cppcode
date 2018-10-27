#include<bits/stdc++.h>
#define regi register int
using namespace std;
int l,m,x,y,now,ans;
int cutin[10005],cutout[10005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>l>>m;
	for (regi i=1;i<=m;i++)
	{
		cin>>x>>y;
		cutin[x]++;
		cutout[y]++;
	}
	for (regi i=0;i<=l;i++)
	{
		now+=cutin[i];
		
		if (now==0) ans++;
		now-=cutout[i];
	}
	cout<<ans<<endl;
	return 0;
}
