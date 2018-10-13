#include<bits/stdc++.h>
#include<vector>
using namespace std;
int i,j,k,n,c,d,e,f,zzb=1;
bool fin;
int a[10005],b[10005],z[10005];
void zin(int x)
{
	z[zzb]=a[x];
	b[x]=1;
	zzb++;
}
int main()
{
	cin>>n>>c;
	memset(b,0,sizeof(b));
	for (i=1;i<=n;i++)
		cin>>a[i];
		
while (zzb!=n)
{
	j=1;
	while (b[j]) j++;
	k=c+zzb-1;
	fin=false;
	while (j<k&&!fin)
	{
		d=0;
		e=j;
		f=1;
		int minn=0x3f;
		for (i=j;i<=k;i++)
			if (!b[i]) minn=min(minn,a[i]);
		for (i=j;i<=k;i++)
		{
			if (a[i]==minn) 
			{
				zin(i);
				d++;
				if (f) 
				{
					e=i-1;
					while (b[e]) e--;
					if (e<j) fin=true;
					f=0;
				}
				
			}
		}
		k+=d;
		if (k>n) k=n;
		j=e;
	}
}
	for (i=n;i>=1;i--)
		if (!b[i]) zin(i);
	for (i=1;i<=n;i++)
		cout<<z[i]<<" ";
	return 0;
}
