# Lake Counting (POJ No.2386 USACO 2004 November)

[Lake Counting](https://vjudge.net/problem/POJ-2386)

Due to recent rains, water has pooled in various places in Farmer John's field, which is represented by a rectangle of N x M (1 <= N <= 100; 1 <= M <= 100) squares. Each square contains either water ('W') or dry land ('.'). Farmer John would like to figure out how many ponds have formed in his field. A pond is a connected set of squares with water in them, where a square is considered adjacent to all eight of its neighbors. 

Given a diagram of Farmer John's field, determine how many ponds he has.

# Input

* Line 1: Two space-separated integers: N and M 

* Lines 2..N+1: M characters per line representing one row of Farmer John's field. Each character is either 'W' or '.'. The characters do not have spaces between them.

# Output

* Line 1: The number of ponds in Farmer John's field.

# Sample Input

10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

#Sample Output

3

# Hint

OUTPUT DETAILS: 

There are three ponds: one in the upper left, one in the lower left,and one along the right side.

# 水洼
[问题描述]
有一个大小为M*N的园子，雨后积起了水。Tom想要数一数园子里共有多少个水洼。把连通的积水认为是连接在一起的同一个水洼。请帮忙计算园子里共有多少个水洼。(八连通是指下图中相对W的8个*部分)
***
*W*
***
[样例输入]
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
[样例输出]
3
[数据范围]
(1 <= N <= 100; 1 <= M <= 100)

------
# solve
DFS

#src
```c++
	#include <cstdio>
	#include <string>
	#include <iostream>
	using namespace std;

	const int MAXN=100;

	int a[MAXN+1][MAXN+1];
	int n,m;
	int dfs(int x,int y){
		a[x][y]=0;
		for(int i=-1;i<2;i++){
			for(int j=-1;j<2;j++){
				int x1=x+i;
				int y1=y+j;
				if(0<=x1&&x1<n&&0<=y1&&y1<m&&a[x1][y1]) dfs(x1,y1);
			}
		}
		return 0;
	}
	int main(){
		int ans=0;
		cin>>n>>m;
		for (int i=0;i<n;i++){
			string s;
			cin>>s;
			for(int j=0;j<m;j++){
				if (s[j]=='W') a[i][j]=1;
			}
		}	
		for (int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if (a[i][j]) {
					dfs(i,j);
					ans++;
				}	
			}
		}
		cout<<ans;
	}
```