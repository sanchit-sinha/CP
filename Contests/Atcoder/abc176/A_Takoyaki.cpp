#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
        IOS;
        ll n,x,t;
        cin>>n>>x>>t;
        cout<<((n-1+x)/x)*t<<"\n";
}
