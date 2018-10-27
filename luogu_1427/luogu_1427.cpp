#include<bits/stdc++.h>
using namespace std;
vector<int> a;int i;
int main()
{
	while(cin>>i) a.push_back(i);
	for (int j=a.size()-2;j>=0;j--) cout<<a[j]<<" ";
	return 0;
}
