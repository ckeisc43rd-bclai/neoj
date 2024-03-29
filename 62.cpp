#include<bits/stdc++.h>
using namespace std;
int arr[15][15];
bool ok=0;
void print(){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++) cout<<arr[i][j];
    cout<<'\n';
}
int find_next(int r,int c){
    for(int i=r;i<9;i++)
        for(int j=0;j<9;j++)
            if(arr[i][j]==0) return i*9+j;
    return -1;
}
vector<int> put(int r,int c){
    bool ok[10]={1,1,1,1,1,1,1,1,1,1};
    for(int i=0;i<9;i++) if(arr[i][c]!=0) ok[arr[i][c]]=0;          //col
    for(int i=0;i<9;i++) if(arr[r][i]!=0) ok[arr[r][i]]=0;          //row
    
    int boxr=3*(r/3),boxc=3*(c/3);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(arr[boxr+i][boxc+j]!=0) ok[arr[boxr+i][boxc+j]]=0;
        
    vector<int> ans;
    for(int i=1;i<=9;i++) if(ok[i]) ans.push_back(i);
    return ans;
}
void dfs(int r,int c){
    int pos=find_next(r,c),nr,nc;
    if(pos==-1) {
        ok=1;
        return;
    }
    
    vector<int> v=put(r,c);
    
    for(int i=0;i<v.size();i++){
        arr[r][c]=v[i];
        pos=find_next(r,c);
        nr = pos/9; nc = pos%9;
        dfs(nr,nc);
        if(ok) return;
    }
    arr[r][c]=0;
}
void solve(){
    int pos=find_next(0,0);
    int r=pos/9,c=pos%9;
    dfs(r,c);
    
    bool legal=1;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            vector<int> v=put(i,j);
            if(v.size()>0) legal=0;
        }
    }
    
    if(!legal || !ok) cout<<"No solution."<<'\n';
    else print();
}

int main(){
    int t;cin>>t;
    char x;
    while(t--){
        ok=0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin>>x;
                if(x=='.') arr[i][j]=0;
                else arr[i][j]=x-'0';
            }
        }
        solve();
    }
}