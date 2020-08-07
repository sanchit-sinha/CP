#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
ll n,s;
int main(){
    IOS;
    cin>>n>>s;
    map<ll,multiset<pair<ll,ll>>> m;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];

    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            m[a[i]+a[j]].insert({i,j});
        }
    } 

    bool got=0;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;++j){
            ll find=(s-a[i]-a[j]);
            if(find){
                auto it=m.find(find);
                if(it != m.end()){
                    for(auto p:m[find]){
                        if((p.first!=i && p.second!=j) && (p.first!=j && p.second!=i)){
                            cout << i+1<<" "<<j+1<<" "<<p.first+1<<" "<<p.second+1<<'\n';
                            got=1;
                        }
                    }
                }
            }
            if(got) break;
        }
        if(got) break;
    }    
    if(!got) cout<<"IMPOSSIBLE\n";
}
