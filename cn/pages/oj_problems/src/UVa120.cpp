/*
	UVa120
*/
#include <iostream>
#include <string>
using namespace std;

int n,a[31];
void print_a(int n){
	for(int i=0;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void flip(int k){
	for (int i=0;i<=k / 2;i++){
		int t=a[i];
		a[i]=a[k-i];
		a[k-i]=t;
	}
	cout<<n-k+1<<" ";
}
int main()
{
	string s;
	while(getline(cin,s)){
		int v=0;
		n=0;
		for(int i=0;i<s.size();i++){
			if(s[i]>='0'&&s[i]<='9'){
				v=v*10+(s[i]-'0');
			}else{				
				if (v) {a[n++]=v;}//去空格
				v=0;
			}	
		}
		if (v) {a[n]=v;}//去空格
		print_a(n);
		//选择排序的方法
		for(int i=n;i>0;i--){
			int k=i;
			for(int j=i-1;j>=0;j--){
				if (a[k]<a[j]){ k=j;}
			}
			if (k!=i){
				if (k!=0) {flip(k);}
				flip(i);
			}
		}
		cout<<0<<endl;
	}
	return 0;
}