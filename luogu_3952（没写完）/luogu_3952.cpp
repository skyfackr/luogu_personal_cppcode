#include<bits/stdc++.h>
#include<climits>
#define regi register int
#define maxl 102
using namespace std;
string code[maxl];
inline void readcode(int l)
{
	for (regi i=1;i<=l i++)
	{
		getline(cin,code[i]);
	}
}
void readheader(int &l,int &o)
{
	string ss;
	cin>>l>>ss;
	if (ss[3]=='n') 
	{
		int x=5;
		o=0;
		while (ss[x]!=')')
		{
			o=o*10+(int)(ss[x]-'1'+1);
		}
	}
	else o=0;
	return ;
}
inline void clearcode(int l)
{
	for (regi i=1;i<=l;i++) code[i].clear();
	return;
}
inline bool numtest(char ch)
{
	return (ch>='0'||ch<='9')?true:false;
}
int run(int l)
{
	int o1=-1,undo=-1;
	stack<int> xh;
	int bj[27];
	int nowo;
	for (regi i=1;i<=l;i++)
	{
		if (code[i][0]=='F')//create
		{
			int x;
			
			x=code[i][2]-'a'+1;
			if (bj[x]==1) return -1;
			bj[x]=1;
			xh.push(x);
			int i,j;
			if (code[i][4]=='n')
			{
				if (o1==-1) o1=i;
				continue;
			}
			now=5;
			while (numtest(5)) now++;
			now++;
			if (code[i][now]=='n') nowo++;
			else
			{
				if (o1==-1) o1=i;
				continue;
			}
		}
		else if(code[i][0]=='E')
		{
			
		}
	}
}
