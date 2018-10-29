#include<bits/stdc++.h>
#define regi register int
using namespace std;
string a,b;
unsigned long long aa=1,bb=1;
int main()
{
	getline(cin,a);
	getline(cin,b);
	for (regi i=0;i<=a.size()-1;i++)
	{
		aa*=a[i]-'A'+1;
		
		
	}
	aa%=47;
	for (regi i=0;i<=b.size()-1;i++)
	{
		bb*=b[i]-'A'+1;
		
	}
	bb%=47;
	if (aa==bb) cout<<"GO"<<endl;
	else cout<<"STAY"<<endl;
	return 0;
}
