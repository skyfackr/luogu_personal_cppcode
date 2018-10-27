#include<bits/stdc++.h>
#define it int
#define ll long long
#define ust unsigned int
#define usg unsigned long long
#define regi register int
using namespace std;
it n,l,r;
usg ans=0;
char ch;
struct linking
{
	it x,y;
};
vector<linking> link;
bool bin[305]={false};
bool get;
void linkstart(it l,it r)
{
	if (l==r) return ;
	while (bin[l]==false&&bin[r]==true)
	{
		linking now;
		now.x=l;
		now.y=r;
		l++;
		r--;
		link.push_back(now);
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	l=r=1;
	get=false;
	for (regi i=1;i<=n;i++)
	{
		cin>>ch;
		if (ch=='1') 
		{
			bin[i]=true;
			get=true;
		}
		else if (get)
		{
			r=i-1;
			linkstart(l,r);
			l=i;
			get=false;
		}
	}
	linkstart(l,n);
	l=link.size();
	for (regi i=0;i<=l-1;i++)
	{
		ans+=abs(link[i].y-link[i].x);
	}
	cout<<ans<<endl;
	return 0;
}
