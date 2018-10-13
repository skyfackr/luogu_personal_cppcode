#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,ans;
//const long long roadmax=1e9+200005;
std::map<int,int> zlen;
std::map<int,int> flen;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>k;
		ans+=zlen[i+k];
		zlen[i+k]++;
		if (i-k<0)
		{
			j=k-i;
			ans+=flen[j];
			flen[j]++;
		}
		else
		{
			j=i-k;
			ans+=zlen[j];
			zlen[j]++;
		}
	}
	cout<<ans;
	return 0;
}
