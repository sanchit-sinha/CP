#include "bits/stdc++.h"
using namespace std; 
#define ll long long 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int main(){
    IOS;
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if(b>a)swap(a,b);
        if(a>=b+b){
            if(a==b+b) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            if((a+b)%3==0) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
