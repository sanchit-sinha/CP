#include "bits/stdc++.h"
using namespace std; 
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
map<int,int>ct;
int main(){
    IOS;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ct[x-1]++;
    }
    int ans;
    ans=min(ct[0]+ct[1],ct[1]+ct[2]);
    ans=min(ans,ct[0]+ct[2]);
    cout<<ans<<"\n";
}
