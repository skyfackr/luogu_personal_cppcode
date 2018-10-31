#include<bits/stdc++.h>
using namespace std;
string s;
int a,b,n;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s>>a>>b;
		if(b>a&&a>=2400) 
		{
			cout<<"YES"<<endl;
			exit(0);
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
