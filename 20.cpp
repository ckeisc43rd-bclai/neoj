#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t,n,k;
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<<"Line #"<<i<<endl;
		cin>>n;
		int arr[1000007]={0},oneinline[1007]={0};
		for(int j=1;j<=n;j++){
			cin>>k;
			for(int p=1;p<=k;p++){
				int temp;
				cin>>temp;
				arr[temp]=j;
			}
		}
		list<int> line;
		list<int>::iterator it[1007];
		int steps;
		cin>>steps;
		for(int j=1;j<=steps;j++){
			string s;
			cin>>s;
			if(s[0]=='E'){
				int current;
				cin>>current;
				if(arr[current]>0){
					if(oneinline[arr[current]]==0){
						line.push_back(current);
						it[arr[current]]=--line.end();
						oneinline[arr[current]]++;
					}else{
						it[arr[current]]=line.insert(++it[arr[current]],current);
						oneinline[arr[current]]++;
					}
				}else{
					line.push_back(current);
				}
			}else{
				int out=line.front();
				if(arr[out]>0){
					oneinline[arr[out]]--;
				}
				cout<<out<<endl;
				line.pop_front();
			}
		}
	}
}