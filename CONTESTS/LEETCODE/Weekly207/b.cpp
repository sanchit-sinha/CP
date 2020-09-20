#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll unsigned long long

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}

class Solution {
public:
        int maxUniqueSplit(string s) {
                ll n=(int)s.size();
                ll ans=LLONG_MIN;
                ll len = (1ll<<(n+1));
                for(ll i=0;i<len;i++){
                        ll temp=i;
                        vector<ll> bit(n , 0);

                        ll index=0;
                        while(temp) bit[index++]=temp%2 , temp/=2;

                        bit[0]=1;
                        set<string> t;
                        for(ll j=0;j<n;j++){
                                char c=s[j];
                                if(bit[j]){
                                        string x;
                                        while(j<n){
                                                char c=s[j];
                                                x.push_back(c);
                                                j++;
                                                if(bit[j]){
                                                        j--;
                                                        break;
                                                }
                                                else j++;
                                        }
                                        t.insert(x);
                                }
                        }
                        ans=max(ans , (int)t.size());
                }
                return ans;
        }
};
