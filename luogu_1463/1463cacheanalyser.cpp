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
now_time = time(NULL); //取得日历时间：从1970年1月1日0时0分0秒到此时的秒数" 运行的结果与当时的时间有关
cout<<now_time<<endl;
cout<<"--------------------"<<endl;
cout<<num<<endl<<endl;
cache.close();
return 0;
	
} 
