#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define ff first
#define ss second
#define maxn 1005
using namespace std;


int h,w;
char grid[maxn][maxn];
bool vis[maxn][maxn];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
queue<int> qx,qy;

void dfs(int y,int x){
    vis[y][x]=1;
    //stack<int> s;
    for(int k=0;k<4;k++){
        if((y+dy[k])>=1 && (y+dy[k])<=h && (x+dx[k])>=1 && (x+dx[k])<=w){
            if(grid[y+dy[k]][x+dx[k]]=='.' && !vis[y+dy[k]][x+dx[k]]){
                dfs((y+dy[k]),(x+dx[k]));
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>h>>w;
        char c;
        int cnt=0;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin>>c;
                grid[i][j]=c;
                vis[i][j]=0;
            }
        }
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(grid[i][j]=='.' && !vis[i][j]){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}