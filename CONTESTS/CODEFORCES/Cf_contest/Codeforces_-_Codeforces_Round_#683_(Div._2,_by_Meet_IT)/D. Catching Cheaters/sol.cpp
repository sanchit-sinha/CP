/**
 *    Author:  Sanchit Sinha
 *    Created: 15.11.2020 22:19:12       
**/
#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define nl cout<<"\n"
#define endl "\n"
#define ll int
#define ld long double
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c.size())
#define mp make_pair
#define mt make_tuple
#define get(x,c) get<x>(c)
#define trav(a,x) for(auto a=x.begin();a!=x.end();a++)
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,b,a) for(int i=b;i>=a;i--)
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define f first
#define s second

inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}
ll power(ll x,ll y);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5 + 11;
string lcs(string &X, string &Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++) 
   { 
     for (int j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
  
   // Following code is used to print LCS 
   int index = L[m][n]; 
  
   // Create a character array to store the lcs string 
   char lcs[index+1]; 
   lcs[index] = '\0'; // Set the terminating character 
  
   // Start from the right-most-bottom-most corner and 
   // one by one store characters in lcs[] 
   int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
      // If current character in X[] and Y are same, then 
      // current character is part of LCS 
      if (X[i-1] == Y[j-1]) 
      { 
          lcs[index-1] = X[i-1]; // Put current character in result 
          i--; j--; index--;     // reduce values of i, j and index 
      } 
  
      // If not same, then find the larger of two and 
      // go in the direction of larger value 
      else if (L[i-1][j] > L[i][j-1]) 
         i--; 
      else
         j--; 
   } 
  
   // Print the lcs 
   return lcs; 
} 
ll minWindow(string S, string T) {
    //Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.
    int s = S.size();
    int t = T.size();
    vector<vector<int>> dp(s, vector<int>(t, -1));
    for(int i = 0; i < s; i++) {
        if(S[i] == T[0]) {
            dp[i][0] = i;
        } else {
            if(i != 0) {
                dp[i][0] = dp[i-1][0];
            }
        }
    }
    for(int i = 1; i < s; i++) {
        for(int j = 1; j < t; j++) {
            if(S[i] == T[j]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int begin = -1, length = INT_MAX;
    for(int i = 0; i < s; i++) {
        int index = dp[i][t-1];
        if(index != -1) {
            int curLength = i - index + 1;
            if(curLength < length) {
                begin = index;
                length = curLength;
            }
        }
    }
    if(begin == -1)
        return -1;
    string ans= S.substr(begin, length);
    return (int)ans.size();
}
void solve(){
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    string LCS = lcs(s,t,n,m);
    if(LCS=="") cout<<0<<"\n";
    else{
        ll len=sz(LCS);
        string x;
        ll ans=LLONG_MIN;
        FOR(i,0,len-1){
            x.pb(LCS[i]);
            int l1 = minWindow(s,x);
            int l2 = minWindow(t,x);
            ll val = 4*abs((int)x.size()) - l1 - l2;
            ans=max(ans,val);
        }
        cout<<ans<<"\n";
    }
}
int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    ll NTC=1;
    // cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
