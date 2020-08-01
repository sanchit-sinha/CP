#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        if(x+x<=y) cout<<x<<" "<<x+x<<"\n";
        else cout<<-1<<" "<<-1<<"\n";
    }
}
