#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n;cin>>n;

    vector<pair<pair<ll,ll>,ll>>v;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        v.push_back(make_pair(make_pair(b,a),i));
    }
    sort(v.begin(),v.end());

    multiset<pair<ll,ll>>m;

    ll ans=0;ll id[n];
    for(ll i=0;i<n;i++){
        ll l=v[i].first.second,r=v[i].first.first,index=v[i].second;
        if(i==0){
            m.insert({r,ans});
            id[index]=ans++;
        }
        else{
            auto it=m.upper_bound(make_pair(l,LLONG_MIN));
            if(it==m.begin()){
                m.insert({r,ans});
                id[index]=ans++;
            }
            else{
                it--;
                ll val=it->second;
                m.erase(it);
                m.insert(make_pair(r,val));
                id[index]=val;
            }   
        }
    }

    cout<<ans<<"\n";
    for(ll i=0;i<n;i++) cout<<id[i]+1<<" ";
    cout<<"\n";
}
