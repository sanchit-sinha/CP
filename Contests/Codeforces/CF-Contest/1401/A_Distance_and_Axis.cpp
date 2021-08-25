#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
       IOS;
       ll T;
       cin>>T;
       while(T--){
               ll n,k;
               cin>>n>>k;
                if(n<=k) cout<<k-n<<"\n";
                else if((n+k)&1 || (n-k)&1) cout<<1<<"\n";
                else cout<<"0\n";
       }    
}