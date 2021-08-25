#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 
string s,t;
bool good[26];
ll bad;
set<pair<ll,ll>> hashes;
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
// 0 - indexed hashing
// PR = 31,53 ; MOD = 1e9 + 9;
class rollinghash{
        public:
        ll PR,MOD;
        vector<ll> ro,minv;
        rollinghash(string s,ll pr,ll mod){
                PR=pr;MOD=mod;int N=(int)s.length();ll p=1ll,val=0;
                ro.resize(N);minv.resize(N + 1);
                for(int i=0;i<N;i++){
                        val+=(((s[i]-'a'+1)*p)%MOD); val%=MOD; p=(p*PR)%MOD; ro[i]=val;
                }
                minv[0]=1;minv[1]=powermod(PR,MOD-2,MOD);
                for(int i=2;i<=N;i++) minv[i]=(minv[i-1]*minv[1])%MOD; 
        }
        ll get(int ii,int jj){
                return ((minv[ii]*(ro[jj]-((ii-1>=0)?ro[ii-1]:0)))%MOD+MOD)%MOD;
        }
};
// constructing rolling has of prefixes -rollinghash r (str , PR , MOD);
// getting prefix of substring - r.get(l1 , r1)
int main(){
        IOS;
        cin>>s>>t>>bad;
        ll n=(int)s.size();
        for(ll i=0;i<26;i++) good[i]=t[i]-'0';
        rollinghash r1(s,31,1e9+7);
        rollinghash r2(s,53,1e9+7);
        for(ll i=0;i<n;i++){
                ll ct=0;
                for(ll j=i;j<n;j++){
                        if(!good[s[j]-'a']) ct++;
                        if(ct<=bad){
                                hashes.insert(make_pair(r1.get(i,j) , r2.get(i,j)));
                        }
                }
        }
        cout<<(int)hashes.size()<<"\n";
}
