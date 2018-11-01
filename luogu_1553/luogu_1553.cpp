#include<bits/stdc++.h>
#define regi register int
using namespace std;
stack<int> s;
queue<int> point;
string in;
void outint(stack<int> &s)
{
//	cout<<s.size()<<endl;
	while (s.size()>1&&s.top()=='0') s.pop();
//	cout<<s.size()<<endl;
	while (!s.empty())
	{
		cout<<s.top()-'0';
		s.pop();
	}
	return;
}
void outpoint(queue<int> &q)
{
	stack<int> s;
//	cout<<endl<<q.size()<<endl;
	
	while (q.size()>1&&q.front()=='0') q.pop();
//	cout<<q.size()<<endl;
	while (!q.empty())
	{
		s.push(q.front());
		q.pop();
	}
	while (!s.empty())
	{
		cout<<s.top()-'0';
//		_sleep(1000);
		s.pop();
	}
	return;
}
int main()
{
	cin>>in;
	int now=0;
	while (now<=in.size()-1)
	{
		if (in[now]=='.')
		{
			outint(s);
			cout<<'.';
			now++;
			while (now<=in.size()-1)
			{
				point.push(in[now]);
				now++;
			}
			outpoint(point);
			return 0;
		}
		if (in[now]=='/')
		{
			outint(s);
			now++;
			cout<<'/';
			continue;
		}
		if (in[now]=='%')
		{
			outint(s);
			cout<<'%';
			break;
		}
		s.push(in[now]);
		now++;
	}
	if (in[(in.size()-1)]!='%') outint(s);
	return 0;
}
