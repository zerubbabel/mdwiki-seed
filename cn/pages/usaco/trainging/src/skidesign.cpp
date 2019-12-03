/*
ID: imate811 
TASK: skidesign
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
	int n;
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>a[i];
	} 
	sort(a,a+n);
	int ans=(a[n-1]-a[0])*(a[n-1]-a[0])*n; 
	for(int i=a[0];i<=a[n-1]-17;i++){//枚举最低的山峰 
		//计算最低山峰为i时的花费 
		int cost=0,low=i,high=i+17;
		for(int j=0;j<n;j++){
			if(a[j]>high||a[j]<low){
				int d=min(abs(a[j]-high),abs(low-a[j]));
				cost+=d*d;
			}
		}	
		ans=min(ans,cost);
	}
	fout<<ans << endl;	
	return 0;
}