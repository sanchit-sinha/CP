#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
const ll N=2e5+11;
ll a[N],n;
int main(){
    IOS;
    cin>>n;
    ll sum=0;
    for(ll i=0;i<n;i++)
        cin>>a[i],sum+=a[i];

    sort(a,a+n);

   cout << max(sum,2*a[n-1]);
}
