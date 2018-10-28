#include<bits/stdc++.h>
using namespace std;
//水个屁，不会。。。。。 
unsigned int n;
int t;
int main()
{
	cin>>t;
	while (t)
	{
		t--;
		cin>>n;
		cout<<n*n*(n-1)/2%(unsigned int)(10e9+9)<<endl;
	}
	return 0;
} 
