#include<bits/stdc++.h>
#include<cmath>
#include<time.h>
#include<stdlib.h>
using namespace std;
int num1;
std::map<long long,long long> su;
void cacheanalyser()
{
	int x;
		ifstream cache;
	cache.open("dabiaocache.txt",ios::in);
	freopen("CON","w",stdout);
	num1=0;
	while(!cache.eof())
	{
		//cache>>x;
		//num1++;
		//system("cls");
		num1++;
		cache>>su[num1];
		cout<<"su-found:"<<num1<<endl;
	}
	//system("cls");
	cout<<"su-cache founded:"<<num1;
	freopen("dabiaocache_num.txt","a+",stdout);
time_t now_time;
now_time = time(NULL); //取得日历时间：从1970年1月1日0时0分0秒到此时的秒数" 运行的结果与当时的时间有关
cout<<now_time<<endl;
cout<<"--------------------"<<endl;
cout<<num1<<endl<<endl;
cache.close();
freopen("CON","w",stdout);
_sleep(3000);
return ;
} 
 
  
int PrimeFactorization2(int n){
	int min = 1;
	int max = (int)floor(sqrt((double)n));
//	cout << "max:" << max << endl;
	int sum = 0;
	if (max == sqrt(n)) {
		sum++;
		max--;
	}
	for (int i = min; i <= max; i++) {
		if (n % i ==0)
		{
			//cout << i << "," << n / i << ",";
			sum += 2;
		}
	}
	return sum;
}



int num;
void su_analysising_sign(int x)
{
	freopen("CON","w",stdout);
	//system("cls");
		cout<<"su-analsising..."<<endl;
		cout<<x<<"/2000000000"<<endl;
//		_sleep(1500);
	freopen("dabiaocache.txt","a+",stdout);
}
void ans_analysising_sign(int x)
{
	freopen("CON","w",stdout);
//	system("cls");
		cout<<"ans-analsising..."<<endl;
		cout<<x<<"/2000000000"<<endl;
		
	freopen("dabiao.txt","a+",stdout);
}
void ans_analysising_sign_found()
{
	freopen("CON","w",stdout);

	
		cout<<"founded!"<<endl;
	freopen("dabiao.txt","a+",stdout);
}
int main()
{
	cacheanalyser();
	freopen("dabiao.txt","w",stdout);
	freopen("dabiaocache.txt","a+",stdout);
	for (int i=num1+1;i<=2000000000;i++)
	{
		su_analysising_sign(i);
		su[i]=PrimeFactorization2(i);
		cout<<su[i]<<" ";
	}
	_sleep(1000);
	freopen("CON","w",stdout);
	system("cls");
		cout<<"answer_analsys...";
		_sleep(1000);
	freopen("dabiao.txt","a+",stdout);
	for (int i=1;i<=2000000000;i++)
	{
		ans_analysising_sign(i);
		bool find=true;
		int k=0;
		while (find&&k<i)
		{
			if (su[k]<su[i]) k++;
			else find=false; 
		}
		if (k==i&&find)
		{
			ans_analysising_sign_found();
			num++;
			cout<<i<<",";
		}
	}
	freopen("CON","w",stdout);
	//system("cls");
	cout<<"finished!"<<endl<<"number:"<<num<<endl;
	return 0;
}
