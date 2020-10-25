/**
 *    Author:  Sanchit Sinha
 *    Created: 24.10.2020 20:02:20       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

bool BinarySearch(vector<ll> a,ll x){
    ll left=0,right=(int)a.size();
    while(left<right){
        ll mid=(left+right)/2;
        if(a[mid]<=x) left=mid+1;
        else right=mid;
    }
    if(left>0 && a[left-1]==x) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x,pos;
    cin>>n>>x>>pos;
    vector<ll>a(n,0);
    for(ll i=0;i<n;i++) a[i]=i+1;
    ll ct=0;
    do{
        if(BinarySearch(a,x)){
            ll index=0;
            for(ll i=0;i<n;i++){
                if(a[i]==x) index=i;
            }
            if(index==pos){
                // for(ll i=0;i<n;i++){
                //     cout<<a[i]<<" ";
                // }
                // cout<<"\n";
                ct++;
            }
        }
    } while (next_permutation(a.begin(),a.end()));
    cout<<ct<<"\n";
    return 0;
}
