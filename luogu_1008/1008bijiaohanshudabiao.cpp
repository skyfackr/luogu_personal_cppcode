#include<bits/stdc++.h>
using namespace std;
ofstream f;
int main()
{
	f.open("bijiaohanshu.txt",ios::out);
	for (int i=1;i<=8;i++)
	{
		for (int j=i+1;j<=9;j++)
		{
			cout<<"writing: "<<i<<" to "<<j<<endl;
			f<<"i"<<i<<"!=i"<<j<<"&&";
		}
	}
	f.close();
	return 0;
}
