# Fence Repair

[Fence Repair](https://vjudge.net/problem/POJ-3253)



# src
```c++
	/*
	Fence Repair
	poj3253 
	sol:greedy,huffman code
	*/
	#include <iostream>
	#include <algorithm>
	#include <string>
	using namespace std;
	const int MAX_N=20001;
	int L[MAX_N];
	//插入排序t为待插入数据,原数据[l,r)插入后数据[l-1,r)
	int insert(int t,int l,int r){
		int i=l;
		while(i<r&&t>L[i]){
			L[i-1]=L[i];
			i++;
		}
		L[--i]=t;
		return 0;
	}
	int main(){
		int n;
		long long ans=0;//注意数据大小
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>L[i];
		}
		sort(L,L+n);
		for(int i=0;i<n-1;i++){
			int t=L[i]+L[i+1];//合并后大小
			ans=ans+t;
			insert(t,i+2,n);//插入到合适位置
		}
		cout<<ans;
		return 0;
	}
```
