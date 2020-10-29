/**
 *    Author:  Sanchit Sinha
 *    Created: 25.10.2020 17:16:11       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll T;
    cin>>T;
    while(T--){
        ll n,m;
        cin>>n>>m;
        ll row_left_to_right[n][m]={0};
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++) cin>>row_left_to_right[i][j];
        }
        ll col_top_to_bottom[m][n]={0};
        for(ll i=0;i<m;i++){
            for(ll j=0;j<n;j++){
                cin>>col_top_to_bottom[i][j];
            }
        }
        map<ll,ll> id_colzero_ele;
        ll index=0;
        set<ll> s;
        for(ll j=0;j<n;j++){
            s.insert(col_top_to_bottom[0][j]);
            id_colzero_ele[col_top_to_bottom[0][j]]=index++;
        }
        ll req_row=0;
        for(ll i=0;i<m;i++){
            bool ok=1;
            for(ll j=0;j<n;j++){
                auto it=s.find(row_left_to_right[j][i]);
                if(it == s.end()) ok=0;
            }
            if(ok) req_row=i;
        }
        map<ll,ll> id_rowzero_ele;
        index=0;
        for(ll i=0;i<n;i++){
            id_rowzero_ele[i]=id_colzero_ele[row_left_to_right[i][req_row]];
        }
        vector<vector<ll>> ans(n,vector<ll>(m,0));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                ans[id_rowzero_ele[i]][j]=row_left_to_right[i][j];
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++) cout<<ans[i][j]<<" ";
            cout<<"\n";
        }
    }    
    return 0;
}