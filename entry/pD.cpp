#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define ll long long

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int n,count=0;cin>>n;
    vector<vector<char>> v(n,vector<char> (n));
    vector<pair<int,int>> ans;
    int now,dx,dy;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    int m;cin>>m;
    vector<char> f(m);
    for(int i=0;i<m;i++){
        cin>>f[i];
    }
    int cur=1,x,y;
    //cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==f[0]){
                y=i;x=j;
                now=1;dx=-1;dy=-1;cur=1;
                while(cur<m){
                    for(int k=0;k<now;k++){
                        x+=dx;
                        //cout<<x<<y<<endl;
                        //cout<<cur<<endl;
                        if(x<0 || x>=n){
                            //cout<<"out of x index"<<endl;
                            goto label;
                        }else if(v[y][x]!=f[cur]){
                            //cout<<"wrong feature"<<endl;
                            goto label;
                        }
                        cur++;
                        if(cur>=m){
                            //cout<<"out of feature"<<endl;
                            goto good;
                        }
                    }
                    dx*=-1;
                    for(int k=0;k<now;k++){
                        y+=dy;
                        //cout<<x<<y<<endl;
                        //cout<<cur<<endl;
                        if(y<0 || y>=n){
                            //cout<<"out of y index"<<endl;
                            goto label;
                        }else if(v[y][x]!=f[cur]){
                            //cout<<"wrong feature"<<endl;
                            goto label;
                        }
                        cur++;
                        if(cur>=m){
                            //cout<<"out of feature"<<endl;
                            goto good;
                        }
                    }
                    dy*=-1;
                    now++;
                }
                good: count++;
                ans.push_back(make_pair(i+1,j+1));
                //cout<<j<<' '<<i;
            }
            label: int z;
        }
    }
    cout<<count<<endl;
    for(int i=0;i<count;i++){
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    }
}