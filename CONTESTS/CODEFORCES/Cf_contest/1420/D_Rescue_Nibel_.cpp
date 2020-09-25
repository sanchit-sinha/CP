#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll mod = 998244353;
ll nCr(vector<ll>& fact, ll n,ll r){
        if(n<r) return 0;
        ll p=fact[n]%mod;
        
        p*=powermod(fact[r],mod-2,mod);
        p%=mod;
        
        p*=powermod(fact[n-r],mod-2,mod);
        p%=mod;

        return p;
}
int main(){
        IOS;
        ll n,k;
        cin>>n>>k;

        vector<ll> fact(n+11+n , 1);
        for(ll i=2;i<=n+n;i++) fact[i]=fact[i-1]*i , fact[i]%=mod;

        vector<pair<ll,ll>>v;        
        for(ll i=0;i<n;i++){
                ll x,y;
                cin>>x>>y;
                v.push_back(make_pair(x,-1));
                v.push_back(make_pair(y,1));
        }
        sort(v.begin() , v.end());

        if(k==1){
                cout<<n<<"\n";
                return 0;
        }

        ll active=0,ans=0;
        for(ll i=0;i<n+n;i++){
                if(v[i].second==-1){s
                        ans+=nCr(fact,active,k-1);
                        ans%=mod;

                        active++;
                }
                else active--;
        }
        cout<<ans<<"\n";
}
