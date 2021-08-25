#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

int main(){
    IOS;
    ll n;
    cin>>n;
    ll ans=-1;
    if(n==7){
        cout<<1<<"\n";
        return 0;
    }
    else if(n%2==0){
        cout<<-1<<"\n";
        return 0;
    }

    n*=9;
    for(ll i=1;i<=1e6;i++){
        ll b=3;
        ll a= powermod(10,i,n);
        a%=n;
        (a)=(a-1+n)%n;
        
        a=((a%n)*7)%n;
        if(a==0){
            ans=i;
            break;
        }
    }
    if(ans!=-1)cout << ans<<"\n";
    else cout<<-1<<"\n";
}
