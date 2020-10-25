/**
 *    Author:  Sanchit Sinha
 *    Created: 24.10.2020 20:47:04       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

const ll mod=1e9+7;
ll ncr(ll n,ll r){
    if(n<r) return 0;
    ll p=1;
    for(ll i=1;i<=r;i++){
        p*=(n-i+1);
        p%=mod;
    } 
    // cout <<p <<" ";
    for(ll i=1;i<=r;i++){
        ll x=powermod(i,mod-2,mod);
        p*=x;
        p%=mod;
    }
    // cout << p <<" ";
    return p%mod;
}
ll fact(ll n){
    ll ans=1;
    for(ll i=1;i<=n;i++){
        ans*=i;
        ans%=mod;
    }
    return ans%mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x,pos;
    cin>>n>>x>>pos;
    map<ll,ll> m;
    ll l=0,r=n,mid=0,ct=1;
    while(l<r){
        mid=(l+r)/2;
        m[mid]=ct++;
        if(pos>=mid) l=mid+1;
        else r=mid;
    }
    // for(auto it=m.begin();it!=m.end();it++) {
    //     cout<< it->first<<" " << it->second<<"\n";
    // }
    // cout<<"\n";
    ll small=0,big=0;
    for(auto it=m.begin();it!=m.end();it++) {
        if(it->first<pos) small++;
        else if(it->first>pos) big++;
    }
    ll len=(int)m.size();
    ll less=x-1,greater=n-x;
    ll ans=1;

    // cout << less <<" " << small << " : "<<greater<<" "<<big<< "  : " << len<<"\n";
    // (n-len)! * small C less * big C greater 
    ans*=fact(n-len);
    ans%=mod;
    
    // cout <<" n-len "<< ans<<"\n ";
    
    ans*=ncr(less,small);
    ans%=mod;

    // cout << "lessCsmall "<<ans<<"\n ";

    ans*=ncr(greater,big);
    ans%=mod;

    // cout <<"greaterCbig  "<< ans<<"\n ";

    ans*=fact(big);
    ans%=mod;

    // cout <<"fact(big)  "<< ans<<"\n ";

    ans*=fact(small);
    ans%=mod;

    // cout<<"fact(small)  "<<ans<<"\n";


    cout << ans<<"\n";
    return 0;
}
