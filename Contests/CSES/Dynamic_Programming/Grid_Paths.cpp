#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
const ll N=1e3+11,mod=1e9+7;
string s[N];
ll n,dp[N][N];
int main(){
    IOS;
    cin>>n;
    for(ll i=0;i<n;i++) cin>>s[i];
    
    for(ll i=0;i<n;i++){
        if(s[0][i]=='.') dp[0][i]=1;
        else break;
    }

    for(ll i=0;i<n;i++){
        if(s[i][0]=='.') dp[i][0]=1;
        else break;
    }

    for(ll i=1;i<n;i++){
        for(ll j=1;j<n;j++){
            if(s[i][j]=='.'){
                dp[i][j]+=dp[i-1][j];
                dp[i][j]%=mod;
                dp[i][j]+=dp[i][j-1];
                dp[i][j]%=mod;
            }
        }
    }

    // for(ll i=0;i<n;i++){
    //     for(ll j=0;j<n;j++) cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    cout<<dp[n-1][n-1]<<"\n";
}
