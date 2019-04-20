/*头像上传*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gou1 "Too Young"
#define gou2 "Too Simple"
#define gou3 "Sometimes Naive"
int n,l,g;
void preanalyse(int &w,int &h)
{
    //int maxbian=max(w,h);
    while (max(w,h)>g)
    {
        w/=2;
        h/=2;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>l>>g;
    while (n)
    {
        n--;
        int w,h;
        cin>>w>>h;
        preanalyse(w,h);
        if (w<l||h<l)
        {
            cout<<gou1<<endl;
            continue;
        }
        if (w!=h)
        {
            cout<<gou2<<endl;
            continue;
        }
        cout<<gou3<<endl;
    }
    return 0;
}