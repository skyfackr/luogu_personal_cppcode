#include<bits/stdc++.h>
using namespace std;
string s;
#define regi register int
//bool ss[100005]={false};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	int n=s.size();
	for (regi i=0;i<=n-1;i++)
	{
		
		int j=n-1-i;
		if ((s[i]=='b'&&s[j]=='d')||(s[i]=='d'&&s[j]=='b')||(s[i]=='q'&&s[j]=='p')||(s[i]=='p'&&s[j]=='q'))
			continue;
		else
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
