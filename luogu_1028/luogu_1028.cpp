#include<bits/stdc++.h>
#define regi register int
using namespace std;
int fuck(int last)
{
	int ans=1;
	int l=last/2;
	for (regi i=1;i<=l;i++) ans+=fuck(i);
	return ans; 
}
int  n;
int main()
{
	cin>>n;
	cout<<fuck(n)<<endl;
	return 0;
}
