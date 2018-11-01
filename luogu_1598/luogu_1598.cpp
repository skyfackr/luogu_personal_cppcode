#include<bits/stdc++.h>
#define regi register int
using namespace std;
int zm[26];
int line,tu[26][401];
inline void getnum(char ch)
{
	if (ch>='A'&&ch<='Z') zm[ch-'A']++;
	line=max(line,zm[ch-'A']);
	return ;
}
string in;
char out[2]={' ','*'};
int main()
{
	for (regi i=1;i<=4;i++)
	{
		in.clear();
		getline(cin,in);
		for (regi j=0;j<=in.size()-1;j++) getnum(in[j]);
	}
	for (regi i=0;i<=25;i++)
	{
		for (regi j=1;j<=zm[i];j++) tu[i][j]=1;
	}
	for (regi i=line;i>=1;i--)
	{
		for (regi j=0;j<=24;j++)
		{
			cout<<out[tu[j][i]]<<" ";
			//cout<<tu[j][i]<<" ";
		}
		//cout<<tu[25][i]<<endl;
		cout<<out[tu[25][i]]<<endl;
	}
	cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl;
	//for (regi i=0;i<=25;i++) cout<<zm[i]<<" ";
	//cout<<endl<<line<<endl;
	return 0;
}
