/**
 *    author:  Sanchit Sinha
 *    created: 27.09.2020 08:38:39       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll T;
        cin>>T;
        for(ll PTC=1;PTC<=T;PTC++){
                cout<<"Case #"<<PTC<<":"<<' ';
                ll n,x;
                cin>>n>>x;
                vector<pair<ll,ll>>v;
                for(ll i=0;i<n;i++){
                        ll l,r;
                        cin>>l>>r;
                        v.push_back(make_pair(l,r));
                }
                sort(v.begin() , v.end());
                ll ans=0,mx=0;
                for(ll i=0;i<n;i++){
                        ll l=v[i].first , r=v[i].second;
                        ll len=r-l;
                        if(i==0){       
                                ll add = (len-1+x)/x;
                                mx=max(mx,l + add*x);
                                ans += add;
                        }
                        else{   
                                if(r<=mx) continue;
                                else{
                                        l = max(l,mx);
                                        len = r-l;
                                        ll add = (len-1+x)/x;
                                        mx=max(mx,l + add*x);
                                        ans += add;
                                }
                        }     
                }
                cout<<ans<<"\n";
        }    
}
