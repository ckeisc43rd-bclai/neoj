#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

int n,k;const int N =1000000;
ll a[N];
ll b[N];
ll c[N];

bool win(ll day){ //check if train n days can win the enemy
    int enemy=0,sum=0;
    ll cur[N];
    for(int i=0;i<n;i++){
        cur[i]=a[i]+(b[i]*day);
    }
    sort(cur,cur+n);
    for(int i=0;i<n;i++){
        if(cur[i]>c[enemy]){
            sum++;
            enemy++;
        }
    }
    return (sum>=k);//enemy replace sum
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;ll l=-1,r=10000000000;
    cin>>t;
    while(t--){
        l=-1,r=10000000000;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
        }
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        sort(c,c+n);
        if(!win(r)) cout<<-1<<endl;
        else{
            while(r-l!=1){
                int mid=l+(r-l)/2;
                if(win(mid)) r=mid;
                else l=mid;
            }
            cout<<r<<endl;
        }
    }
}