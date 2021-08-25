#include "bits/stdc++.h"
using namespace std; 
#define ll long long 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int main(){
    IOS;
    string s;
    cin>>s;
    ll n=(int)(s.size());
    ll ct[26]={0};
    for(ll i=0;i<n;i++) ct[s[i]-'A']++;
    ll odd=0;
    for(ll i=0;i<26;i++) if(ct[i]&1) odd++;
    if(odd>1){
        cout<<"NO SOLUTION\n";
    }
    else{
        string ans,x;
        char c;
        for(ll i=0;i<26;i++){
            for(ll j=0;j<ct[i]/2;j++) ans.push_back((char)('A'+i));
            if(ct[i]&1) c=(char)(i+'A');
        }
        x=ans;
        reverse(ans.begin(),ans.end());
        if(odd) x+=c+ans;
        else x+=ans;
        cout<<x<<endl;
    }
}
