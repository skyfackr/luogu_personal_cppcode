#include<bits/stdc++.h>
#define died "-TEAMCLOSED-"
#define maxn 1000000
//#define DEBUGON
using namespace std;
char s[maxn];
char fi[maxn];
#include<climits>
int minn=INT_MAX;
inline int zhcn()
{
	wchar_t x;
	return sizeof(x); 
}
#define regi register int
#ifdef DEBUGON
inline void minout()
{
	cout<<minn<<endl;
	return ;
}
#endif
#ifndef DEBUGON
inline void minout()
{
	return ;
}
#endif
inline bool findn(char f[],int now,int size,int nows)
{
	if (f[now]!=s[nows]) return false;
	if (now==size-1) return true;
	return findn(f,now+1,size,nows+1);
}
int ssize=0;
	int fisize=0;
inline int got(char fi[])
{
//	int l1=fi.size();
//	int l2=s.size();


	for (regi i=0;i<=ssize-fisize;i++)
		if (fi[0]==s[i])
			if (findn(fi,1,fisize,i+1)) return i;
	return INT_MAX;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
/*	f1[0]='Ó¢',f1[1]='Ã÷',f1[2]='Éñ',f1[3]='Îä',f1[4]='µÄ',f1[5]='ÐÜ';
	f3[0]='Å¾',f3[1]='Å¾',f3[2]='ÑÕ';*/
	cin>>fisize>>ssize;
	fisize*=zhcn();ssize*=zhcn();
	for (regi i=1;i<=fisize;i++) cin>>fi[i-1];
	for (regi i=1;i<=ssize;i++) cin>>s[i-1];
	fisize--;ssize--;
	minout();
/*	if (s.find( "667")!=string::npos)
	{
		cout<<"a"<<endl;
		return 0;
	}*/
	minn=min(minn,got(fi));
//	minout();
//	if (s.find(f2)!=string::npos) minn=min(minn,(int)s.find(f2));
//	minout();
//	minn=min(minn,got(f3));
	minout();
	if (minn==INT_MAX) cout<<died<<endl;
	else cout<<(minn/zhcn())+1<<endl;
	return 0;
}
