//an=(2n)^k+n
//an mod m=b mod m
//(2n)^k+n  mod m=b mod m
//(2n>^k mod m=b mod m-n
//( (2n)^k- (b mod m -n) ) mod m=0
//���� (2n)^k- (b mod m -n) ������m����
//����4-6������
// ( (2n)^k+n-b ) ��������m
//��� (2n)^k+n mod m=0�������2�� 
//����k=1�����
//ûʱ��������һ���ҵ��뷨�Բ��ԡ������� 
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
