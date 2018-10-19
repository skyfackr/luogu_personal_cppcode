#include<bits/stdc++.h>
using namespace std;
int n,i,j,k,now;
char c;
int a[105];
void finder(int noww,int nowzz,int nowfw)//当前判断 当前指针 当前分的数 
{
	nowfw+=a[nowzz];
	if (nowfw==noww)
	{
		if (nowzz==n)
		{
			cout<<"YES"<<endl;
			exit(0);
		}
		if (a[nowzz+1]==0) finder(noww,nowzz+1,nowfw);
		else
		finder(noww,nowzz+1,0);
	}
	else if (nowfw<noww)
	{
		if (nowzz==n)
		{
			if (j==n-1)
			{
				cout<<"NO"<<endl;
				exit(0);
			}
			j++;
			finder(noww+a[j],j+1,0);
		}
		finder(noww,nowzz+1,nowfw);
	}
	else
	{
		if (j==n-1)
		{
			cout<<"NO"<<endl;
			exit(0);
		}
		j++;
		finder(noww+a[j],j+1,0);
	}
	return ;
}
int main()
{
	cin>>n;
	bool zero=true;
	for (i=1;i<=n;i++)
	{
		cin>>c;
		if (c!='0') zero=false;
		a[i]=c-'0';
	}
	if (zero==true)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	if (n==2)
	{
		if (a[1]==a[2]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		return 0;
	}
	j=1;
	now=a[1];
	finder(now,2,0);
	cout<<"NO"<<endl;
	return 0;
}
