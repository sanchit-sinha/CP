/**
 *    Author:  Sanchit Sinha
 *    Created: 17.10.2020 20:38:28       
**/
#include "bits/stdc++.h"
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        ll twos=0,ones=0;
        set<ll> s;
        for(ll i=0;i<n;i++){
                if(a[i]==1) ones++;
                else if(a[i]==2) twos++;
        }
        
        vector<pair<ll,ll>>ans;
        if(twos>ones){
                cout<<"-1\n";
                return 0;
        }
        else{
                map<ll,ll> ht;
                ll mx_ones_height=0;
                for(ll i=n-1;i>=0;i--){
                        if(a[i]==1){
                                ans.push_back(make_pair(n-mx_ones_height-1,i));
                                ht[i] = mx_ones_height;
                                s.insert(i);
                                mx_ones_height++;
                        }
                }

                ll index=0;
                vector<ll> add;
                for(ll i=n-1;i>=0;i--){
                        if(a[i]==2){
                                bool ok=0;
                                auto it=s.upper_bound(i);
                                if(it==s.end()){
                                        cout<<-1<<"\n";
                                        return 0;
                                }
                                else{
                                        ll possible_col = *it;
                                        ans.push_back(make_pair(n-1-ht[possible_col],i));
                                        
                                        s.erase(it);
                                        add.push_back(i);                                      
                                        index++;
                                }
                        }
                }

                for(ll i=0;i<(int)add.size();i++) s.insert(add[i]);
                for(ll i=n-1;i>=0;i--){
                        if(a[i]==3){
                                auto it=s.upper_bound(i);
                                if(it == s.end()){
                                        cout<<"-1\n";
                                        return 0;
                                }
                                else{
                                        ll possible_col = *it;
                                        ans.push_back(make_pair(n-1-mx_ones_height , i));
                                        ans.push_back(make_pair(n-1-mx_ones_height , possible_col));
                                        mx_ones_height++;

                                        s.erase(it);
                                        s.insert(i);
                                }
                        }
                }
        }

        ll len=(int)ans.size();
        cout<<len<<'\n';
        for(ll i=0;i<len;i++) cout<<ans[i].first+1<<" " <<ans[i].second+1<<"\n";
        return 0;
}
