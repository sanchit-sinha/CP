/**
 *    Author:  Sanchit Sinha
 *    Created: 10.10.2020 20:03:12       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll n,m;
        cin>>n>>m;
        string s[n];
        ll row[n][m] = {0};
        ll col[n][m] = {0};
        for(ll i=0;i<n;i++) cin>>s[i];
        ll ans=0;
        for(ll i=0;i<n;i++){
                for(ll j=0;j<m;j++){
                        if(j == 0){
                                if(s[i][j] == '*') row[i][j] = 1;
                               
                        }
                         else{
                                if(s[i][j] == '*') row[i][j] = row[i][j-1] + 1;
                                else row[i][j] = row[i][j-1];
                        }
                }
        }

        for(ll i=0;i<m;i++){
                for(ll j=0;j<n;j++){
                        if(j == 0){
                                if(s[j][i] == '*') col[j][i] = 1;
                        }
                         else{
                                if(s[j][i] == '*') col[j][i] = col[j-1][i] + 1;
                                else col[j][i]=col[j-1][i]; 
                        }
                }
        }

        // for(ll i=0;i<n;i++){
        //         for(ll j=0;j<m;j++){
        //                 cout << row[i][j] <<" " << col[i][j]<<"\n";
        //         }
        // }
        for(ll i=0;i<n;i++){
                for(ll j=0;j<m;j++){
                        if(s[i][j] == '*'){
                                ll x=row[i][j];
                                ll y = col[i][j];
                                ans += (x*(y-1));
                        }
                }
        }

        cout << ans<<"\n";
        return 0;
}
