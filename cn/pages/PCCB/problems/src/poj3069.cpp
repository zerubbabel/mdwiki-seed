#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX_N=1001;
int x[MAX_N];
int main(){
	int n,r;
	cin>>n>>r;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	sort(x,x+n);
	int i=0;
	while (i<n){
		int k=i;
		while(k<n&&x[k]-x[i]<=r){
			k++;
		}
		
	}
	return 0;
}
