/**
 *    author:  Sanchit Sinha
 *    created: 27.09.2020 05:32:45       
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
                ll a[n];
                vector<pair<ll,ll>>v;
                for(ll i=0;i<n;i++) {
                        cin>>a[i];
                        ll y=(a[i]-1+x)/x;
                        v.push_back(make_pair(y,i));
                }
                sort(v.begin() , v.end());
                for(ll i=0;i<n;i++) cout<<v[i].second+1<<" ";
                cout<<"\n";
        }    
}
