//放弃了，暴力吧，我太弱了QAQ 
#include<bits/stdc++.h>
#define us unsigned
#define it int
#define ll long long
#define maxn (unsigned int)10e6+3
#define ch char
#define mian main
#define reg register
using namespace std;
ch zm[maxn];
us it n,l;
us ll ans=0;
us it getzm(ll x);
it mian()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>l;
	for (reg us it i=1;i<=n;i++) cin>>zm[i];
	if (l==0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	if (l==1)
	{
		cout<<n<<endl;
		return 0;
	}
	for (reg us it i=1;i<=n;i++)
	{
		ans++;
		for (reg us it j=1;j<=l-1;j++)
		{
			if (zm[getzm((ll)i-j)]!=zm[getzm((ll)i+j)])
			{
				ans--;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
us it getzm(ll x)
{
	if (x<1) return n+x;
	if (x>n) return x-n;
	return x;
}
