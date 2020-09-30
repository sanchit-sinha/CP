/**
 *    author:  Sanchit Sinha
 *    created: 27.09.2020 13:19:10       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll ask(ll l,ll r){
        cout << "?"<<" " <<l<<" " << r<<"\n";
        cout.flush();
        ll x;
        cin>>x;
        return x;
}
void display(ll ans[] , ll n){
        cout <<"! ";
        for(ll i=0;i<n;i++) cout<<ans[i] <<" ";
        cout<<"\n";
        cout.flush();
}
int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll n;
        cin>>n;
        ll sfx[n];
        for(ll i=0;i<=n-2;i++){
                ll index=i+1;
                sfx[i] = ask(index,n);
        }
        sfx[n-1] = sfx[0] - ask(1,n-1);
        ll ans[n];
        ans[n-1] = sfx[n-1];
        // 0 1 2 3 4 ..... n-2
        for(ll i=0;i<n-1;i++){
                ans[i] = sfx[i] - sfx[i+1];
        }
        display(ans,n);
        return 0;
}
