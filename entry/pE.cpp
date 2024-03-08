#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,ans;double a,b,aver,total,max=0;
    cin>>n>>a>>b;
    vector<double> v(n+1);
    vector<double> t(n+1);
    vector<double> avg(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        t[i]=v[i]+t[i-1];
        avg[i]=t[i]/(2*a+i*b);
        //cout<<avg[i]<<' ';
        if(avg[i]>max){
            max=avg[i];
            ans=i;
        }
    }
    cout<<1<<" "<<ans;
}