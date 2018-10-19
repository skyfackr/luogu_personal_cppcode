#include<bits/stdc++.h>
using namespace std;
int i1,i2,i3,i4,i5,i6,i7,i8,i9;
int jj1,jj2,jj3;
ofstream f;
int main()
{
	f.open("ans.txt",ios::out);
	for (i1=1;i1<=9;i1++)
		for (i2=1;i2<=9;i2++)
			for (i3=1;i3<=9;i3++)
				for (i4=1;i4<=9;i4++)
					for (i5=1;i5<=9;i5++)
						for (i6=1;i6<=9;i6++)
							for (i7=1;i7<=9;i7++)
								for (i8=1;i8<=9;i8++)
									for (i9=1;i9<=9;i9++)
									{
										if (i1!=i2&&i1!=i3&&i1!=i4&&i1!=i5&&i1!=i6&&i1!=i7&&i1!=i8&&i1!=i9&&i2!=i3&&i2!=i4&&i2!=i5&&i2!=i6&&i2!=i7&&i2!=i8&&i2!=i9&&i3!=i4&&i3!=i5&&i3!=i6&&i3!=i7&&i3!=i8&&i3!=i9&&i4!=i5&&i4!=i6&&i4!=i7&&i4!=i8&&i4!=i9&&i5!=i6&&i5!=i7&&i5!=i8&&i5!=i9&&i6!=i7&&i6!=i8&&i6!=i9&&i7!=i8&&i7!=i9&&i8!=i9)
										{
											jj1=i1*100+i2*10+i3;
											jj2=i4*100+i5*10+i6;
											jj3=i7*100+i8*10+i9;
											if (jj1*6==jj2*3&&jj2*3==jj3*2)
											{
												f<<jj1<<" "<<jj2<<" "<<jj3<<endl;
											}
										}
									}
	f.close();
	return 0;
}
