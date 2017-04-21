/*
Lake Counting 
(POJ No.2386 USACO 2004 November)
sol:DFS
*/

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