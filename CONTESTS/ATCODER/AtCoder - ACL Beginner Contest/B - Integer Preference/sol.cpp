/**
 *    author:  Sanchit Sinha
 *    created: 26.09.2020 21:41:26       
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
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        bool ok=0;
        // a b c d
        if(c>=a && c<=b) ok=1;
        // c d a b 
        if(a>=c && a<=d) ok=1;
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";

        return 0;
}
