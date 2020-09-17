#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

// finding shortest prime factor//SPF -- Nlog(n)
const ll mX = 1e6+2;
ll spf[mX];
void sieve (){
    spf[1]=1;
    for(ll i=2;i<mX;i++){
        if(spf[i]==0){
            spf[i]=i;
            for (ll j=1ll*i*i;j<mX;j+=i){
                if(spf[j]==0) spf[j]=i;
            }
        }
    }
}
map<ll,ll> m;
int main(){
        IOS;
        sieve();
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
                cin>>a[i];
        }

        bool ok=1;
        for(ll i=0;i<n;i++){
                ll x=a[i];
                while(x>1){
                        ll div=spf[x];
                        if(div > 1){
                                auto it=m.find(div);
                                if(it!=m.end()){
                                        ok=0;
                                        break;
                                }
                                else m[div]++;
                                while(x%div==0) x/=div;
                        }
                }
                if(!ok) break;
        }
        if(ok) cout<<"pairwise coprime\n";
        else{
                ll g=0;
                for(ll i=0;i<n;i++) g=gcd(g,a[i]);
                if(g==1) cout<<"setwise coprime\n";
                else cout<<"not coprime\n";
        }
}
