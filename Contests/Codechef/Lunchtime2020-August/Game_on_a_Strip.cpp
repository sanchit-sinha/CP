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
                vector<ll>v;
                for(ll i=0;i<n;i++) cin>>a[i];
                for(ll i=0;i<n;i++){
                        if(a[i]==0){
                                ll ct=0;
                                while(i<n && a[i]==0)ct++,i++;
                                i--;
                                if(ct) v.push_back(ct);
                        }
                }
                ll len=(int)v.size();
                if(len==0){
                        cout<<"No\n";
                        continue;
                }
                else{
                        sort(v.begin() , v.end() , greater<ll>());
                        if(len==1){
                                ll mx=v[0];
                                ll first=(mx+1)/2 , second=mx/2;
                                if(first>second)cout<<"Yes\n";
                                else cout<<"No\n";
                        }
                        else{
                                ll mx1=v[0],mx2=v[1];
                                ll first=(mx1+1)/2 , second=mx1/2;
                                if(mx2>=first) cout<<"No\n";
                                else{
                                        if(first>second)cout<<"Yes\n";
                                        else cout<<"No\n";   
                                }
                        }
                }                
        }       
}