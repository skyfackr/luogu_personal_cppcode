#include<bits/stdc++.h>
#include<climits>
using namespace std;
int a1,a2,a3,b1,b2,b3,i,n,m,ans=INT_MAX;
inline void ansm()
{
	ans=min(ans,m);
}
int main()
{
	cin>>n>>a1>>b1>>a2>>b2>>a3>>b3;
	m=(int)(n/a1)*b1;
	if (n%a1!=0) m+=b1;
	ansm();
	m=(int)(n/a2)*b2;
	if (n%a2!=0) m+=b2;
	ansm();
	m=(int)(n/a3)*b3;
	if (n%a3!=0) m+=b3;
	ansm();
	cout<<ans<<endl;
	return 0;
}
