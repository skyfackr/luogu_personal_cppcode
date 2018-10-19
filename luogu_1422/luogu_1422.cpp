#include<bits/stdc++.h>
#define max1 66.945
#define max2 116.575
#define sf1 0.4463
#define sf2 0.4663
#define sf3 0.5663
using namespace std;
unsigned int e;
double m;
int main()
{
	cin>>e;
	if (e<=150)
			m=sf1*e;
			else
		if (e<=400)
			m=sf2*(e-150)+max1;
			else
		
			m=sf3*(e-400)+max2+max1;
			
	cout<<fixed<<setprecision(1)<<m<<endl;
	return 0;
}
