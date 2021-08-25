/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    #pragma GCC optimize ("-ffloat-store")
    #include<bits/stdc++.h>
    #define dbg(args...) 42;
#endif

using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"
using l128 = __int128;
typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
#endif
}

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli N = 1000000000L;
const lli mod = 360*120*N;
const lli inv11  = 15709090909091LL;
const lli inv719 = 29621140472879LL;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void solve()
{
    vi a(3);
    for(auto &x:a)
        cin>>x;
    if(a[0]==0&&a[1]==0&&a[2]==0){
        cout<<"0 0 0 0"<<endl;
        return;
    }
    auto prt=[&](lli t){
        lli h,m,s,n;
        n=t%N;t/=N;
        dbg(t);
        s=t%60;t/=60;
        m=t%60;t/=60;
        h=t%12;
        cout<<h<<" "<<m<<" "<<s<<" "<<n<<endl;
    };
    vi b(3);
    iota(all(b),0);
    do{
        vector<l128> c;
        for(auto x:b)
            c.pb(a[x]);
        const l128 t=c[2];
        for(auto &x:c)
        {
            x-=t;
            x%=mod;
            x+=mod;
            x%=mod;
        }
        if(c[0]*11%mod!=719*c[1]%mod){
            continue;
        }
        dbg("Hello");
        const lli t1=c[0]*inv719%mod,t2=c[1]*inv11%mod;
        if(t1!=t2)
            continue;
        prt(t1);
        dbg(t1,t2,t1==t2);
        return;
    }while(next_permutation(all(b)));
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
cin>>T;
for(lli tt=1;tt<=T;++tt)
{
    cout<<"Case #"<<tt<<": ";
    solve();
}   aryanc403();
    return 0;
}