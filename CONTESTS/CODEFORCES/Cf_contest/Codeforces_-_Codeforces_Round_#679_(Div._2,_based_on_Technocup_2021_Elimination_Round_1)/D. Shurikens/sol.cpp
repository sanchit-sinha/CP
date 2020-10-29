/**
 *    Author:  Sanchit Sinha
 *    Created: 25.10.2020 18:25:43       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll N=2e5+11;
ll a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll index=0;
    vector<pair<pair<ll,ll> , ll>> order;
    ll ct=0;
    bool ok=0;
    vector<ll> v;
    for(ll i=0;i<n+n;i++){
        char c;
        ll x;
        cin>>c;
        if(c=='-'){
            ct--;
            cin>>x;
            v.push_back(x);
            order.push_back(make_pair(make_pair(x,ct),index));
            index++;
        }
        else{
            ct++;
        }
        if(ct<0) ok=0;
    }
    index=1;
    sort(v.begin() , v.end());
    ll len=(int)v.size();
    if(len != n) ok=0;
    if(!ok) cout<<"NO\n";
    else{
        for(ll i=0;i<len;i++){
            if(v[i]!=i+1) ok=0;
        }
        if(!ok) cout<<"NO\n";
        else{
            for(ll i=0;i<n;i++) a[i]=LLONG_MAX;
            for(ll i=0;i<n;i++){
                ll ele = order[i].first.first;
                ll number_present = order[i].first.second;
                ll index=order[i].second;

                if(number_present==1) a[index]=ele;
            }
            for(ll i=0;i<n;i++){
                ll ele = order[i].first.first;
                ll number_present = order[i].first.second;
                ll index=order[i].second;
                
                ll prev = index-number_present;
            }
        }
    }
    return 0;
}
