#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
        IOS;
        ll T;
        cin>>T;
        while(T--){
                ll a[3];
                for(ll i=0;i<3;i++) cin>>a[i];

                sort(a,a+3,greater<ll>());

                if(a[0]<=a[1]+a[2]+1) cout<<"Yes\n";
                else cout<<"No\n";
        }    
}