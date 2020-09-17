#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
        IOS;
        ll n,m;
        cin>>n>>m;
        ll a[n],b[m];
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<m;i++) cin>>b[i];

        map<ll,multiset<ll> > mp;
        for(ll i=0;i<n;i++){
                for(ll j=0;j<m;j++){
                        ll x=(a[i]&b[j]);
                        mp[i].insert(x);
                }
        } 

        // trying to make largest bit zero      
        for(ll i=9;i>=0;i--){
                ll ct=0;
                for(ll j=0;j<n;j++){
                        bool poss=0;
                        for(auto bit:mp[j]){
                                if((1ll<<i)&bit) continue; // set
                                else poss=1;
                        }
                        if(poss) ct++;
                }
                if(ct==n){
                        // remove other
                        for(ll j=0;j<n;j++){
                                multiset<ll> s=mp[j];
                                for(auto bit:mp[j])
                                        if((1ll<<i)&bit) s.erase(s.find(bit));
                                mp[j]=s;
                        }
                }
        }

        ll ans=0;
        for(ll i=0;i<n;i++){
                ll aibi=*(mp[i].begin());
                ans=(ans|(aibi));
        }

        cout<<ans<<"\n";

}
