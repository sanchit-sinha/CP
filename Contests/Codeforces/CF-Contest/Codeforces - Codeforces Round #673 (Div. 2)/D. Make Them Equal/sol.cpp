/**
 *    Author:  Sanchit Sinha
 *    Created: 28.09.2020 08:12:43       
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
                ll n;
                cin>>n;
                ll a[n],sum=0;
                for(ll i=0;i<n;i++) cin>>a[i],sum+=a[i];
                if(sum%n!=0) cout<<"-1\n";
                else{
                        bool ok=1;
                        sum/=n;
                        vector< pair<pair<ll,ll> ,ll >> ans;
                        for(ll i=1;i<n;i++){
                                ll index=i+1;
                                ans.push_back(make_pair(make_pair(index , 1) , (a[i]/index)));
                                a[i] -= (a[i]/index)*index;
                                a[0] += (a[i]/index)*index;
                        }
                        /*
                        for(ll i=1;i<n;i++){
                                if(a[i]>sum){
                                        ll dif=a[i]-sum , index=i+1;
                                        ans.push_back(make_pair(make_pair(index , 1) , dif/index));
                                        a[0]+=(dif/index)*index;
                                        a[i]-=(dif/index)*index;
                                }
                        } 
                        */               
                        for(ll i=1;i<n;i++){
                                if(a[i]>sum){
                                        ll index=i+1;
                                        ll add=(sum+index - a[i]);
                                        ans.push_back(make_pair((make_pair(1 , index)) , add));
                                        a[0]-=add;
                                        a[i]+=add;
                                        if(a[0]<0) ok=0;
                                        ans.push_back(make_pair(make_pair(index , 1) , 1));
                                        a[0]+=index;
                                        a[i]=sum;
                                }
                        }

                        for(ll i=1;i<n;i++){
                                if(a[i]<sum){
                                        ll index=i+1;
                                        ll dif = sum - a[i];
                                        ans.push_back(make_pair(make_pair(1 ,index) ,dif));
                                        a[0] -= dif;
                                        a[i] = sum;
                                }
                        }
                        if(ok){
                                ll len=(int)ans.size();
                                cout<<len<<"\n";
                                for(ll i=0;i<len;i++){
                                        cout << ans[i].first.first <<" " << ans[i].first.second <<" " << ans[i].second<<"\n";
                                }
                        }
                        else cout<<"-1\n";
                }               
        }    
        return 0;
}