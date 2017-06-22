/*
	POJ1182
	并查集
*/
#include <iostream>
#include <stdio.h>
const int MAXN=50005;
int n,k,a[MAXN*3];
int find(int x){
	while(x!=a[x]){
		x=a[x];
	}
	return x;
}
bool same(int x,int y){
	return find(x)==find(y);
}
void unite(int x,int y){
	int p=find(x);
	int q=find(y);
	if (p!=q){
		a[q]=p;
	}
}
int main(){
	int d,x,y,ans=0;
	scanf("%d%d",&n,&k);
	//i,i+n,i+2*n代表i-A,i-B,i-C
	for(int i=1;i<=n*3;i++){
		a[i]=i;
	}
	for(int i=0;i<k;i++){
		scanf("%d%d%d",&d,&x,&y);
		if(x<1||x>n||y<1||y>n){
			ans++;
			continue;
		}
		if (d==1){//x,y同类则合并x-A,y-A,x-B,y-B,x-C,y-C,但需先判断	x-A与y-B,y-C不同组
		
			if (same(x,y+n)||same(x,y+2*n)){
				ans++;
			}
			else{
				unite(x,y);
				unite(x+n,y+n);
				unite(x+2*n,y+2*n);
			}
		}
		else{
			if (same(x,y)||same(x,y+2*n)){
				ans++;
			}
			else{
				unite(x+2*n,y);
				unite(x,y+n);
				unite(x+n,y+2*n);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}