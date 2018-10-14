#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll b,p,k,d,dd,pp;
int main()
{
	cin>>b>>p>>k;
	d=0;
	dd=b;
	pp=p;
	if (p%2==1)
	{
		p--;
		d=1;
		
	}
	while (p>1)
	{
		if (p%2==1)
	{
		p--;
		b*=dd;
		
	}
		b=pow(b,2);
		b%=k;
		
		p/=2;
	}
//	if (d==1) b*=dd;
	cout<<dd<<"^"<<pp<<" mod "<<k<<"="<<b*dd%k<<endl;
	return 0;
}
