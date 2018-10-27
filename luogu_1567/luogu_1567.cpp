#include<bits/stdc++.h>
using namespace std;
int n,ans,yesd,tod,js;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (register int i=1;i<=n;i++)
	{
		yesd=tod;
		cin>>tod;
		if (tod>yesd) js++;
		else 
		{
			ans=max(js,ans);
			js=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
