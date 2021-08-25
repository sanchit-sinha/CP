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
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        bool ok=0;
        ll start=0;
        for(ll i=0;i<n;i++) if(s[i]=='G') start=i;
        bool got=0;
        for(ll i=start;i<n;i+=k){
                if(!got && s[i]=='#'){
                        break;
                }
                
                if(s[i]=='T'){
                        got=1;
                        break;
                }
        }
        if(!got){
                bool gott=0;
                for(ll i=start;i>=0;i-=k){
                        if(!gott && s[i]=='#'){
                                break;
                        }
                        
                        if(s[i]=='T'){
                                gott=1;
                                break;
                        }
                }
                if(gott) got=1;
        }
        if(got) ok=1;
        else ok=0;

        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
}
