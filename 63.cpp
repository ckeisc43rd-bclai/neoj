#include<bits/stdc++.h>
using namespace std;
int arr[105],ans[105];
int t,n;
void dfs(int ansid,int arrid){
    if(arrid>n) return;         // bug
    if(ansid==6){
        for(int i=0;i<5;i++)cout<<ans[i]<<' ';
        cout<<ans[5]<<'\n';
        return;
    }
    ans[ansid]=arr[arrid];
    dfs(ansid+1,arrid+1);
    dfs(ansid,arrid+1);
    
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        dfs(0,0);
    }
}