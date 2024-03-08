#include <bits/stdc++.h>
#include <queue>

#define endl '\n'
using namespace std;
#define ll long long

int main(){
	queue<ll> q;
	ll n,m,p;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		if(m==1){
			cin>>p;
			q.push(p);
		}else if(m==2 && q.size()){
			cout<<q.front();
			if(i<n){
				cout<<endl;
			}
			q.pop();
		}else{
			cout<<"empty!";
			if(i<n){
				cout<<endl;
			}
		}
	}
}
