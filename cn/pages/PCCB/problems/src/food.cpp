/*
食物链
poj1182
sol:并查集
算法：
*/
#include <iostream>
#include <cstdio>
using namespace std;
const int MAX_N=150002;
int a[MAX_N],h[MAX_N];

int find(int x){
	if (x==a[x]){
		return x;
	}else{
		return a[x]=find(a[x]);
	}
}
int unite(int x,int y){
	int px=find(x);
	int py=find(y);
	if (px==py) return 0;
	if (h[px]<h[py]){
		a[px]=py;		
	}else{
		a[py]=px;
		if(h[px]==h[py]){
			h[px]++;
		}
	}
	return 0;
}

bool same(int x,int y){
	return find(x)==find(y);
}
int main(){
	int n,k,d,x,y,ans=0;
	cin>>n>>k;
	for(int i=1;i<3*n+1;i++){
		a[i]=i;
		h[i]=0;
	}
	for(int i=0;i<k;i++){
		//cin>>d>>x>>y;
		scanf("%d%d%d",&d,&x,&y);//cin太慢了，改成cin居然超时
		if(x>n||y>n){
			ans++;
			continue;
		}
		if(d==1){
			if(same(x,y+n)||same(x,y+2*n)){
				ans++;
				continue;
			}else{
				unite(x,y);
				unite(x+n,y+n);
				unite(x+2*n,y+2*n);
			}
		}else{
			if(same(x,y)||same(x,y+2*n)){
				ans++;
				continue;
			}else{
				unite(x,y+n);
				unite(x+n,y+2*n);
				unite(x+2*n,y);
			}
		}
	}
	cout<<ans;
	return 0;
}
