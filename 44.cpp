#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl '\n'
using namespace std;


int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,n,m;cin>>t;
    while(t--){
        queue<int> x,y,layer;
        char arr[maxn][maxn];
        bool vis[maxn][maxn];
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
                vis[i][j]=false;
                if(arr[i][j]=='K'){
                    x.push(i);
                    y.push(j);
                    layer.push(0);
                    vis[i][j]=true;
                }
            }
        }
        int ans=-1;
        while(!x.empty()&&ans==-1){
            for(int i=0;i<4;i++){
                int curx=x.front()+dx[i],cury=y.front()+dy[i];
                //cout<<prex<<prey;
                if(curx>=0 && curx<n && cury>=0 && cury<m && arr[curx][cury]=='.' && !vis[curx][cury]){
                    x.push(curx);
                    y.push(cury);
                    layer.push(layer.front()+1);
                    vis[curx][cury]=true;
                }else if(arr[curx][cury]=='@'){
                    ans=layer.front()+1;
                }
            }
            x.pop();
            y.pop();
            layer.pop();
        }
        if(ans==-1){
            cout<<"= =\"";
        }else{
            cout<<ans<<endl;
        }
    }
}
