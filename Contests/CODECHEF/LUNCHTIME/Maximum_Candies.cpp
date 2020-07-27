#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll t;cin>>t;
    while(t--){
        ll n,m,x,y;
        cin>>n>>m>>x>>y;
        if(n*m==1){
            cout<<x<<"\n";
        }
        else{
            if(y<=x){
                cout<<(((n*m)+1)/2)*y<<"\n";
            }
            else if(y>x && y<=2*x){
                ll mx=max(y-x,x),mn=min(y-x,x);
                cout<<(((n*m)+1)/2)*mx + ((n*m)/2)*mn<<"\n"; 
            }
            else{
                cout<<n*m*x<<"\n";
            }
        }
    }    
}

//
2
1 1 6 4
1 3 2 4