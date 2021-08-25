/**
 *    Author:  Sanchit Sinha
 *    Created: 24.10.2020 14:12:44       
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
    while(T--){
        ll n;
        cin>>n;
        string s[n];
        for(ll i=0;i<n;i++) cin>>s[i];
        if(s[0][1]=='1' && s[1][0]=='1'){
            ll ans=0;
            ans+=(s[n-1][n-2]=='1');
            ans+=(s[n-2][n-1]=='1');
            cout<<ans<<"\n";
            if(s[n-1][n-2]=='1') cout<<n<<" "<<n-1<<"\n";
            if(s[n-2][n-1]=='1') cout<<n-1<<" " <<n<<'\n';
        }
        else if(s[0][1]=='0' && s[1][0]=='0'){
            ll ans=0;
            ans+=(s[n-1][n-2]=='0');
            ans+=(s[n-2][n-1]=='0');
            cout<<ans<<"\n";
            if(s[n-1][n-2]=='0') cout<<n<<" "<<n-1<<"\n";
            if(s[n-2][n-1]=='0') cout<<n-1<<" " <<n<<'\n';
        }
        else{
            if(s[n-1][n-2]=='1' && s[n-2][n-1]=='1'){
                ll ans=0;
                ans+=(s[0][1]=='1');
                ans+=(s[1][0]=='1');
                cout<<ans<<"\n";
                if(s[0][1]=='1') cout<<1<<" "<<2<<"\n";
                if(s[1][0]=='1') cout<<2<<" "<<1<<"\n";
            }
            else if(s[n-1][n-2]=='0' && s[n-2][n-1]=='0'){
                ll ans=0;
                ans+=(s[0][1]=='0');
                ans+=(s[1][0]=='0');
                cout<<ans<<"\n";
                if(s[0][1]=='0') cout<<1<<" "<<2<<"\n";
                if(s[1][0]=='0') cout<<2<<" "<<1<<"\n";
            }
            else{
                ll ans=2;
                cout<<ans<<"\n";
                // 1
                if(s[0][1]=='0') cout<<1<<" "<<2<<"\n";
                if(s[1][0]=='0') cout<<2<<" "<<1<<"\n";

                // 0
                if(s[n-1][n-2]=='1') cout<<n<<" "<<n-1<<"\n";
                if(s[n-2][n-1]=='1') cout<<n-1<<" "<<n<<"\n";
            }
        }   
    }    
    return 0;
}