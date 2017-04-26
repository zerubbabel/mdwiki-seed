/*
	UVa120 std
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
using namespace std;
int n,a[31];
void flip(int p){
	for (int i=0;i<p-i;i++){
		swap(a[i],a[p-i]);
	}
	cout<<n-p<<" ";
}
int main()
{
	string s;
	while(getline(cin,s)){
		cout<<s<<endl;
		stringstream ss(s);
		n=0;
		while (ss>>a[n]){
			n++;
		}
		//选择排序的方法
		for(int i=n-1;i>0;i--){
			int p=max_element(a,a+i+1)-a;
			if(p==i) continue;
			if(p>0) flip(p);
			flip(i);
		}
		cout<<0<<endl;
	}
	return 0;
}