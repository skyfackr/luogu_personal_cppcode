#include<bits/stdc++.h>
using namespace std;
char isbn[14];
char ch;
int sbm,resbm;
int main()
{
	for (int i=1;i<=12;i++)
	{
		cin>>ch;
		isbn[i]=ch;
	}
	cin>>ch;
	if (ch=='X') sbm=10;
	else sbm=ch-'0';
	resbm=((isbn[1]-'0')*1+(isbn[3]-'0')*2+(isbn[4]-'0')*3+(isbn[5]-'0')*4+(isbn[7]-'0')*5+(isbn[8]-'0')*6+(isbn[9]-'0')*7+(isbn[10]-'0')*8+(isbn[11]-'0')*9)%11;
	if (resbm==sbm)
		cout<<"Right"<<endl;
	else 
	{
		for (int i=1;i<=12;i++) cout<<isbn[i];
		if (resbm==10) cout<<"X";
		else cout<<resbm;
	}
	return 0;
}
