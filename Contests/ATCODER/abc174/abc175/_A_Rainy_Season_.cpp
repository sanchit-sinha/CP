#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
        IOS;
        string s;
        cin>>s;
        ll n=(int)s.size();
        ll ans=0;
        for(ll i=0;i<n;i++){
                char c=s[i];
                ll ct=0;
                if(c=='R'){
                while(s[i]=='R' && i<n)i++,ct++;
                ans=max(ans,ct);
                i--;
                }
        }
        cout<<ans<<"\n";
}
