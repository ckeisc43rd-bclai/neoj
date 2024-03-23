#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int color[maxn];
bool vis[maxn];
vector<int> v[maxn];
bool dfs(int x,int paint){
    int ok=1;
    vis[x]=1;
    color[x]=paint;
    for(auto i : v[x]){
        if(!vis[i]) ok&=dfs(i,!paint);
        else if(color[i]==color[x]) return 0;
    }
    return ok;
}
int main(){
    int t,n,m,a,b;
    cin>>t;
    while(t--){
        memset(color,-1,sizeof(color));
        memset(vis,0,sizeof(vis));
        cin>>n>>m;
        for(int i=0;i<n;i++) v[i].clear();
        while(m--){
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        bool ok=1;
        for(int i=0;i<n;i++){
            if(color[i]==-1) {
                if(!dfs(i,0)) {
                    ok=0;
                    break;
                }
            }
        }
        if(ok) cout<<"NORMAL."<<'\n';
        else cout<<"RAINBOW."<<'\n';
    }
}