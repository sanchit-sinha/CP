#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}


class Solution {
public:
    string reorderSpaces(string s) {
                ll n=(int)s.size();
                ll ct=0;
                ll words=0;
                vector<string> v;
                for(ll i=0;i<n;i++){
                        char c=s[i];
                        if(c!=' '){
                                string x;
                                while(i<n && s[i]!=' ')x.push_back(s[i]) , i++;
                                i--;
                                v.push_back(x);
                                words++;
                        }
                        else{
                                while(i<n && s[i]==c){
                                        i++,ct++;
                                }
                                i--;
                        }
                }
                if(words==1){
                        string ans;
                        ans+=v[0];
                        for(ll j=0;j<ct;j++) ans.push_back(' ');
                        return ans;
                }
                else{
                        string ans;
                        ll div=ct/(words-1);
                        for(ll i=0;i<words;i++){
                               ans+=v[i];
                               if(i!=words-1)for(ll j=0;j<div;j++) ans.push_back(' ');
                        }
                        ll rem=ct - (words-1)*div;
                        for(ll j=0;j<rem;j++) ans.push_back(' ');
                        return ans;
                }
    }
};