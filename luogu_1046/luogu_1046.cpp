#include<bits/stdc++.h>
#define us unsigned
#define ll long long
#define it int
using namespace std;
us ll stevejobs[11];
us it ming,ans;
int main()
{
	for (register int i=1;i<=10;i++) cin>>stevejobs[i];
	cin>>ming;
	ming+=30;
	for (register int i=1;i<=10;i++) ans+=stevejobs[i]<=ming?1:0;
	cout<<ans;
	return 0;
}
