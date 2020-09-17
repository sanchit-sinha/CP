#include "bits/stdc++.h"
using namespace std; 
#define ll long long 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int main(){
    IOS;
    ll n;
    cin>>n;
    ll factor=5,ex5=0;
    while(n){
        ex5+=(n)/factor;
        n/=factor;
    }
    cout<<ex5<<"\n";
}
