/*
The Dragon of Loowater
UVa11292
sol:排序，按顺序取

*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N=20001;
int c[MAX_N],x[MAX_N];
int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0&&m==0){
			break;
		}
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=0;i<m;i++){
			cin>>c[i];
		}
		sort(x,x+n);
		sort(c,c+m);
		int j=0,ans=0;
		bool f=true;
		for (int i = 0; i < n; ++i)//依次枚举恶龙
		{			
			while(j<m&x[i]>c[j]){//找到第一个满足条件的骑士就ok
				j++;
			}
			if(j!=m){
				ans+=c[j];
				j++;
			}else{
				f=false;
				break;
			}			
		}
		if (f){
			cout<<ans<<endl;
		}else{
			cout<<"Loowater is doomed!"<<endl;
		}
	}
	return 0;
}
