#include<bits/stdc++.h>
using namespace std;
int bank,nowm,i;
int a[13];
int main()
{
	for (i=1;i<=12;i++)
	{
		cin>>a[i];
	}
	for (i=1;i<=12;i++)
	{
		nowm+=300;
		nowm-=a[i];
		if (nowm<0)
		{
			cout<<"-"<<i<<endl;
			return 0;
		}
		bank+=(int)(nowm/100)*100;
		nowm%=100;
	}
	cout<<bank*1.2+nowm<<endl;
	return 0;
}
