/*
Saruman's Army
poj3069
sol:greedy
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX_N=1001;
int x[MAX_N];
int main(){
	int n,r;
	while(cin>>r>>n)
	{
		if(n==-1 && r==-1) break;
		int ans=0;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		sort(x,x+n);
		int left=0;//最左边需要覆盖的点的下标
		while (left<n){
			int i=left;//找到最右边能够覆盖left的点
			while(i<n&&x[i]-x[left]<=r){
				i++;
			}
			ans++;
			i--;
			//更新最左边需要覆盖的点的下标
			left=i;
			while(left<n&&x[left]-x[i]<=r){
				left++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
