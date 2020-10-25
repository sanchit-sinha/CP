/**
 *    Author:  Sanchit Sinha
 *    Created: 24.10.2020 19:43:03       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

const ll N=1e5+22;
multiset<ll> s;
bool prime[N]; 
void sieve(ll n){ 
    memset(prime,true,sizeof(prime)); 
    for (ll p=2;p*p<=n;p++){ 
        if (prime[p]==true) { 
            s.insert(p);
            for (ll i=p*p;i<=n;i += p) 
                prime[i]=false; 
        } 
    } 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        vector<vector<ll>> ans(n+1,vector<ll>(n+1,0));
        if(n%2==0){
            for(ll i=0;i<n;i++){
                ans[i][i]=1;
            }
            for(ll i=0;i<n;i++){
                ans[i][n-1-i]=4;
            }
            for(ll i=0;i<n;i++){
                for(ll j=0;j<n;j++) cout<<ans[i][j]<<" ";
                cout<<"\n";
            }
        }
        else{
             for(ll i=0;i<n;i++){
                ans[i][i]=1;
            }
            for(ll i=0;i<n;i++){
                ans[i][n-1-i]=4;
            }
            ll y=n/2;
            ans[n/2][n/2]=1;
            ans[y+1][y]=18;
            ans[y-1][y]=18;
            ans[y][y+1]=18;
            ans[y][y-1]=18;
            for(ll i=0;i<n;i++){
                for(ll j=0;j<n;j++) cout<<ans[i][j]<<" ";
                cout<<"\n";
            }
        }
    }    
    return 0;
}