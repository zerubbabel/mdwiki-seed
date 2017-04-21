/*
Expedition
poj2431
sol:priority queue
算法：
0.汽车一路向town行驶

1.如果燃料箱为空：如果优先队列为空则无法到达终点，
否则反复取出优先队列里最大的元素，直到油箱里的有足够到达i

2.经过加油站i时，往优先队列里加入Bi

*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N=10002;
typedef pair<int,int> pa;
pa d[MAX_N];
int main(){
	int n,p,L,ans=0;
	cin>>n;
	priority_queue<int> q;
	for(int i=0;i<n;i++){
		cin>>d[i].first>>d[i].second;
	}	
	cin>>L>>p;
	for(int i=0;i<n;i++){
		d[i].first=L-d[i].first;
	}
	sort(d,d+n);
	d[n].first=L;d[n].second=0;
	int oil=p;
	for(int i=0;i<n+1;i++){
		while(oil<d[i].first&&!q.empty()){//如果到位置i油不够并且可加油的优先队列非空就一直选择大的油量加油
			oil+=q.top();
			q.pop();
			ans++;
		}
		if (oil<d[i].first) {//根据前面的原则加油，如果还是无法到达位置i说明无解
			ans=-1;
			break;	
		}
		q.push(d[i].second);
	}
	cout<<ans;
	return 0;
}
