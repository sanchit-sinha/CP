#include <bits/stdc++.h>
using namespace std; 
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define ld long double
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<b;i++)
#define reprev(i,a,b) for(int i=b-1;i>=a;i--)
#define all(c) c.begin(),c.end()
#define sz(c) (int)c.size()
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vin(a,n) vi a(n); rep(k_,0,n) {cin>>a[k_];}
#define vout(a) rep(k_,0,sz(a)) {cout<<a[k_]<<" ";} cout<<endl;
#define pb push_back
#define mp  make_pair
#define mod 1000000007
#define mod2 998244353
#define inf LLONG_MAX
#define pi 3.1415926535897932384626
#define tr(container, it) \
for(auto it = container.begin(); it != container.end(); it++)

int power(int x, unsigned int y, int p)  
{  
    int res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("./input.txt", "r", stdin);
        freopen("./output.txt", "w", stdout);
    #endif
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d; cin>>a>>b>>c>>d;

        cout<<max(c+d, a+b)<<endl;
    }
    return 0;
}