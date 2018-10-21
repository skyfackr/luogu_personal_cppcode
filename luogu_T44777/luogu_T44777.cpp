#include<bits/stdc++.h>
using namespace std;
int last,n,i,j,k,num,ans;
int h[1005],bag[1005];
void bagget()
{
	last=n;
	while (bag[last]==1) last--;
	bag[last]=1;
	num++;
	for (int i=last+1;i<=n;i++) 
	{
		bag[i]=0;
		num--;
	}
	return ;
}
bool fuck(int l,int v)
{
	if (l==last) return true;
	int r=l+1;
	while (bag[r]==0) r++;
	if (h[r]-h[l]==v) return fuck(r,v);
	else return false;
}
inline void asj()
{
	ans++;
	ans%=998244353;
	return;
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	while (bag[0]==0)
	{
		bagget();
		if (num==1)
		{
			asj();
			continue;
		}
		j=0;
		while (bag[j]==0) j++;
		k=j+1;
		while (bag[k]==0) k++;
		if (fuck(k,(h[k]-h[j]))) asj();
	}
	cout<<ans-1<<endl;
	return 0;
}
