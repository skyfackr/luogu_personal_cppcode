#include<bits/stdc++.h>
#define us unsigned
#define ll long long 
using namespace std;
const us ll maxn=5*10e3;
us ll tal,con,a,b;
us int n,m,i,j;
us ll ha[maxn];
string sj;
 void bookcity(us int i,us ll d)
{
	if (ha[i]-d<1) ha[i]=1;
	else ha[i]-=d;
	return;
}
 void guy(us int i,us ll s)
{
	ha[i]*=s;
	return;
}
 void tingtime(us int i,us ll d)
{
	ha[i]=d;
	return;
}
 void zero(us int x,us int y)
{
	con=0;
	for (us int i=x;i<=y;i++)
	{
		if (ha[i]<=tal) con++;
	}
	cout<<con*600<<endl;
	return;
}
int main()
{
	cin>>n>>tal;
	for (i=1;i<=n;i++)
	{
		cin>>ha[i];
	}
	cin>>m;
	for (i=1;i<=m;i++)
	{
		sj.clear();
		cin>>sj>>a>>b;
		
		
			if (sj== "BookCity")
				bookcity(a,b);
			else if (sj== "Guy")	
			 
				guy(a,b);
			else if (sj== "Zero")	
			 
				zero(a,b);
			else if (sj== "tingtime")	
			 
				tingtime(a,b);
				
		
	}
	return 0;
}
