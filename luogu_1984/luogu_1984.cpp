#include<bits/stdc++.h>
using namespace std;
double j,ntf,lastntf;
int n;
int main()
{
	cin>>n;
	j=420000.0/n;
	ntf=1;
	lastntf=1;
	for (int i=2;i<=n;i++)
	{
		lastntf=lastntf*(2*(i-1)-1)/(2*(i-1));
		ntf+=lastntf;
	}
	j*=ntf;
//	j=(int)(j*100+0.5)/100;
	cout<<fixed<<setprecision(2)<<j<<endl;
	return 0;
}
