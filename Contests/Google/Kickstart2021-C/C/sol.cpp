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

const ll N = 1e5+11;


void solve(ll x){
    ll w , e;
    cin >> w >> e;

    string s = "RSP";

    string ans = "";
    rep(i , 20) ans += s;
    cout << ans << "\n";

    cout << "*********************************\n";   

    vll stats(60 , 0);
    map<char , ll > m;
    rep(i , sz(ans)){
        if(i == 0) {
            m[ans[i]]++;
            cout << i + 1 << " : " << ans[i] << " : " <<  'P' ;
            
            char c = 'P';
            cout << " : ";

            ll won = 0;
            if(ans[i] == 'R'){
                if(c == 'R') won =  -1 ;
                else if(c == 'P') won =  0;
                else if(c == 'S') won =  1;
            }
            else if(ans[i] == 'P'){
                if(c == 'R') won =  1;
                else if(c == 'P') won =  -1;
                else won = 0;
            }
            else if(ans[i] == 'S'){
                if(c == 'R') won =  0;
                else if(c == 'P') won =  1;
                else if(c == 'S') won = -1 ;
            }

            cout << won << " ";

            stats[i] = won;
            cout << "\n";
        }
        else{
            ld mx = 0.0;
            trav(it , m){
                ll cnt = it->s;
                ld val = (1.0 * cnt)/i;
                cout << it->f << " " << val << "\n";
                mx = max(mx , val);
            }

            // cout << i << " : " << mx <<"\n\n";

            char c = '?';
            trav(it , m){
                ll cnt = it->s;
                ld val = (1.0 * cnt)/i;

                if(mx == val){
                    c = it->f;
                    break;
                }
            }

            cout << i + 1 << " : " << ans[i] << " : ";
            char choose = '?';
            if(c == 'R') choose =  'P';
            else if(c == 'S') choose =  'R';
            else choose = 'S';

            c = choose;
            cout <<  mx << " : " << c ;

            cout << " : ";
            ll won = 0;
            if(ans[i] == 'R'){
                if(c == 'R') won =  -1 ;
                else if(c == 'P') won =  0;
                else if(c == 'S') won =  1;
            }
            else if(ans[i] == 'P'){
                if(c == 'R') won =  1;
                else if(c == 'P') won =  -1;
                else won = 0;
            }
            else if(ans[i] == 'S'){
                if(c == 'R') won =  0;
                else if(c == 'P') won =  1;
                else if(c == 'S') won = -1 ;
            }

            stats[i] = won;
            cout << won << " ";
            cout << "\n\n";

            m[ans[i]]++;
        }
    }
        cout << "\n";

        ll won = 0 , lose = 0, draw = 0;
        rep(i , 60){
            won += (stats[i] == 1);
            lose += (stats[i] == 0);
            draw += (stats[i] == -1);
        }

        cout << "won : " << won << " lose : " << lose << " : draw " << draw << "\n";

        ll score = won * w + draw * e;
        cout << "score " << score << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
   
    ll NTC=1;
    ll x;
    cin>>NTC;
    cin >> x;

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
        cout << "Case #" << PTC << ":" << ' ';
        solve(x);
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

ll power(ll x,ll y){if(y==0) return 1;ll a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
