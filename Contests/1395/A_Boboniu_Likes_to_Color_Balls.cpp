#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
    IOS;
    ll t;
    cin>>t;
    while(t--){
    ll r,g,b,w;
    cin>>r>>g>>b>>w;
    ll odd=0,even=0;
    if(r&1) odd++;
    else even++;

    if(b&1) odd++;
    else even++;

    if(g&1) odd++;
    else even++;

    if(w&1) odd++;
    else even++;

    if(odd==1 && even==3) cout<<"Yes\n";
    else if(even==4) cout<<"Yes\n";
    else{
        r--,g--,b--;
        if(r<0 || b<0 || g<0) cout<<"No\n";
        else{
            w+=3;
            odd=0,even=0;
            if(r&1) odd++;
            else even++;

            if(b&1) odd++;
            else even++;

            if(g&1) odd++;
            else even++;

            if(w&1) odd++;
            else even++;

            if(odd==1 && even==3) cout<<"Yes\n";
            else if(even==4) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    }
}

