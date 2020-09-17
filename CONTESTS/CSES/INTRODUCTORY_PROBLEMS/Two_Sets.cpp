#include "bits/stdc++.h"
using namespace std; 
#define ll long long 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int main(){
    IOS;
    ll n;cin>>n;
    ll a=(n*(n+1))/2;
    if(a&1)cout<<"NO\n";
    else{
        cout<<"YES\n";
        bool vis[n+1]={0};
        a/=2;
        ll s=0,ct=0;
        for(ll i=n;i>0;--i){
            s+=i;
            if(s<a) vis[i]=1,ct++;
            else{
                s-=i;
                break;
            }
        }
        vis[a-s]=1;
        ct++;
        cout<<ct<<endl;
        for(ll i=1;i<=n;i++) if(vis[i]) cout<<i<<" ";
        cout<<"\n";
        cout<<n-ct<<"\n";
        for(ll i=1;i<=n;i++) if(!vis[i]) cout<<i<<" ";
        cout<<"\n";
    } 
}
