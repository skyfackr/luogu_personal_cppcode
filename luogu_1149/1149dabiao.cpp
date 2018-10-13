#include<bits/stdc++.h>
using namespace std;
int main()
{
        int a[2001]={6},b,c[10]={6,2,5,5,4,5,6,3,7,6},s=0,i,j,k;
        cout<<"time:25"<<endl<<"0-24"<<endl;
        freopen("dabiao.txt","w",stdout);
      
        for(i=1;i<=2000;i++)
        {
                j=i;
                while(j>=1)//求每个数所用的火柴棒
                {
                        a[i]=a[i]+c[j%10];
                        j=j/10;
                }
        }
          for (k=0;k<=24;k++)
    {
        
		b=k;
		s=0;
        for(i=0;i<=1000;i++)
        {
                for(j=0;j<=1000;j++)
                if(a[i]+a[j]+a[i+j]+4==b)s++;//还有加号与等号
        }
        freopen("dabiao.txt","a+",stdout);
        cout<<s<<",";
        freopen("CON","w",stdout);
        cout<<"finished:"<<k<<endl;
   	}
        return 0;
}
