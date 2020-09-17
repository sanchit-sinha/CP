#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long

const ll mod=1e9+7;

int main(){
        IOS;
        ll n,m;
        cin>>n>>m;
        vector<ll> x(n,0);
        for(ll i=0;i<n;i++) cin>>x[i];
        vector< vector<ll >> dp(n , vector<ll>(m+1 , 0));                
        //dp[i][j] - number of arrays of length i and a[i]=j;
        for(ll i=0;i<n;i++){
                if(i==0){
                        if(x[i]==0){
                                for(ll j=1;j<=m;j++) dp[0][j]=1;
                        }
                        else{
                                dp[0][x[0]]=1;
                        }
                }
                else{   
                        if(x[i] == 0){
                                for(ll j=1;j<=m;j++){
                                        if(j-1>=1){
                                                dp[i][j]+=dp[i-1][j-1];
                                                dp[i][j]%=mod;
                                        }

                                        if(j+1<=m){
                                                dp[i][j]+=dp[i-1][j+1];
                                                dp[i][j]%=mod;
                                        }

                                        dp[i][j]+=dp[i-1][j];
                                        dp[i][j]%=mod;
                                }
                        }
                        else{
                               ll j=x[i];
                               if(j-1>=1){
                                        dp[i][j]+=dp[i-1][j-1];
                                        dp[i][j]%=mod;
                                }

                                if(j+1<=m){
                                        dp[i][j]+=dp[i-1][j+1];
                                        dp[i][j]%=mod;
                                }
                                dp[i][j]+=dp[i-1][j];
                                dp[i][j]%=mod;
                        }
                }
        }
        ll ans=0;
        for(ll i=1;i<=m;i++){
                ans+=dp[n-1][i];
                ans%=mod;
        }
        cout<<ans<<"\n";
}
