/**
 *    Author:  Sanchit Sinha
 *    Created: 25.10.2020 16:37:14       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll T;
    for(ll n=2;;n+=2){
            ll b[n];
            vector<pair<ll,ll>> v;
            for(ll i=0;i<n;i++){
                ll x=rand(1,1000);
                // cout << x <<" ";
                b[i]=x;
                v.push_back({x,i});
            }
            // return 0;
            // /*
            sort(v.begin(),v.end());
            ll ans[n]={0};
            ll mx=0;
            for(ll i=n-1;i>=1;i--){
                ll index=v[i].second;
                if(i==n-1){
                    mx=v[i].first;
                    ans[index]=1;
                }
                else{
                    // 2 3 4 5 100s
                    if(v[i].first<mx){
                        mx-=v[i].first;
                        ans[index]=-1;
                        v[i].first=0;
                    }
                    else{
                        // 2' 3' 4 5
                        v[i].first+=mx;
                        mx=v[i].first;
                        ans[index]=1;
                    }
                }
            }
            ll x=0;
            for(ll i=0;i<n;i++){
                x+=(ans[i]*b[i]);
            }
            // cout << x <<" : ";
            // for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
            // cout<<"\n";
            ll y=v[0].first;
            for(ll i=0;i<n;i++){
                if(ans[i]!=0) ans[i]*=y;
            }
            ans[v[0].second]=-x;
            ll sum=0;
            for(ll i=0;i<n;i++) sum+=(ans[i]*b[i]);
            cout << n << ": "<< sum<<"\n";
            if(sum!=0){
                for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
                cout<<"\n";
            }
            // */
        }
    }    