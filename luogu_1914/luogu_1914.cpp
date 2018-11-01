#include<bits/stdc++.h>
using namespace std;
int n;
char ch;
int main()
{
    cin>>n;
    n%=26;
    while (cin>>ch) 
    {
        int cch=ch;
		cch+=n;
        while (cch>'z'||cch<0) cch-=26;
        cout<<(char)cch;
    }
    return 0;
}
