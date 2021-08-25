/**
 *    Author:  Sanchit Sinha
 *    Created: 04.10.2020 21:46:14       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}


ll computeCost(ll arr[], ll N, ll X)
{
    ll cost = 0;
    for (ll i = 0; i < N; i++)
        cost += abs(arr[i] - X);
    return cost;
}

pair<ll,ll> minCostToMakeElementEqual(ll arr[], ll N)
{
    ll low, high;
    low = high = arr[0];
 
    // setting limits for ternary search by
    // smallest and largest element
    for (ll i = 0; i < N; i++) {
        if (low > arr[i])
            low = arr[i];
        if (high < arr[i])
            high = arr[i];
    }
 
    /* loop until difference between low and high
       become less than 3, because after that
       mid1 and mid2 will start repeating
    */
    while ((high - low) > 2) {
 
        // mid1 and mid2 are representative array
        // equal values of search space
        ll mid1 = low + (high - low) / 3;
        ll mid2 = high - (high - low) / 3;
 
        ll cost1 = computeCost(arr, N, mid1);
        ll cost2 = computeCost(arr, N, mid2);
 
        // if mid2 point gives more total cost,
        // skip third part
        if (cost1 < cost2)
            high = mid2;
 
        // if mid1 point gives more total cost,
        // skip first part
        else
            low = mid1;
    }
 
    // computeCost gets optimum cost by sending
    // average of low and high as X
    return make_pair((low+high)/2 , computeCost(arr, N, (low + high) / 2));
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll T;
        cin>>T;
        while(T--){
                ll n,m;
                cin>>n>>m;
                vector<vector<ll>>a(n , vector<ll>(m , 0));
                for(ll i=0;i<n;i++){
                        for(ll j=0;j<m;j++) cin>>a[i][j];
                }
                ll ans=0;
                for(ll i=0;i<n;i++){
                        for(ll j=0;j<m;j++){
                                ll x=a[i][j];
                                ll y=a[n-1-i][j];
                                ll z=a[i][m-1-j];
                                ll k=a[n-1-i][m-1-j];

                                ll arr[4] ={x,y,z,k};
                                // cout << i << ": " << j << " : " << x <<" " << y <<' ' << z << " " << k<<"\n";
                                pair<ll,ll> p =minCostToMakeElementEqual(arr,4);

                                ll val = p.first;
                                
                                a[i][j] = val;
                                // cout << i <<" " << j <<" : \n";
                                a[n-1-i][j] = val;
                                // cout << n-1-i <<" " << j <<" : \n";
                                a[i][m-j-1] = val;
                                // cout << i <<" " << m-1-j <<" : \n";
                                a[n-1-j][m-j-1] = val;
                                // cout << n-1-i <<" " << m-j-1 <<" : \n";
                                
                                // cout << val <<" " << p.second<<"\n\n";
                                ans+= p.second;
                                // cout <<" ----------------\n";
                                // for(ll ii=0;ii<n;ii++){
                                //         for(ll jj=0;jj<m;jj++) cout<<a[ii][jj]<<" ";
                                // cout<<"\n";
                                // }
                                // cout<<"---------------\n";
                        }
                }

                // for(ll i=0;i<n;i++){
                //         cout << i <<" : ";
                //         for(ll j=0;j<m;j++) cout<<a[i][j] <<" ";
                //         cout<<"\n";
                // }
                cout << ans<<"\n";
        }    
        return 0;
}