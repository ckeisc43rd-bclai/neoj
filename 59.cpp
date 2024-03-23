#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    priority_queue<int,vector<int>,greater<int>> q;
    int t;cin>>t;int a,b;
    while(t--){
        cin>>a;
        if(a==1){
            cin>>b;
            q.push(b);
        }else if(q.empty()){
            cout<<"empty!\n";
        }else{
            cout<<q.top()<<endl;
            q.pop();
        }
    }

}