#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define MAXN 1e5+7
using namespace std;

vector<vector<int>> v(MAXN,vector<int> ());
vector<bool> visited(MAXN,false);
vector<int> maxnodes(MAXN,0);
int dfs(int n){
    visited[n]=1;
    int maxdepth=0;
    while(!v[n].empty()){
        for(auto &i:v[n]){
            if(!visited[i]){
                maxdepth+=dfs(i);
            }
        }
    }
    return maxdepth+1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n,ans=0,x,y;cin>>n;
        for(int j=1;j<n;j++){
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        cout<<1;
        for(int j=0;j<n;j++){
            for(auto &&it:visited){
                it=0;
            }
            for(auto &it:v[j]){
                int nodes=dfs(it);
                maxnodes[j]=nodes>maxnodes[j]?nodes:maxnodes[j];
            }
        }
        for(int j=0;j<n;j++){
            if(maxnodes[j]>maxnodes[ans]){
                ans=j;
            }
        }
        cout<<ans<<endl;
    }

}