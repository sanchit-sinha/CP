#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll x,y,n,m;
    cin>>n>>m>>x>>y;
    x--,y--;
    if(n==1){
        for(ll i=y;i<=m;i++) cout<<x+1<<" "<<i+1<<"\n";
        for(ll i=y-1;i>=0;i--) cout<<x+1<<" "<<i+1<<"\n";
        return 0;
    }
    if(m==1){
        for(ll i=x;i<n;i++) cout<<i+1<<" "<<y+1<<"\n";
        for(ll i=x-1;i>=0;i--) cout<<i+1<<" "<<y+1<<"\n";
        return 0;
    }

    // right
    for(ll i=y;i<m;i++) cout<<x+1<<" " <<i+1<<"\n"; 
    //left
    for(ll i=y-1;i>=0;i--) cout<<x+1<<" "<<i+1<<"\n";

    //left
    bool left=0;
    for(ll i=x-1;i>=0;i--){
        if(left){
            for(ll j=m-1;j>=0;j--) cout<<i+1<<" "<<j+1<<"\n";
            left=0;
        }
        else{
            for(ll j=0;j<m;j++) cout<<i+1<<" "<<j+1<<"\n";
            left=1;
        }
    }

    for(ll i=x+1;i<n;i++){
        if(left){
            for(ll j=m-1;j>=0;j--) cout<<i+1<<" "<<j+1<<"\n";
            left=0;
        }
        else{
            for(ll j=0;j<m;j++) cout<<i+1<<" "<<j+1<<"\n";
            left=1;
        }
    }
}
