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
                ll n;
                cin>>n;
                ll a[n];
                for(ll i=0;i<n;i++) cin>>a[i];
                sort(a , a + n);
                vector<ll> neg,pos;
                for(ll i=0;i<n;i++){
                        if(a[i]<0)neg.push_back(a[i]);
                } 
                for(ll i=0;i<n;i++) {
                        if(a[n-1-i]>=0) pos.push_back(a[n-1-i]);
                } 
                sort(neg.begin() , neg.end());
                sort(pos.begin() , pos.end() , greater<ll>());
                ll len1=(int)neg.size();
                ll len2=(int)pos.size();
                // cout << len1 <<" " << len2 <<"\n";
                // continue;
                ll ans=LLONG_MIN;
                for(ll i=0;i<=len1;i++){
                        ll x=i,y=5-i;
                        ll p=1;
                        if(x>=0 && y>=0 && x<=5 && y<=5 && x+y==5 && x<=len1 && y<=len2){
                                // even
                                if(!(x&1))for(ll j=0;j<x;j++) p*=(neg[j]);
                                else for(ll j=0;j<x;j++) p*=neg[len1-j-1];

                                for(ll j=0;j<y;j++)p*=pos[j];
                                ans=max(ans , p);
                        }
                }
                cout<<ans<<"\n";

        }    
}       