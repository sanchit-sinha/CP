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
bool iscorrect(string s , ll n , ll k){
    ll ct[26] = {0};

    rep(i , n) ct[s[i] - 'a']++;
    rep(i , 26) if(ct[i]%k) return 0;

    return 1;
}
void solve(){
    ll n , k;
    cin >> n >> k;
    string s;
    cin >> s;

    if(n%k != 0){
        cout << -1 << "\n";
        return ;
    }

    if(iscorrect(s, n, k)){
        cout << s << "\n";
        return ;
    }

    map<ll , ll> m;
    rep(i , n) m[s[i] - 'a']++;

    // finding index of changing position
    ll index = -1;
    FORR(i , n - 1 , 0){
        // change ith position
        ll ele = s[i] - 'a';
        m[ele]--;
        if(m[ele] == 0) m.erase(m.find(ele));

        ll ct[26] = {0};
        ll sum = 0;
        trav(it , m){
            ll ele = it->f;
            ct[ele] = m[ele];
            
            ll div = (ct[ele] + k - 1)/k;
            ct[ele] = div * k;
            
            sum += ct[ele];

            ct[ele] -= m[ele];
        }        

        ll mx = 0;
        rep(i , 26) if(ct[i]) mx = max(mx , i);

        if(sum == n){
            if(mx > ele){
                index = i;
                break;
            }
        }
        else{
            if(sum < n){
                if(sum%k == 0){
                    index = i;
                    break;
                }
            }
        }

    }

    // finding new string using the changing position
    if(index == -1) cout << index << "\n";
    else{
        string ans;
        m.clear();
        FOR(i , 0 , index - 1){
            ll ele = s[i] - 'a';

            auto it = m.find(ele);
            if(it == m.end()) m[ele] += k;

            m[ele]--;
            if(m[ele] == 0) m.erase(m.find(ele));
            
            ans.pb(s[i]);
        }

        ll ct = 0;
        trav(it , m) ct += (it->s);

        ll ele = s[index] - 'a';
        ll rem = (n - 1 - index + 1);

        if(ct == rem){
            // cant use extra elements
            auto it = m.ub(ele);
            if(it == m.end()){
                cout << -1 << "\n";
                return ;
            }
            else{
                ll x = (it->f);
                ans.pb(x + 'a');

                m[x]--;
                if(m[x] == 0) m.erase(m.find(x));
            }
        }
        else if(ct < rem){
            // can use extra elements
            ll dif = rem - ct;
            if(dif%k){
                cout << -1 << "\n";
                return;
            }
            else{
                // the suitable element to be used at the changing position is the element just greater than ele
                ll just_greater = ele + 1;
                auto it = m.find(just_greater);
                if(it == m.end()){
                    // (ele + 1) is not already present in the set of elements to be used
                    m[just_greater] += k;
                    ans.pb(just_greater + 'a');

                    m[just_greater]--;
                    if(m[just_greater] == 0) m.erase(m.find(just_greater));
                
                    dif -= k;
                    // add 'a' at remaining places 
                    m[0] += dif;
                }
                else{
                    // ele + 1 is already present 
                    ans.pb(just_greater + 'a');

                    m[just_greater]--;
                    if(m[just_greater] == 0) m.erase(m.find(just_greater));

                    // add 'a' at remaining places
                    m[0] += dif;

                }
            }
        }
        else {
            cout << -1 << "\n";
            return ;
        }

        while(!m.empty()){
            ll ele = (m.begin())->f;
            ll cnt = m[ele];


            rep(i , cnt) ans.pb(ele + 'a');
            m.erase(m.find(ele));
        }
        cout << ans << "\n";   
    }

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
    cin>>NTC;
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
                            