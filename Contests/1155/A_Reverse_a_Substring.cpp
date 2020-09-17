#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
        IOS;
        ll n;cin>>n;
        string s;
        cin>>s;
        for(ll i=0;i<n-1;i++){
                if(s[i+1]<s[i]){
                        cout<<"YES\n";
                        cout<< i+1 <<" " <<i+2<<"\n";
                        return 0;
                }
        }
        cout<<"NO\n";
}
