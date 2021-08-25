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

const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const ld PI = acos(-1);
const ld eps = 1e-9;

const ll N = 5e4 + 11;
ll n , x[N] , y[N] , z[N];
bool removed[N];
map<ll , set<ll>> mx;
vpll ans;

void add(ll x , ll y){
    assert(!removed[x]);
    assert(!removed[y]);
    
    removed[x] = 1;
    removed[y] = 1;
    ans.pb(mp(x + 1 , y + 1));
}

void solve(){
    cin >> n;
    rep(i , n) cin >> x[i] >> y[i] >> z[i];

    rep(i , n) mx[x[i]].insert(i);


    // cout <<" oldx \n";
    // cout << "***************\n";
    // trav(it3 , mx){
    //     cout << "x : " << it3 ->f << ": ";
    //     trav(it4 , it3->s) cout << *it4 << " ";
    //     cout << "\n";
    // }
    // cout << "***************\n";
    // cout << "\n";
    // O(diff x * diff y * diff z) = O(n);
    trav(it , mx){
        map<ll , set<ll>> my;
        trav(itt , it->s) my[y[*itt]].insert(*itt);

        // cout << "x : \n";
        // trav(it2 , it->s) cout << *it2 << " ";
        // cout << "\n";

        // cout << "checky : \n";
        // cout << "##########3\n";
        // trav(it2 , my){
        //     cout << " y : " <<  it2->f << " : ";
        //     trav(it3 , it2->s) cout << *it3 << " "; 
        //     cout << "\n";
        // }
        // cout << "##########3\n";
        // cout << "\n";
        trav(it1 , my){ // diff z of same x & y 
            while(sz(it1->s) > 1){
                ll index = *(it1->s).begin();

                if(removed[index]){
                    auto itr = (it1->s).find(index);
                    if(itr == (it1->s).end()) (it1->s).erase(itr);
                }
                else{
                    auto itl = (it1->s).begin();
                    ll index1 = *itl;

                    itl++;
                    ll index2 = *itl;

                    if(!removed[index1] && !removed[index2]){
                        add(index1 , index2);

                        auto itf1 = (it1->s).find(index1);
                        auto itf2 = (it1->s).find(index2);

                        if(itf1 != (it1->s).end()) (it1->s).erase(itf1);
                        if(itf2 != (it1->s).end()) (it1->s).erase(itf2);
                    }
                    else{
                        if(removed[index1]){
                            auto itr = (it1->s).find(index1);
                            if(itr == (it1->s).end()) (it1->s).erase(itr);
                        }
                        if(removed[index2]){
                            auto itr = (it1->s).find(index2);
                            if(itr == (it1->s).end()) (it1->s).erase(itr);
                        }
                    }
                }
            }
        }

        // cout <<" newx \n";
        // cout << "***************\n";
        // trav(it3 , mxx){
        //     cout << "x : " << it3 ->f << ": ";
        //     trav(it4 , it3->s) cout << *it4 << " ";
        //     cout << "\n";
        // }
        // cout << "***************\n";
        // cout << "\n";

    }

    mx.clear();
    rep(i , n){
        if(!removed[i]) mx[x[i]].insert(i);
    }

    // cout << sz(ans) << "\n";
    // trav(it , mxx){
    //     cout << "into " << it->f << " : ";
    //     trav(it2 , it->s) cout << *it2 << " ";
    //     cout << "\n";
    // }

    trav(it , mx){
        while(sz(it->s) > 1){ // dif y of same x
            auto itl = (it->s).begin();
            ll index1 = *itl;

            itl++;
            ll index2 = *itl;

            add(index1 , index2);

            auto it1 = (it->s).find(index1);
            auto it2 = (it->s).find(index2);

            if(it1 != (it->s).end()) (it->s).erase(it1);
            if(it2 != (it->s).end()) (it->s).erase(it2);
        }   
    }

    mx.clear();
    rep(i , n){ // dif x
        if(!removed[i]) mx[x[i]].insert(i);
    }

    // cout << "after removing x \n";
    // trav(it , mxx){
    //     cout << "into " << it->f << " : ";
    //     trav(it2 , it->s) cout << *it2 << " ";
    //     cout << "\n";
    // }
    // return ;

    assert(sz(mx)%2 == 0); // all should be even
    while(!mx.empty()){
        auto it = mx.begin();
        ll index1 = *(it->s.begin());
        ll xx1 = x[index1];

        it++;
        ll index2 = *(it->s.begin());
        ll xx2 = x[index2];

        add(index1 , index2);

        auto it1 = mx.find(xx1);
        auto it2 = mx.find(xx2);
        if(it1 != mx.end()) mx.erase(it1);
        if(it2 != mx.end()) mx.erase(it2);
    }

    // cout << sz(ans) << "\n";
    rep(i , sz(ans)) cout << ans[i].f << " " << ans[i].s << "\n";
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
   
    ll NTC=1;
    // cin>>NTC;

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
