#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int x,num;
int main()
{
	ifstream cache;
	cache.open("dabiaocache.txt",ios::in);
	while(!cache.eof())
	{
		cache>>x;
		num++;
		system("cls");
		cout<<"found:"<<num;
	}
	system("cls");
	cout<<"cache founded:"<<num;
	freopen("dabiaocache_num.txt","a+",stdout);
time_t now_time;
now_time = time(NULL); //ȡ������ʱ�䣺��1970��1��1��0ʱ0��0�뵽��ʱ������" ���еĽ���뵱ʱ��ʱ���й�
cout<<now_time<<endl;
cout<<"--------------------"<<endl;
cout<<num<<endl<<endl;
cache.close();
return 0;
	
} 
