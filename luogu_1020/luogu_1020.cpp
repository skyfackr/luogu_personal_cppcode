#include<bits/stdc++.h>
#define mian main
using namespace std;
int he[100005],on[100005],down[100005];
int n,i,j,k,ans;
int onmiddleget(int x)
{
	int l=1;
	int r=ans;
	int m=(ans+1)/2;
	while (l<r)
	{
		if (on[m]==x)
		{
			while (on[m-1]==x) m--;
			l=m;
			r=m;
		}
		else if (on[m]>x) r=m;
		else l=m+1;
		m=(l+r)/2;
	}
//	if (on[l]!=on[r]) return r;
	return r;
}
int downmiddleget(int x)
{
	int l=1;
	int r=ans;
	int m=(ans+1)/2;
	while (l<r)
	{
		if (down[m]==x)
		{
			while (down[m-1]==x) m--;
			l=m;
			r=m;
		}
		else if (down[m]<x) r=m;
		else l=m+1;
		m=(l+r)/2;
	}
//	if (down[l]!=down[r]) return r;
	return r;
}
void onpush(int x)
{
	ans++;
	on[ans]=x;
	return;
}
void downpush(int x)
{
	ans++;
	down[ans]=x;
	return ;
}
int main()
{
	n=0;
	while(cin>>k)
	{
		n++;
		he[n]=k;
	}
/*	while(scanf("%d",&he[++n])!=EOF){
		continue;
	};*/
//	cout<<"test"<<endl;
	ans=1;
	down[1]=he[1];
	for (i=2;i<=n;i++)
	{
		if (down[ans]>he[i]) downpush(he[i]);
		else 
		{
			j=downmiddleget(he[i]);
			down[j]=he[i];
		}
	}
	
	cout<<ans<<endl;
	on[1]=he[1];
	ans=1;
	for (i=2;i<=n;i++)
	{
		if (on[ans]<he[i]) onpush(he[i]);
		else 
		{
			j=onmiddleget(he[i]);
			on[j]=he[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
