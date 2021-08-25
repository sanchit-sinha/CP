#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
        IOS;
        string s;
        cin>>s;
        ll sum=0;
        ll n=(int)s.size();
        for(ll i=0;i<n;i++) sum+=(s[i]-'0');
        if(sum%9==0 ) cout<<"Yes\n";
        else cout<<"No\n";
}
