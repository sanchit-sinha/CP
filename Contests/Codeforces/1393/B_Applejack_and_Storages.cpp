#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
set<ll> s2,s4,s6,s8;
map<ll,ll>m;
bool check(){
    ll l2=(int)(s2.size());
    ll l4=(int)(s4.size());
    ll l6=(int)(s6.size());
    ll l8=(int)(s8.size());
    
    if(l8) return true;
    if((l6>=2) || (l6>=1 && l4>=1) || (l6>=1 && l2>=1)) return true;
    if((l4>=2) || (l4>=1 && l2>=2)) return true;

    return false;
}
int main(){
    IOS;
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]++;        
    }

    for(auto it=m.begin();it!=m.end();it++){
        ll ct=it->second;
        // cout << it->first<<" " << it->second<<"\n\n";
        if(ct>=8) s8.insert(it->first);
        else if(ct>=6) s6.insert(it->first);
        else if(ct>=4) s4.insert(it->first);
        else if(ct>=2) s2.insert(it->first);
    }

    ll q;
    cin>>q;
    while(q--){
        char c;
        ll x;
        cin>>c>>x;ll prev=m[x];
        if(c=='+'){
            m[x]++;
        }
        else m[x]--;

        ll ct=prev;
        // cout << x << " : " << ct <<"\n";
        if(ct>=8) {
            auto it=s8.find(x);
            if(it != s8.end()) s8.erase(it);
        }
        else if(ct>=6) {
            auto it=s6.find(x);
            if(it != s6.end()) s6.erase(it);
        }
        else if(ct>=4) {
            auto it=s4.find(x);
            if(it != s4.end()) s4.erase(it);
        } 
        else if(ct>=2){
            auto it=s2.find(x);
            if(it != s2.end()) s2.erase(it);
        }

        ct=m[x];
        if(ct>=8) s8.insert(x);
        else if(ct>=6) s6.insert(x);
        else if(ct>=4) s4.insert(x);
        else if(ct>=2) s2.insert(x);

        if(check()) cout<<"YES\n";
        else cout<<"NO\n";
    }

}
