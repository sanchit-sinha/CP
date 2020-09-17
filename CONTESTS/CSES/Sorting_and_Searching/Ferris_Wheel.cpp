#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll n,x;
    cin>>n>>x;
    multiset<ll> s;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        s.insert(x);
    }
    ll ans=0;
    while(!s.empty()){
        ll y=*s.rbegin();
        s.erase(s.find(y));
        if(y<=x) {
            bool two=0;
            auto it=s.upper_bound(x-y);
            if(it != s.begin()) {
                it--;
                if(y+*it <= x){
                    s.erase(it);
                    ans++;
                    two=1;
                }
            }
            if(!two) ans++;
        }
    }
    cout<<ans<<"\n";
}
