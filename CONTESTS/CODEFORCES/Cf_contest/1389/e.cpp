#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
int main(){
    IOS;
    ll T;
    cin>>T;
    while(T--){
        ll m,d,w;
        cin>>m>>d>>w;
        /* 
        y*(d-1)+x %w == x*(d-1)+y%w
            (y-x)*(d-1) = w*q
            (y-x) --factor of f=w/gcd(w,d-1);       
            iterate throug diff.. 
            for f -- min(d,m)-f pairs
                2f -- min(d,m) - 2f pairs
                .
                .
                ....
       */         
        ll g=gcd(w,d-1);
        ll f=w/g;
        ll mn=min(d,m);
        ll n=mn/f;
        cout<<(mn*n)-f*((n*(n+1))/2)<<"\n";
    }    
}