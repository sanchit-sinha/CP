#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        ll a[n];
        vector<ll> x;
        for(ll i=0;i<n;i++) cin>>a[i],x.push_back(a[i]);

        sort(x.begin(),x.end());

        ll mx=100;
        ll ans=LLONG_MIN;
        for(ll sum=0;sum<=mx;sum++){
            bool vis[n]={0};
            ll ct=0;
            for(ll i=0;i<n;i++){
                if(!vis[i]){
                    for(ll j=0;j<n;j++){
                        if(!vis[j] && j!=i){
                            if(x[i]+x[j]==sum){
                                ct++;
                                vis[i]=vis[j]=1;
                                break;
                            }
                        }
                    }
                }
            }
            // cout << sum <<" " << ct<<"\n";
            ans=max(ans,ct);
        }
        cout << ans<<"\n";
    
    }    


}