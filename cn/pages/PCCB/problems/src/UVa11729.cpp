/*
The Dragon of Loowater
UVa11292
sol:贪心，排序，执行时间长的在前

*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
const int MAX_N=1001;
P x[MAX_N];
bool cmp(P x,P y){
	return x.first>y.first;
}
int main(){
	int n,c=0;
	while(cin>>n&&n){
		c++;
		for(int i=0;i<n;i++){
			cin>>x[i].second>>x[i].first;
		}
		sort(x,x+n,cmp);
		int ans=0,s=0;
		for(int i=0;i<n;i++){
			s+=x[i].second;//waiting time
			ans=max(ans,s+x[i].first);
		}
		cout<<"Case "<<c<<": "<<ans<<endl;
	}
	return 0;
}