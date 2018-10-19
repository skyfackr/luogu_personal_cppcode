#include<bits/stdc++.h>
using namespace std;
set<string> s;
int n,i,j,k;
string llist,nowl;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		nowl.clear(); 
		cin>>llist;
		nowl+='/';
		k=llist.size()-1;
		for (j=1;j<=k;j++)
		{
			if (llist[j]=='/') 
				s.insert(nowl);
			nowl+=llist[j]; 
		}
		s.insert(nowl);
		cout<<s.size()<<endl;
	}
//	cout<<"\aÎÒÆ¤£¡\n"<<endl; 
	return 0;
}
