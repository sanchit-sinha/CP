#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll int
int main(){
        IOS;
        ll n,x;
        cin>>n>>x;
        vector<ll> pages(n,0),price(n,0);
        vector< vector<ll> > dp(n,vector<ll>(x+1,0));

        for(ll i=0;i<n;i++) 
                cin>>price[i];

        for(ll i=0;i<n;i++)
                cin>>pages[i];

        // dp[index][price at most j]=max pages read;
        for(ll i=0;i<n;i++){
                if(i==0){
                        for(ll j=price[0];j<=x;j++) dp[0][j]=pages[i];
                }
                else{
                        for(ll j=0;j<=x;j++){
                                dp[i][j]=max(dp[i][j] , dp[i-1][j]);
                                if(j-price[i]>=0) dp[i][j]=max(dp[i][j] , dp[i-1][j-price[i]] + pages[i]);
                        }
                }
        }
        cout<<dp[n-1][x]<<"\n";
}
