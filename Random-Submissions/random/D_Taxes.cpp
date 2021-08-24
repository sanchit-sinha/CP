#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

bool isprime(ll x){
        if(x<=3) return true;
        for(ll i=2;i*i<=x;i++) if(x%i==0) return false;
        return true;
}
int main(){
        IOS;
        ll n;
        cin>>n;
        if(isprime(n)) cout<<"1\n";
        else{
                if(n&1){
                        if(isprime(n-2)) cout<<"2\n";
                        else{
                                // Goldbach's conjecture ->(3 ,  odd-3 -> even)
                                cout<<"3\n";
                        }
                }
                else{
                        // Goldbach's conjecture
                        cout<<"2\n";
                }
        }
}
