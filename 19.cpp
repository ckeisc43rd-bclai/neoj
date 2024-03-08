#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main(){
    int n,m,p;
    cin>>n;
    while(n--){
        cin>>m;
        stack<int> s;
        queue<int> q;
        for(int i=1;i<=m;i++){
            cin>>p;
            q.push(p);
        }
        for(int i=1;i<=m;i++){
            s.push(i);
            while(!s.empty() && !q.empty() && q.front()==s.top()){
                q.pop();
                s.pop();
            }
        }
        if(s.empty() && q.empty()){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}