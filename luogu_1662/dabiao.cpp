#include<bits/stdc++.h>
#include<time.h>
using namespace std;
 bool okay(int x)
{
	if (x%7==0) return 1;
	while(x>0)
	{
		
		if (x%10==7) return 1;
		x=x/10;
	}
	return 0;
}
int main()
{
	int cputime=CLOCKS_PER_SEC;
	char num[25]="dabiao_number.txt";
	char des[25]="dabiao_destnation.txt";
	int time=1000000;
	int i,j,k,d,start,end,t;
	freopen(num,"w",stdout);
	freopen(des,"w",stdout);
	freopen("CON","w",stdout);
	cout<<"start "<<time<<" time"<<endl;
	start=clock();
	k=1;
	j=0;
	d=0;
	t=0;
	for (i=1;i<=1000000000;i++)
	{
		d++;
		if (k==1) 
		{
			j++;
			if (j==1338) j=1;
			if (okay(i)) k=-1;
		}
		else 
		{
			j--;
			if (j==0) j=1337;
			if (okay(i)) k=1;
		}
		if (d==time)
		{
			d=0;
			freopen(num,"a+",stdout);
			cout<<j<<",";
			freopen(des,"a+",stdout);
			cout<<k<<",";
			t++;
		}
	}
	freopen("CON","w",stdout);
	end=clock();
	cout<<"complete"<<endl<<"time:"<<abs(start-end)/cputime<<"s"<<endl<<"number:"<<t;
	return 0;
}
