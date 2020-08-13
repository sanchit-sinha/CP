#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
const ll N=4e5+11;
ll p[N],n;

int main(){
    IOS;
    ll T;
    cin>>T;
    while(T--){
        for(ll i=0;i<n+1;i++) p[i]=0;
        cin>>n;
        for(ll i=1;i<n+1;i++) cin>>p[i]; 
        ll g=0,s=0,b=0;
        if(n<6) cout<<"0 0 0\n";
        else{
            ll l=1,r=n/2;
            ll rnxt=p[r+1];
            ll new_right=r;
            for(ll i=r;i>=1;i--){
                if(p[i]==rnxt) new_right--;
                else break;
            }
        
        // cout << l <<" " << new_right<<"\n\n";
    
            ll mx=p[1];
            for(ll i=1;i<=new_right;i++){
                if(p[i]==mx) g++;
                else break;
            }
            l=g+1;
        
            // cout << l <<" " << new_right<<"\n\n";

            ll mn=p[new_right];
            for(ll i=new_right;i>=l;i--){
                if(p[i]==mn || b<=g) {
                    b++;
                    mn=max(mn,p[i]);
                }
                else break;
            }

            new_right-=b;

            // cout << l <<" " << new_right<<"\n\n";

            s=(new_right-l+1);
            if(g==0||b==0||s==0 || s<=g) cout<<"0 0 0\n";
            else cout<<g<<" "<<s<<" "<<b<<"\n";
        }
    }    
}