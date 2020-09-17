#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
int main(){
        IOS;
        ll n,m;
        cin>>n>>m;
        ll a[n],b[m];
        ll g=0;
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<m;i++) cin>>b[i];
        for(ll i=0;i<n-1;i++)g=gcd(g,a[i+1]-a[i]);
        for(ll i=0;i<m;i++){
                ll x=b[i];
                if(g%x==0){
                        cout<<"YES\n";
                        cout<<a[0] <<" " << i+1<<"\n";
                        return 0;
                }
        }
        cout<<"NO\n";
}
