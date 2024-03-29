#include<bits/stdc++.h>
#define d long double
using namespace std;
d a[15],b[15],c[15];
int t,n;
d check(double x){
    d ans=-1;
    for(int i=0;i<n;i++) ans=max(ans,a[i]*((x-b[i])*(x-b[i]))+c[i]);
    return ans;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
        d l=0.000000,r=300.0000000;
        int cnt=10007;
        while(cnt--){
            d ml=(l*2+r)/3, mr=(l+r*2)/3;
            if(check(mr)>check(ml)) r=mr;
            else l=ml;
        }
        printf("%LF\n",check((l+r)/2));
    }
}