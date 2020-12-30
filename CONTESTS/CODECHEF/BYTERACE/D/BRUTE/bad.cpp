#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define S size()
#define E end()
#define B begin()
#define L length()
 
#define endl "\n"
#define cnt count
#define in insert
#define er erase
#define fi first
#define se second
#define fl float
#define ld long double
#define ll long long

#define gcd __gcd
#define mp make_pair
#define pb push_back
#define popb pop_back()
#define pf push_front
#define popf pop_front()
#define all(v) v.B,v.E
#define acc(v) accumulate(all(v), 0)
#define psum partial_sum
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define np next_permutation
#define maxe *max_element
#define mine *min_element
 
#define forl(i,n) for(ll i = 0; i < n; i++)
#define fore(i,m,n) for (ll i = m; i <= n; i++)
#define rforl(i,n) for (ll i = n - 1; i >= 0; i--)
#define rfore(i,m,n) for (ll i = m; i >=n; i--)    
#define iter(s) for(auto it:s)
 

#define prec(n) fixed<<setprecision(n)
#define popcnt(n) __builtin_popcountll(n)
#define parity(n) __builtin_parityll(n)
#define clz(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctzll(n)

#define sll set<ll>
#define sc set<char>
#define mll map<ll,ll>
#define vll vector<ll>
#define vc vector<char>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define msll multiset<ll>
#define msc multiset<char>
#define vvll vector<vector<ll>>
#define rev reverse

#define tc ll q;cin>>q;while(q--)
#define pat ll n;cin>>n
#define pat1 vll a(n);forl(i,n)cin>>a[i]
#define pat2 ll n,k;cin>>n>>k;vll a(n);forl(i,n) cin>>a[i]
#define pats string s;cin>>s
#define yesno if(flag)cout<<"YES\n";else cout<<"NO\n"
#define loop forl(i,n)

#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a,b) cout << a << " " << b << endl
#define p3(a,b,c) cout << a << " " << b << " " << c << endl
#define p4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
 
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define mod1 1000000007
#define mod2 998244353
#define PI 3.1415926535897932384626433832
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define oset tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
#define ofk order_of_key
#define fbo find_by_order
using namespace std;
void printarr(ll a[],ll n){
    forl(i,n){
        p0(a[i]);
    }
    cout<<endl;
}
void printv(vector<ll>&v){
    forl(i,v.S){
        p0(v[i]);
    }
    cout<<endl;
}
vector<ll> res;
void factorize(ll n) {
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
}
vll divs;
void divisor(ll n){
        for(ll i=2;i<=sqrt(n);i++){
            if(n%i==0){
                divs.pb(i);
                if(n/i!=i){
                    divs.pb(n/i);
                }
            }
        }
        divs.pb(1);
        if(n!=1){
            divs.pb(n);
        }
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
//unordered_map<ll,ll,custom_hash>mp;
//Pythagorean Triplets-2n+1,2n^2+2n,2n^2+2n+1
//**********************************
ll a[100001];
ll dp[100001][3];
ll rec(ll l,ll r,ll sel){
    if(l==r){
        if(sel==0){
            return 0;
        }else if(sel==1){
            return a[l];
        }else{
            return a[l];
        }
    }else if(r-l==1){
        if(sel==0){
        return 0;
        }else if(sel==1){
            return max(a[l],a[r]);
        }else{
            return a[l]+a[r];
        }
    }else{
        if(dp[l][sel]!=-1){
            return dp[l][sel];
        }else{
        if(sel==0){
            return dp[l][sel]=max(rec(l+1,r-1,0),max(rec(l+1,r-1,1),rec(l+1,r-1,2)));
        }else if(sel==1){
            return dp[l][sel]=max(rec(l+1,r-1,0),rec(l+1,r-1,1))+max(a[l],a[r]);
        }else{
            return dp[l][sel]=max(rec(l+1,r-1,0),rec(l+1,r-1,1))+a[l]+a[r];
        }
        }
    }
}
 
 
//             “Those who cannot acknowledge themselves will eventually fail”-Itachi Uchiha
int main(){
   FAST;
   tc{
      ll n,x;
      cin>>n>>x;
      forl(i,n){
          cin>>a[i];
      }
      ll ans=0;
      memset(dp,-1,sizeof(dp));
      //p1(max(rec(0,n-1,0),rec(0,n-1,1)));
      if(max(rec(0,n-1,0),rec(0,n-1,1))>=x){
          p1("YES");
      }else{
          p1("NO");
      }
      
  
  
  
  
  
   }
   
}