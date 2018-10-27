//an=(2n)^k+n
//an mod m=b mod m
//(2n)^k+n  mod m=b mod m
//(2n>^k mod m=b mod m-n
//( (2n)^k- (b mod m -n) ) mod m=0
//所以 (2n)^k- (b mod m -n) 可以与m整除
//以上4-6行作废
// ( (2n)^k+n-b ) 可以整除m
//针对 (2n)^k+n mod m=0情况特判2种 
//特判k=1的情况
//没时间了我试一下我的想法对不对。。。。 
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
	unsigned long long n,m,b;
	cin>>n>>b>>m;
	unsigned long long nn=2*n;
	while (nn<m)
	{
		nn*=n*2;
	}
//	nnn=( nn+n-b )%m;
	if (( nn+n-b )%m==0)
	cout<<"1"<<endl;
	else cout<<"INF"<<endl;
	return 0;
} 
