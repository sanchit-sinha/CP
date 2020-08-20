#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

int main(){
        IOS;
        ll x,k,d;
        cin>>x>>k>>d;
        if(x<0)x=-x;
        ll a=x/d;
        if(a<=k) {
                if(a==k)cout<<x%d<<"\n";
                else{
                        ll pos=x%d;
                        ll neg=d-pos;
                        ll rem=(k-a);
                        if(rem&1) cout<<neg<<"\n";
                        else cout<<pos<<"\n";
                }
        }
        else cout<<abs(x-k*d)<<"\n";
}
