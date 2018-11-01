#include<bits/stdc++.h>
#define regi register int
using namespace std;
int t,s,x;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t>>s>>x;
	if (x<t)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	if (x==t||s==1) 
	{
		cout<<"YES"<<endl;
		return 0;
	}
	if (x==t+1) 
	{
		cout<<"NO"<<endl;
		return 0;
	}
	x-=t;
	if (x%s<=1)
	{
		cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;
	return 0;
} 
