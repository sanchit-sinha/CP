#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}


int main(){
       IOS;
       ll T;
       cin>>T;
       while(T--){
                ll p,f,cs,cw,s,w;
                cin>>p>>f>>cs>>cw>>s>>w;
                // cheaper first
                if(s>w) swap(cs,cw),swap(s,w);
               
                // first p
                ll mx1=0;
                for(ll i=0;i<=min(cs,p/s);i++){
                        pair<ll,ll> picked_by_first,picked_by_second;

                        picked_by_first.first=i;
                        ll rem_capacity_first=p-(picked_by_first.first)*s;
                        picked_by_first.second=min(cw,rem_capacity_first/w);

                        ll rem_cs=cs-picked_by_first.first , rem_cw=cw-picked_by_first.second;

                        picked_by_second.first = min(rem_cs , f/s);
                        ll rem_capacity_second = f-picked_by_second.first*s;
                        picked_by_second.second=min(rem_cw , rem_capacity_second/w);

                        mx1=max(mx1 , picked_by_first.first + picked_by_first.second + picked_by_second.first + picked_by_second.second);
                }

                // first f
                ll mx2=0;
                for(ll i=0;i<=min(cs,f/s);i++){
                        pair<ll,ll> picked_by_first,picked_by_second;

                        picked_by_first.first=i;
                        ll rem_capacity_first=f - (picked_by_first.first)*s;
                        picked_by_first.second=min(cw,rem_capacity_first/w);

                        ll rem_cs=cs-picked_by_first.first , rem_cw=cw-picked_by_first.second;

                        picked_by_second.first = min(rem_cs , p/s);
                        ll rem_capacity_second = p-picked_by_second.first*s;
                        picked_by_second.second=min(rem_cw , rem_capacity_second/w);

                        mx2=max(mx2 , picked_by_first.first + picked_by_first.second + picked_by_second.first + picked_by_second.second);
                }

                // cout << mx1 <<" " << mx2<<"\n";
                cout << max(mx1 , mx2)<<"\n";   
       }    
}