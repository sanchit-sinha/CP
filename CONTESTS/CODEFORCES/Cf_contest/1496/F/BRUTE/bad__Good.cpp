#include "bits/stdc++.h"
using namespace std;
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define pb push_back
#define ll long long
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
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 1e5+11;

#define mod 1000000007
long long divisorProduct(int n) { 
    long long product = 1; 
    for(int i=1; i*i<=n; i++){ 
        if (n%i == 0){ 
            if (n/i == i) product = (product*i)%mod; 
            else{ 
                product = (product*i)%mod; 
                product = (product*(n/i))%mod; 
            } 
        } 
    } 
    return product; 
} 

bool compare(pair<int, long long> a, pair<int, long long> b){
    return a.first > b.first;
}

vector<int> solve2(vector<int> &A, vector<int> &B) {
    int n=A.size();
    vector<int> leftFreq(n, 1);
    vector<int> rightFreq(n, 1);
    for(int i=1; i<n; i++){
        int prev=i-1;
        while(prev>=0 && A[prev]<=A[i]){
            leftFreq[i] += leftFreq[prev];
            prev -= leftFreq[prev];
        }
    }
    for(int i=n-2; i>=0; i--){
        int next=i+1;
        while(next<n && A[next]<A[i]){
            rightFreq[i] += rightFreq[next];
            next += rightFreq[next];
        }
    }
    
    vector<pair<int, long long>> numFreq(n);
    for(int i=0; i<n; i++) numFreq[i] = {divisorProduct(A[i]), leftFreq[i]*rightFreq[i]};
    sort(numFreq.begin(), numFreq.end(), compare);
    vector<long long> cumFreq(n);
    cumFreq[0]=numFreq[0].second;
    for(int i=1; i<n; i++) cumFreq[i] = numFreq[i].second + cumFreq[i-1];
    
    vector<int> ans;
    for(int i=0; i<B.size(); i++){
        auto id=lower_bound(cumFreq.begin(), cumFreq.end(), B[i])-cumFreq.begin();
        ans.push_back(numFreq[id].first);
    }
    return ans;    
}
void solve(){
	ll n;
	cin >> n;
	vector<int> A(n , 0);
	rep(i , n) cin >> A[i];

	ll q;
	cin >> q;
	vector<int> B(q , 0);
	rep(i , q) cin >> B[i];

	vector<int> ans = solve2(A,B);
	rep(i , q) cout << ans[i] << " ";
	cout << "\n";
}

int main(){
    IOS;
    cout<<fixed<<setprecision(20);
    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        factorial();
    #endif
    ll NTC=1;
    // cin>>NTC;
    ll PTC=0;
    while((PTC++)<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
