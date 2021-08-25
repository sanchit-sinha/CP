#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n,sum;
    cin>>n>>sum;
    vector<pair<ll,ll>>v;
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    bool ok=0;
    for(ll i=0;i<n;i++){
        auto it=upper_bound(v.begin(),v.end(),make_pair(sum-v[i].first,LLONG_MAX));
        if(it != v.begin()){
            it--;
            ll index1=v[i].second+1 , index2=it->second+1;
            if(it->first== sum-v[i].first && index1 != index2){
                cout<<index1<<" "<<index2<<"\n";
                ok=1;
                break;
            }
        }
    }
    if(!ok) cout<<"IMPOSSIBLE\n";
}
