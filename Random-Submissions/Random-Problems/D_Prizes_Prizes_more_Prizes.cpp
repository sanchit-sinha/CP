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
        cin>>n;
        ll price[n];
        for(ll i=0;i<n;i++) cin>>price[i];
        ll a[5];
        map<ll,ll> match;
        for(ll i=0;i<5;i++) cin>>a[i],match[a[i]]=i;
        sort(a ,a+5 , greater<ll>());
        vector<ll> ans(5,0);
        ll present=0;
        for(ll i=0;i<n;i++){
                ll x=price[i];
                present+=x;
                while(1){
                        bool got=0;
                        ll div=1,index=-1;
                        for(ll j=0;j<5;j++){
                                if(a[j]<=present){
                                        got=1;
                                        div=a[j];
                                        index=j;
                                        break;
                                }
                        }
                        if(!got) break;
                        else{
                                ans[match[a[index]]]+=present/div;
                                present%=div;
                        }

                }
        }
        for(ll i=0;i<5;i++) cout<<ans[i]<<" ";
        cout<<"\n";
        cout<<present<<"\n";
}
