#include<bits/stdc++.h>
using namespace std;
unsigned int x,n,i,t,ans;
int main()
{
	cin>>n>>x;
	for (i=1;i<=n;i++)
	{
		t=i;
		while (t)
		{
			if (t%10==x)
			{
				ans++;
			}
			t/=10;
		}
	} 
	cout<<ans<<endl;
	return 0;
}
