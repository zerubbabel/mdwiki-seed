/*Best Cow Line 
POJ - 3617
USACO 2007 November Silver
sol:greedy
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int n;
	string s="";
	cin>>n;
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
		s+=t;
	}
	int i=0,j=n-1,c=0;
	while(i<=j){
		bool left=true;
		for(int k=i;k<=j;k++){
			if(s[k]<s[j+i-k]){
				break;	
			}
			else if(s[k]>s[j+i-k]){
				left=false;
				break;
			}
		}
		if (left){
			cout<<s[i++];
		}
		else{
			cout<<s[j--];
		}
		c++;
		if (c % 80==0) cout<<endl;
	}	
	return 0;
}