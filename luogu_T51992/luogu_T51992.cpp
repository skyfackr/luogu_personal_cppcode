#include<bits/stdc++.h>
using namespace std;
//ˮ��ƨ�����ᡣ�������� 
unsigned int n;
int t;
int main()
{
	cin>>t;
	while (t)
	{
		t--;
		cin>>n;
		cout<<n*n*(n-1)/2%(unsigned int)(10e9+9)<<endl;
	}
	return 0;
} 
