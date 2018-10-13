#include<bits/stdc++.h>
#include<queue>
using namespace std;
int h,i,n,j,k;
priority_queue<int,vector<int>,greater<int> > money;
int main()
{
	cin>>n;
	while (n>0)
	{
		money.push(int((double)n/2+0.5));
		n/=2;
//		h++;
	}
	
	cout<<money.size()<<endl;
	while (!money.empty())
	{
		j=money.top();
		money.pop();
		cout<<j<<" ";
	}
	return 0;
} 
