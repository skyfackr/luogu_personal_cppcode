#include<bits/stdc++.h>
using namespace std;
unsigned long long n,a,m,nn,mm;
unsigned long long chu(int x,int y)
{
	if (x%y==0) return x/y;
	return x/y+1;
}
int main()
{
	cin>>n>>m>>a;
	nn=chu(n,a);
	mm=chu(m,a);
	cout<<nn*mm<<endl;
	return 0;
}
