#include<bits/stdc++.h>
using namespace std;
int ans=0;
double x,now=2.0,youed=0.0;
int main()
{
	cin>>x;
	while (youed<x)
	{
		ans++;
		youed+=now;
		now*=0.98;
	}
	cout<<ans<<endl;
	return 0;
}
