#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

const ll N=1e6+11,mod=1e9+7;
ll n,x,dp[N],coin[101];

int main(){
    IOS;
    cin>>n>>x;
    for(ll i=0;i<n;i++) cin>>coin[i];

    dp[0]=1;
    for(ll i=1;i<=x;i++){
        for(ll j=0;j<n;j++){
            ll prev=i-coin[j];
            if(prev>=0) dp[i]+=dp[prev];
            dp[i]%=mod;
        }
    }
    cout<<dp[x]<<"\n";

}
