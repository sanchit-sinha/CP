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
        string s;
        cin>>s;
        ll n=(int)s.size();
        for(ll i=0;i<n;i++){
                if(s[i]=='?'){
                        ll index1=i-1,index2=i+1;
                        bool gota=0;
                        if(index1>=0 && s[index1]=='a') gota=1;
                        if(index2<n && s[index2]=='a') gota=1;
                        if(gota) s[i]='b';
                        else s[i]='a';
                }
        }
        cout<<s<<"\n";
}
