/**
 *    Author:  Sanchit Sinha
 *    Created: 17.10.2020 00:48:51       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        string s;
        cin>>s;
        ll ct[26]={0};
        ll n=(int)s.size();
        for(ll i=0;i<n;i++) ct[s[i]-'A']++;
        ll odd=0;
        for(ll i=0;i<26;i++) if(ct[i]&1) odd++;
        if(odd>1) cout<<"NO SOLUTION\n";
        else{
                char c;
                if(odd) for(ll i=0;i<26;i++) if(ct[i]&1) c=(char)('A'+i);
                ll l=0,r=n-1;
                vector<char> t(n,'?');
                for(ll i=0;i<26;i++){
                        if(ct[i]&1) t[n/2]=c;
                        ll k=ct[i]/2;
                        for(ll j=0;j<k;j++){
                                char x='A'+i;
                                t[l++]=x;
                                t[r--]=x;
                        }
                }
                for(ll i=0;i<n;i++) cout<<t[i];
                cout<<"\n";
        }
        return 0;
}
