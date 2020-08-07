#include "bits/stdc++.h"
using namespace std; 
#define ll long long 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int main(){
    IOS;
    string s;
    ll ans=-LLONG_MAX;
    cin>>s;
    for(ll i=0;i<(int)(s.size());i++){
        char c=s[i];
        ll ct=0;
        while(s[i]==c) i++,ct++;
        i--;
        ans=max(ans,ct);
    }
    cout<<ans<<"\n";
}
