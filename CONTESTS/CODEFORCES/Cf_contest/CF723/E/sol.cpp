#include "bits/stdc++.h"
using namespace std;
#define f                   first
#define s                   second
#define pb                  push_back
#define ll                  long long
#define ld                  long double
#define lb                  lower_bound
#define ub                  upper_bound
#define mp                  make_pair
#define mt                  make_tuple
#define pll                 pair<ll , ll>
#define vll                 vector<ll>
#define vvll                vector<vll>
#define vpll                vector<pll>
#define all(c)              (c).begin(),(c).end()
#define sz(c)               (int)(c.size())
#define get(x,c)            get<x>(c)
#define trav(a,x)           for(auto a = x.begin() ; a != x.end() ; a++)
#define rep(i, n)           for(int i = 0; i < (n) ; i++)
#define FOR(i, a, b)        for(int i = (a); i <= (b); i++)
#define FORR(i, b, a)       for(int i = (b); i >= (a); i--)

inline ll gcd(ll a,ll b) {if(b == 0) return a; a %= b; return gcd(b , a);}
inline ll max(ll a,ll b) {return((a > b) ? a : b);}
inline ll min(ll a,ll b) {return((a > b) ? b : a);}
ll power(ll x,ll ex);
ll powermod(ll x,ll ex,ll md);

const ll N = 1e5+11;
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

ll swaps(vvll &m , string &s){
    ll n = sz(s);
    vll new_index(n , 0);

    vll index_pointer(26 , 0);
    rep(i , n){
        new_index[i] = m[s[i] - 'A'][index_pointer[s[i] - 'A']++];
    }

    ll op = 0; // no of swaps is equivalent to the number of inversions in the index array
    
    // finding number of inversions 
    rep(i , n){
        op += query(1, 0, n - 1, new_index[i] + 1, n - 1);
        update(1 , 0 , n - 1 , new_index[i] , 1);
    }
    return op;
}
void solve(){
    string s;
    cin >> s;

    ll n = sz(s);
    vvll original_index(26);
    rep(i , n){
        original_index[s[i] - 'A'].pb(i);
    }

    string dif;
    rep(i , 26){
        if(sz(original_index[i])) dif.pb((char)(i + 'A'));
    }

    // same characters will always stay together 
    vector<string> pos;
    do{
        string t;
        rep(i , sz(dif)){
            ll cnt = sz(original_index[dif[i] - 'A']);
            while(cnt > 0) t.pb(dif[i]) , cnt--;
        }
        pos.pb(t);
    } while(next_permutation(all(dif)));

    ll len = sz(pos);

    string ans;
    ll op = 0ll;
    rep(i , len){
        rep(j , n + 5) a[j] = 0;  
        build(1 , 0 , n - 1);
        ll operations = swaps(original_index , pos[i]);

        op = max(op , operations);
        if(op == operations) ans = pos[i];
    }

    cout << ans << "\n";

    // cout << "check\n";
    // rep(j , n + 5) a[j] = 0;  
    // build(1 , 0 ,n - 1);
    // cout << swaps(original_index , ans) <<"\n*****************\n";
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
   
    ll NTC=1;
    cin>>NTC;

    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        factorial();
    #endif 
    #ifdef PREPROCESS
        preprocess();
    #endif
    
    ll PTC=0;
    while((PTC++)<NTC){
        // cout << "Case #" << PTC << ":" << ' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
