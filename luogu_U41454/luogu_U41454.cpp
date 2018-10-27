#include<bits/stdc++.h>
#include<queue>
#define regi register int
using namespace std;
queue<int> dnpass;
stack<int> enpass,pass;
int n,p;
int main()
{
	cin>>n;
	for (regi i=1;i<=n;i++)
	{
		cin>>p;
		enpass.push(p);
	}
	dnpass.push(enpass.top());
	enpass.pop();
	while (enpass.size()>1)
	{
		dnpass.push(enpass.top());
		enpass.pop();
		dnpass.push(dnpass.front());
		dnpass.pop();
	}
	dnpass.push(enpass.top());
	enpass.pop();
	int l=dnpass.size();
	for (regi i=1;i<=l;i++)
	{
		pass.push(dnpass.front());
		dnpass.pop();
	}
	for (regi i=1;i<=l;i++)
	{
		cout<<pass.top()<<" ";
		pass.pop();
	}
	return 0;
}
