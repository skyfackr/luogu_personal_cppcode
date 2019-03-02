/*洛咕三月月赛T1整数校验器*/
/*https://www.luogu.org/contestnew/show/14994*/
#include<bits/stdc++.h>
using namespace std;
#define regi register int
#define regl register long long
#define ll long long
#define vaildnum 0//合法
#define invaildnum_invaildtype 1//格式不合法
#define invaildnum_override 2//数字越界
ll l,r;
string ls,rs;
bool ls_minus=false,rs_minus=false;
int t;
bool isinminus=true,isinplus=true;
void getlrline()//lr转化，我知道名字不对，因为我懒得改了
{
    ostringstream ossl,ossr;
    ossl<<l;
    ossr<<r;
    ls=ossl.str();
    rs=ossr.str();
    if (l<0) ls_minus=true;
    if (r<0) rs_minus=true;
    return;
}
bool typetest(string s)//格式测试
{
    if (s[0]=='0'&&s.size()==1) return true;
    int testnum=0;
    if (s[0]=='-') testnum++;
    if (s[testnum]=='0') return false;
    return true;
}
void spj_0()//lr全是0的特判
{
    while (t)
    {
        t--;
        string s;
        getline(cin,s);
        if (!typetest(s))
        {
            cout<<invaildnum_invaildtype<<endl;
            continue;
        }
        if (s[0]=='0'&&s.size()==1)
        {
            cout<<vaildnum<<endl;
        }
        else
        {
            cout<<invaildnum_override<<endl;
        }
    }
    return;
}
int ridetest(string s,string x)//对于同样长度的数字的测试，1为大，2为小，0为一样
{
    bool s_minus=false,x_minus=false;
    if (s[0]=='-') s_minus=true;
    if (x[0]=='-') x_minus=true;
    if (s_minus&&!x_minus) return 2;
    if (!s_minus&&x_minus) return 1;
    ll nowtest=0,testsize=s.size()-1;
    if (s_minus) nowtest++;
    while (nowtest<=testsize)
    {
        if (s[nowtest]>x[nowtest]) return 1;
        if (s[nowtest]<x[nowtest]) return 2;
        nowtest++;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>l>>r>>t;
    getlrline();
    if (l==0&&r==0) 
    {
        spj_0();
        return 0;
    }
    if (r<=0) isinplus=false;
    if (l>=0) isinminus=false;
//    cin.clear();
    {
        string s;
        getline(cin,s);
    }
    while (t)
    {
        t--;
        string s;
        getline(cin,s);
        if (!typetest(s))
        {
            cout<<invaildnum_invaildtype<<endl;
            continue;
        }
        bool isminus=false;
        if (s[0]=='-') isminus=true;
        if ((!isminus&&!isinplus)||(isminus&&!isinminus))
        {
            cout<<invaildnum_override<<endl;
            continue;
        }
        ll ssize=s.size();
        if (isminus) ssize--;
        ll lssize=ls.size(),rssize=rs.size();
        if (ls_minus) lssize--;
        if (rs_minus) rssize--;
        if (((isinplus&&isinminus)&&(ssize>lssize||ssize>rssize))||((!isinminus)&&(ssize<lssize||ssize>rssize))||((!isinplus)&&(ssize>lssize||ssize<rssize)))
        {
            cout<<invaildnum_override<<endl;
            continue;
        }
        int lsride=0,rsride=0;
        if (ssize==lssize) lsride=ridetest(s,ls);
        if (ssize==rssize) rsride=ridetest(s,rs);
        if ((lsride==2)||(rsride==1))
        {
            cout<<invaildnum_override<<endl;
            continue;
        }
        cout<<vaildnum<<endl;
    }
    return 0;
}