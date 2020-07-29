#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll t;
    cin>>t;
    while(t--){
        ll n,k,l;
        cin>>n>>k>>l;
        ll d[n+2];
        vector<ll> safe;
        bool ok=1;

        safe.push_back(0);
        for(ll i=1;i<=n;i++){
            cin>>d[i];
            if(d[i]>l) ok=0;
            if(d[i]+k<=l) safe.push_back(i);
        }
        safe.push_back(n+1);

        for(ll i=0;i<(int)(safe.size()-1);++i){
            ll t=k;
            bool inc=0;
            for(ll j=safe[i]+1;j<safe[i+1];++j){
                if(inc) t++;
                else t--;

                if(!inc) t=min(t,l-d[j]);

                if(t+d[j]>l) ok=0;
                if(t<=0) {
                    t=0;
                    inc=1;
                }
            }
        }

        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }    
}
