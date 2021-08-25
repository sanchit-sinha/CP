#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

const ll mod=1e9+7;
ll fact(ll x){
        ll p=1;
        x=(x+mod)%mod;
        for(ll i=1;i<=x;i++){
                p*=i;
                p%=mod;
        }
        return p%mod;
}
int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                ll n,x;
                cin>>n>>x;
                ll a[n+11];
                map<ll,ll> m;
                bool ok=1;
                for(ll i=2;i<=n;i++) cin>>a[i],m[a[i]]++;
                multiset<pair<ll,ll>> s;
                for(auto it=m.begin() ; it!=m.end();it++) s.insert(make_pair(it->first,it->second));
                m[0]++;
                ll index=1;
                ll ans=1,extra=0;
                for(auto it=s.begin();it!=s.end();it++){
                        ll dis=it->first,ct=it->second;
                        if(dis!=index){
                                ok=0;
                                break;
                        }
                        else{
                                ll num=n-m[dis-1]-m[dis+1];
                                extra+=powermod(num,ct,mod);
                               if(dis==2) cout << num <<" " << ct<<"\n";
                                ll val=(powermod(m[dis-1],ct,mod));
                                ans*=val;
                                ans%=mod;
                        }
                        index++;
                }
                if(ok){
                        if(x==n-1) cout<<ans<<"\n";
                        else{
                                ll rem=x-(n-1);
                                ll p1=fact(rem);
                                ll p2=fact(extra-rem);
                                ll k=extra*powermod(p1,mod-2,mod);
                                k%=mod;
                                k*=powermod(p2,mod-2,mod);
                                k%=mod;
                                cout << ans <<" " << extra <<"\n";
                                ans+=k;
                                ans%=mod;
                                cout<<ans<<"\n";
                        }
                }
                else cout<<"0\n";
        }    
}