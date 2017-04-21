#include <iostream>
#include <string.h>
using namespace std;
int a[10];
int main(){
	memset(a,1,sizeof(a));
	for(int i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
	
	return 0;
}
