#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
set<ll> s;
ll n;
vector<pair<ll,ll>> v;
int main(){
    IOS;
    ll T;
    cin>>T;
    while(T--){
        v.clear();s.clear();

        cin>>n;

        for(ll i=0;i<n;i++) s.insert(i);
        for(ll i=0;i<n;i++){
            ll x;cin>>x;
            v.push_back({x,i});                
        }
        sort(v.begin(),v.end());

        ll l=v[0].second,r=v[0].second;
        s.erase(s.find(v[0].second));
        cout<<1;
        for(ll i=1;i<n;i++){
            ll index=v[i].second;
            l=min(l,index);
            r=max(r,index);

            s.erase(s.find(index));
            auto it=s.upper_bound(l);
            if(it==s.end()){
                cout<<1;
            }
            else{
                ll mx=*it;
                if(mx>r) cout<<1;
                else cout<<0;
            }
        }
        cout<<"\n";
        
    }    
}