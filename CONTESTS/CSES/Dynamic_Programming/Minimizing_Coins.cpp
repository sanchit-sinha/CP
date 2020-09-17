#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll int 

const ll N=1e6+2;
ll dp[N],n,coin[101],x;
int main(){
    IOS;
    cin>>n>>x;
    for(ll i=0;i<n;i++) cin>>coin[i];
    sort(coin,coin+n);

    for(ll i=1;i<=x;i++) dp[i]=INT_MAX;

    for(ll i=1;i<=x;i++){
        for(ll j=0;j<n;j++){
            ll prev_position=i-coin[j];
            if(prev_position>=0){
                if(dp[prev_position]!=INT_MAX)dp[i]=min(dp[i],dp[prev_position]+1);
            }
        }
    } 

    if(dp[x]==INT_MAX) cout<<-1<<"\n";
    else cout<<dp[x]<<"\n";
}
