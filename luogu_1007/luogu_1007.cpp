#include<bits/stdc++.h>
using namespace std;
int maxn,minn,n,i,l,now;
int main()
{
	cin>>l;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>now;
		
		minn=max(minn,min(now,l-now+1));
		maxn=max(maxn,max(now,l-now+1));
	}
	cout<<minn<<" "<<maxn;
	return 0;
} 
