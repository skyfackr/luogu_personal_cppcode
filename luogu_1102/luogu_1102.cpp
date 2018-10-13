#include<bits/stdc++.h>
#include<queue>
using namespace std;
map<long long,long long> num;
queue<int> number;
int n,i,j,c;
long long ans;
int main()
{
//	freopen("testdata.in","r",stdin);
	cin>>n>>c;
	for (i=1;i<=n;i++)
	{
		cin>>j;
		if (num[j]==0) number.push(j);
		num[j]++;
	}
	while (!number.empty())
	{
		j=number.front();
		number.pop();
//		int a=num[j];
//		int b=num[j-c];
		if (j>=c) ans+=num[j]*num[j-c];
	}
	cout<<ans<<endl;
	return 0;
}
