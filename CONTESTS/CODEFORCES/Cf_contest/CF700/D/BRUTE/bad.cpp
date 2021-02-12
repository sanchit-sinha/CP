#include <iostream>
#include<bits/stdc++.h>
#include<functional>
using namespace std;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< long long > vll;
typedef pair< int,int > ii;
typedef long long ll;
#define sz(a) int((a).size())
#define pb push_back
#define mp  make_pair
#define pll pair <ll,ll>
#define mod 1000000007
#define mod2 998244353
#define all(c) c.begin(),c.end()
#define tr(c,i) for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x) (c.find(x) != c.end())
#define cpresent(c,x) (find(all(c),x) != c.end())
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define repn(i,a,b)   for(int i=a;i>=b;i--)
#define fo(i,n) for(ll i=1;i<=n;i++)
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define Yes cout<<"Yes\n"
#define No cout<<"No\n"
#define nl "\n"
#define F first
#define S second 
#define eps 0.0000001
typedef long double ld;
typedef unsigned long long ull;


void ipgraph(int n, int m);
//void dfs(int u, int par);
ll gcd (ll a, ll b);
unsigned long long factorial[2000007]; 
//___________________________________________
 unsigned long long power(unsigned long long x,long long y,int p)
{unsigned long long res=1;x=x%p;while(y>0){if(y&1)
res=(res*x)%p;y=y>>1;x=(x*x)%p;}
return res;}
//__________________________________________
unsigned long long modInverse(unsigned long long n,int p)
{return power(n,p-2,p);}
//_____________________________________________
unsigned long long nc(unsigned long long n,int r,int p)
{if(r==0)
return 1;return(factorial[n]*modInverse(factorial[r],p)%p*modInverse(factorial[n-r],p)%p)%p;}
 int fa[200005];
 int find(int x){if(fa[x]==x)return x;fa[x]=find(fa[x]);return fa[x];}
 int join(int x, int y){
     int a = fa[x];
     int b = fa[y];
     if(a==b)return 0;
     fa[a]=b;
     return 1;
}

void deb(int x , string s){
    cout<<x<<" "<<s<<nl;
}
int range(int l,int r, vi &b){
    return upper_bound(b.begin()+1,b.end(),r) - lower_bound(b.begin()+1,b.end(),l);
}

ll N = mod2;
 
ll mod1(ll n) {return (n % N + N) % N; }
ll modM(ll n, ll m) { return ((n % N * m % N) + N) % N; }
ll modA(ll n, ll m) { return ((n % N + m % N) + N) % N; }
ll modS(ll n, ll m) { return ((n % N - m % N) + N) % N; }



ll dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

/*  */
struct element{
    ll p,q,c;
};

bool com(element x , element y){
    if(x.p == y.p){
        return x.q < y.q;
    }
    else{
        return x.p < y.p;
    }

}
ll lcm(ll a,ll b){
    return (a/gcd(a,b))*b;
}
    bool prime[1000004];
    ll spf[1000004];

void SieveOfEratosthenes(int n) 
{
    fo(i,1000003){
        prime[i]=true;
    }
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        {
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    
} 

void build_spf() 
{ 
    fo(i,1000003){
        spf[i]=i;
    }
    for (int p=2; p*p<=1000003; p++) 
    { 
      if(spf[p]==p){
          for(int j = 2*p ;j<=1000003;j+=p){
              spf[j]=p;
          }
      }  
    } 
  
    
} 
/* const int no = 2e5+5;
bitset<no> b;
unordered_map<int,bool> g[no];
void dfs(int u){
    b[u]=0;
    for(auto i = b._Find_first();i<b.size();i= b._Find_next(i)){
        if(g[u][i]==0){
            dfs(i);
        }
    }
} */



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=1;
/*         factorial[0] = 1; 
for (int i = 1; i <= 2000004; i++) {MIUC
    factorial[i] = (factorial[i - 1] * i) % mod2; 
} */
    //cin>>T;
    //SieveOfEratosthenes(1000001);
   // Google,FB cout << "Case #"<< T + 1 << ": ";
    while(T--){
            int n;
            cin>>n;
            vi a(n+1);
            fo(i,n){
                cin>>a[i];
            }
          /*   stack<int> s1,s0;
            int f=0;
            fo(i,n){
                if(s0.empty()){
                    s0.push(a[i]);
                }
                else if(s1.empty()){
                    s1.push(a[i]);
                }
                else{
                    int p = a[i];
                    if(p== s1.top()&& p == s0.top()){
                        continue;
                    }
                    else if(p==s1.top()){
                        s0.push(a[i]);
                        f=1;
                    }
                    else if(p==s0.top()){
                        s1.push(a[i]);
                        f=0;
                    }
                    else{
                        if(f==0){
                            s0.push(a[i]);
                        }
                        else{
                            s1.push(a[i]);
                        }
                        f^=1;
                    }
                }
            }
            cout<<s1.size()+s0.size()<<nl; */

            ll ans=0;
            int i=-1;
            fo(j,n-1){
                if(a[j]==a[j+1]){
                    i=j;
                    break;
                }
            }
            if(i==-1){
                cout<<n<<nl;
            }
            else{
                int ans=0;
                int prev=-1;
                int pi=-1;
                int np=0;
                for(int k=1;k<=n;){
                    if(k==n){
                        ans++;
                        //cout<<"&\n";
                        k++;
                        continue;
                    }

                    if(a[k]==a[k+1]){
                        if(prev==a[k]){
                            int l = k-pi-1;
                            if(l/2 >np){
                                ans+=2;
                            }
                            else{
                                ans+=1;
                            }
                            while(a[k]==a[k+1] && k<n){
                                k++;
                            }
                            prev=a[k];
                            pi = k;
                            k++;
                            np=0;

                        }
                        else{
                            ans+=2;
                            while(a[k]==a[k+1] && k<n){
                                k++;
                            }
                            prev=a[k];
                            pi = k;
                            k++;
                            np=0;
                        }
                    }
                    else{
                        ans++;
                        if(a[k]==prev){
                            np++;
                        }
                        k++;
                    }
                }
                cout<<ans<<nl;
            }


    
    }








    

    
       
    return 0;
}



ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}



    /*factorial[0] = 1; 
for (int i = 1; i <= 100004; i++) {
    factorial[i] = (factorial[i - 1] * i) % mod; 
}*/
/* ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull m) {
    ull ans = 1;
    for (; e; b = modmul(b, b, m), e /= 2)
        if (e & 1) ans = modmul(ans, b, m);
    return ans;
}
 
bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n-1), d = n >> s;
    for (ull a : A) {   // ^ count trailing zeroes
        ull p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
} */

