#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll int
ll n;
string a,b;
int main(){
    IOS;
    ll t;
    cin>>t;
    while(t--){
        a.clear(),b.clear();
        cin>>n>>a>>b;
        a+='0',b+='0';
        vector<ll>v1,v2;
        for(ll i=0;i<n;i++){
            if(a[i]!=a[i+1]) v1.push_back(i);
            if(b[i]!=b[i+1]) v2.push_back(i);
        }
        cout<<(int)(v1.size())+(int)(v2.size())<<" ";
        for(ll i=0;i<(int)(v1.size());i++) cout<<v1[i]+1<<" ";
        reverse(v2.begin(),v2.end());
        for(ll i=0;i<(int)(v2.size());i++) cout<<v2[i]+1<<" ";
        cout<<"\n";
    }
}
