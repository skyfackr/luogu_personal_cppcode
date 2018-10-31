#include<bits/stdc++.h>
using namespace std;
string in,mu;
int num,now=-1,first=-1;
int main()
{
	cin>>mu;
	for (int i=0;i<=mu.size()-1;i++) mu[i]=tolower(mu[i]);
	while (cin>>in) 
	{
		now++;
		for (int i=0;i<=in.size()-1;i++) in[i]=tolower(in[i]);
		if (in==mu)
		{
			num++;
			if (first==-1) first=now;
		}
	}
	if (first==-1) cout<<"-1"<<endl;
	else cout<<num<<" "<<first<<endl;
	return 0;
} 
