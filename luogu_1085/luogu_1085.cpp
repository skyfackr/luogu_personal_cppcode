#include<bits/stdc++.h>
using namespace std;
struct Ans
{
	int day,h;
}ans;
int x,y,i;
int main()
{
	ans.day=ans.h=0;
	for (i=1;i<=7;i++)
	{
		cin>>x>>y;
		if (x+y-8>ans.h) 
		{
			ans.day=i;
			ans.h=x+y-8;
		}
	}
	cout<<ans.day<<endl;
	return 0;
}
