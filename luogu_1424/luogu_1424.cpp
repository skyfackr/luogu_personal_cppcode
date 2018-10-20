#include<bits/stdc++.h>
using namespace std;
long long n,mile;
int x,i;
inline void xget()
{
	x++;
	if (x>7) x=1;
	return ;
}
int main()
{
	cin>>x>>n;
	for (i=1;i<=n;i++)
	{
		if (x<=5) mile+=250;
		xget();
	}
	cout<<mile<<endl;
	return 0;
}
