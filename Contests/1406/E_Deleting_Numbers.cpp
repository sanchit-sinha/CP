#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll int

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

ll A(ll x){
        cout<<"A"<<" " <<x<<"\n";
        ll y;
        cin>>y;
        return y;
}
ll B(ll x){
        cout<<"B"<<" " <<x<<"\n";
        ll y;
        cin>>y;
        return y;
}
void C(ll x){
        cout<<"C"<<" " <<x<<"\n";
}
int main(){
        // concept similar to factorizing a number in sqrt logn
        IOS;
        ll n;
        cin>>n;
        vector<ll> primes;
        vector<bool> isprime(n+11,true);
        for(ll i=2;i<=n;i++){
                if(isprime[i]){
                        primes.push_back(i);
                        for(ll j=i+i;j<=n;j+=i) isprime[j]=0;
                }
        }

        ll ans=1;
        ll len=(int)primes.size();
        // number of primes < sqrt(n) -> <(~65)
        for(ll i=0;i<min(len,65);i++){
                ll x=primes[i];
                ll b=B(x),a=A(x);
                if(a){
                        ll temp=x*x;
                        while(true){
                                if(temp>n) break;
                                if(A(temp)) temp*=x;
                                else break;
                        }
                        temp/=x;
                        ans*=temp;
                }
        }
        // atmax 200 queries have been performed , remaining about 9800
        // One prime number is remaining which "may" be the factor of ans
        for(ll i=65;i<len;i++){
                ll x=primes[i];
                ll b=B(x);
        }
}
