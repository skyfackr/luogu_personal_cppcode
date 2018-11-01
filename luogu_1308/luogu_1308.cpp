#include<bits/stdc++.h>
using namespace std;
string in,mu;
int num,now=0,first=-1,nowl;
int main()
{
	getline(cin,mu);
	getline(cin,in);
	for (int i=0;i<=mu.size()-1;i++) mu[i]=tolower(mu[i]);
	for (int i=0;i<=in.size()-1;i++) in[i]=tolower(in[i]);
	mu=' '+mu+' ';
	in=' '+in+' ';
	size_t test=in.find(mu);
	if (test==string::npos) 
	{
		cout<<"-1"<<endl;
		return 0;
	}
	size_t ans=test;
	while (test!=string::npos)
	{
		num++;
		test=in.find(mu,test+1);
	}
	cout<<num<<" "<<ans<<endl;
	return 0;
}
