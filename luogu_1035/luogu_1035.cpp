#include<bits/stdc++.h>
using namespace std;
int k,ans;
double i;
int main()
{
	cin>>k;
	ans=1;
	for (i=0;i<=k;ans++)
	{
		i+=(double)1/ans;
	}
	cout<<ans-1;
	return 0;
} 
