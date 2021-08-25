#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}


int main(){
        IOS;
        ll n;
        cin>>n ;
        ll a[n];
        map<ll,ll> m;
        vector<ll>v;
        for(ll i=0;i<n;i++) cin>>a[i],m[a[i]]++;
        for(ll i=0;i<n;i++){
                m[a[i]]--;
                if(m[a[i]]==0) v.push_back(a[i]);
        }
        ll len=(int)v.size();
        cout<<len<<"\n";
        for(ll i=0;i<len;i++) cout<<v[i]<<" ";
        cout<<"\n";
}
