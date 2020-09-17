#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

const ll N=1e6+1;
ll dp[N],n;
int main(){
    IOS;
    cin>>n;

    for(ll i=1;i<=n;i++) dp[i]=LLONG_MAX;
    for(ll i=1;i<=n;i++){
        vector<ll> digits;
        ll x=i;
        while(x){
            if(x%10) digits.push_back(x%10);
            x/=10;
        }
        ll len=(int)digits.size();
        for(ll j=0;j<len;j++){
            ll prev_number=i-digits[j];
            if(prev_number>=0) dp[i]=min(dp[i],dp[prev_number]+1);
        }
    }
    cout<<dp[n]<<"\n";
}
