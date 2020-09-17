#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

const ll N=1e6+11;
const ll mod=1e9+7;
ll n,dp[N];// dp[i][j] - number of ways to obtain sum i
int main(){
    IOS;
    cin>>n;

    // base
    dp[1]=1,dp[0]=1;
    
    // transition
    for(ll i=2;i<=n;i++){
        for(ll j=1;j<=6;j++){
            if(i-j>=0)dp[i]+=dp[i-j];

            dp[i]%=mod;
        }
    }

    cout<<dp[n]<<"\n";
}
