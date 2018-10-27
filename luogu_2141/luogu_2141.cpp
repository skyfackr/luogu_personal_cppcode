#include<bits/stdc++.h>
#define reg register int
using namespace std;
int n;
int num[105],numbj[20005];
set<int> ans;
int main()
{
	cin>>n;
	for (reg i=1;i<=n;i++) 
	{
		cin>>num[i];
		numbj[num[i]]=1;
	}
	for (reg i=1;i<=n-1;i++)
	{
		for (reg j=1+i;j<=n;j++)
		{
			int k=num[i]+num[j];
			if (numbj[k]) 
			ans.insert(k);
		}
	}
	cout<<ans.size();
	cout<<endl;
//	system("pause");
	exit(0);
}
