#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll b,p,k,ans,dd,pp;
int main()
{
	cin>>b>>p>>k;
	ans=1;
	dd=b;
	pp=p;
	while (p>0)
	{
		if (p&1)
		{
			ans*=b;
			ans%=k;
		}
		b*=b;
		b%=k;
		p/=2;
	}
//	if (d==1) b*=dd;
	cout<<dd<<"^"<<pp<<" mod "<<k<<"="<<ans%k<<endl;
	return 0;
}
