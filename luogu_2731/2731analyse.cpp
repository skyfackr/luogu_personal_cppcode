#include<bits/stdc++.h>
using namespace std;
ifstream data1;
ifstream data2;
int x1,x2,num;
map<int,int> m1,m2;
int main()
{
	data1.open("testdata2.out",ios::in);
	data2.open("data2out.out",ios::in);
	cout<<"analysising...."<<endl;
	while ((!data1.eof())&&(!data2.eof()))
	{
		data1>>x1;
		m1[x1]++;
		data2>>x2;
		m2[x2]++;
		num++;
		if (x1!=x2)
		{
			cout<<"founded! "<<num<<endl;
			cout<<"�ڱ�����֣�"<<x1<<endl;
			cout<<"�����ˣ�"<<m1[x1]<<endl; 
			cout<<"������ļ����֣�"<<x2<<endl;
			cout<<"�����ˣ�"<<m2[x2]<<endl;  
			return 0;
		}
	}
	if (data1.eof()&&data2.eof())
	{
		cout<<"not found"<<endl;
		return 0;
	}
	else if (data1.eof()&&(!data2.eof()))
	{
		cout<<"������ȹ���"<<endl;
		return 0; 
	}
	else if ((!data1.eof())&&data2.eof())
	{
		cout<<"������ȹ���"<<endl;
		return 0; 
	}
	return 0;
}
