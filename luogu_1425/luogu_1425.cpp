#include<bits/stdc++.h>
using namespace std;
int ax,ay,bx,by,cx,cy;
int main()
{
	cin>>ax>>ay>>bx>>by;
	cx=bx-ax;
	cy=by-ay;
	if (cy<0)
	{
		cx--;
		cy+=60;
	}
	cout<<cx<<" "<<cy<<endl;
	return 0;
}
