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
        if(s[n-2]=='P'){
                ll x=s[0]-'0';
                ll y=s[1]-'0';
                ll num=x*10+y;
                if(num!=12) num+=12;
                x=num/10;
                y=num%10;
                s[0]=x+'0';
                s[1]=y+'0';
        }
        else{
                ll x=s[0]-'0';
                ll y=s[1]-'0';
                ll num=x*10+y;
                if(num==12) num=0;
                x=num/10;
                y=num%10;
                s[0]=x+'0';
                s[1]=y+'0';
        }
        for(ll i=0;i<n-2;i++) cout<<s[i];
        cout<<"\n";
}
