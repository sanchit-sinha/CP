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

const ll N = 3e5+11;

ll tree[4*N],a[N];
ll pull(ll l,ll r){
    ll p = (l + r); //operation
    return p;            
}
void build(ll node,ll l,ll r){
    if(l==r) tree[node]=a[l];
    else{
        ll mid=l+(r-l)/2;
        build(2*node,l,mid);
        build(2*node+1,mid+1,r);
        
        tree[node] = pull(tree[node*2],tree[node*2+1]);
    }
}
void update(ll node,ll l,ll r,ll index,ll val){
    if(index>r || index<l) return ;
    if(l==r) a[index]=val , tree[node]=val; //update operation
    else{
        ll mid=l+(r-l)/2;
        update(node*2,l,mid,index,val);
        update(node*2+1,mid+1,r,index,val);
        
        tree[node] = pull(tree[node*2],tree[node*2+1]);
    }
}
ll query(ll node,ll l,ll r,ll start,ll end){
    if(end<l || start>r) return 0; //operation (inf , -inf , 0 ...)
    else if(start<=l && end>=r) return tree[node];
    else{
        ll mid=l+(r-l)/2;
        ll p1=query(2*node,l,mid,start,end);
        ll p2=query(2*node+1,mid+1,r,start,end);
        
        return pull(p1,p2); //operation
    }
}
//build(1,0,n-1) .... query(1,0,n-1,l,r) .... update(1,0,n-1,x,a[x])
ll n , q , col[N];
void solve(){
    cin >> n >> q;

    FOR(i , 0  , n - 1) cin >> col[i];
    map<ll , multiset<ll> > m;
    FOR(i , 0 , n - 1){
        m[col[i]].insert(i);
    }

    // rep(i , n) cout << col[i] <<  " ";
    // cout << "\n";

    // return;

    build(1 , 0 , n - 1);
    while(q--){
        ll x;
        cin >> x;

        ll index = *m[x].begin();
        ll pos = query(1, 0 , n - 1 , 0 , index);

        ll newindex = index + pos;

        update(1, 0, n - 1, 0 , a[0] + 1);
        update(1, 0, n - 1, index , a[index] - 1);
        // a[0] += 1;
        // a[index] -= 1;
        
        ll temp = a[index] - newindex;
        update(1, 0, n - 1, index , a[index] - newindex);

        update(1, 0, n - 1, index + 1 , a[index + 1] + newindex);
        // a[index] -= (newindex - 1);
        // a[index + 1] += (newindex - 1);

        cout << pos << " : " << newindex << "\n";
        cout << "ORINGINAL " << index << "\n";
        rep(i , n) cout << i << " ";
        cout << "\n";
        rep(i , n) cout << a[i] << " ";
        cout << "\n";
        rep(i , n){
            cout << i + query(1, 0, n - 1, 0, i) << " ";
        }
        cout << "\n\n";

        cout << newindex + 1 << " ";
    }
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
