#include<bits/stdc++.h>
#define reg register int
using namespace std;
int fish[105];
int lowbe[105];
int n;
int main()
{
	cin>>n;
	for (reg i=1;i<=n;i++)
	{
		cin>>fish[i];
	
	}
	//���ȿ��ǣ������޳�֮�����ϣ�����������
	for (reg i=2;i<=n;i++)
	{
		for (reg j=i;j>=1;j--)
		{
			if (fish[j]<fish[i])
			{
				lowbe[i]++;
			}
		}
	} 
	for (reg i=1;i<=n;i++) cout<<lowbe[i]<<" ";
	return 0;
}
