/*
	资源分配类DP
	![洛谷P1280 尼克的任务](https://www.luogu.org/problem/show?pid=1280)
*/
#include<iostream>
using namespace std;
const int M=10005;
int f[M],P[M],T[M];
int n,k;
void _init(){
	cin>>n>>k;
	for(int i=0;i<k;i++){
		cin>>P[i]>>T[i];
	}
}
void _solve(){
	int j=k-1;
	for(int i=n;i;i--){
		if (P[j]!=i){
			f[i]=f[i+1]+1;
		}
		else{
			while(P[j]==i){
				f[i]=max(f[i],f[i+T[j]]);
				j--;	
			}
		}
	}
}
int main()
{
	_init();
	_solve();
	cout<<f[1];
	return 0;
}