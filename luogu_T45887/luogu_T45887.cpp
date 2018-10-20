#include<bits/stdc++.h>
#define us unsigned
#define ll long long
using namespace std;
struct S
{
	bool fyw;
	ll qaq;
}ying[100005];
int n,m,i,j,k,now,x,l,r,val,nowfyw;
us ll ans;
inline void fywget(int x,int val)
{
	ying[x].fyw=true;
	nowfyw=x;
	ying[x].qaq=max((ll)1,val-ying[x].qaq);
	return;
}
inline void fywqaq(int l,int r,int val)
{
	for (int i=l;i<=r;i++)
	{
		ying[i].qaq+=val;
	}
	return;
}
void levelup(int l,int r)
{
	if (l<=nowfyw&&r>=nowfyw)
	{
		cout<<ying[nowfyw].qaq<<endl;
		ans+=ying[nowfyw].qaq;
		ying[nowfyw].qaq=0;
		ying[nowfyw].fyw=false;
		nowfyw=-1;
		return;
	}
	ll maxqaq=0;
	int maxqaqnumber;
	for (int i=l;i<=r;i++)
	{
		if (maxqaq<ying[i].qaq)
		{
			maxqaq=ying[i].qaq;
			maxqaqnumber=i;
		}
		
		
	}
	cout<<maxqaq<<endl;
	ans+=maxqaq;
	ying[maxqaqnumber].qaq=0;
	return;
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>ying[i].qaq;
	}
	for (i=1;i<=m;i++)
	{
		cin>>now;
		switch (now)
		{
			case 1:
				cin>>x>>val;
				fywget(x,val);
				break;
			case 2:
				cin>>l>>r;
				levelup(l,r);
				break;
			case 3:
				cin>>l>>r>>val;
				fywqaq(l,r,val);
				break;
		}
		
	}
	if (ans<10000)
		{
			cout<<"QAQ"<<endl;
		}
		else if (ans<10000000)
		{
			cout<<"Sakura"<<endl;
		}
		else cout<<"ice"<<endl;
	return 0;
}
