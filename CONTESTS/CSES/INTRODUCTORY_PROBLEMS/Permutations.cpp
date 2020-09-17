#include "bits/stdc++.h"
using namespace std; 
#define ll long long 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int main(){
    IOS;
    ll n;cin>>n;
    if(n<=4){
        if(n==1) cout<<n<<"\n";
        else if(n==4) cout<<"2 4 1 3\n";
        else cout<<"NO SOLUTION\n";
    }
    else{
        for(ll i=1;i<=n;i+=2) cout<<i<<" ";
        for(ll i=2;i<=n;i+=2) cout<<i<<" ";
        cout<<"\n";
    }
}
