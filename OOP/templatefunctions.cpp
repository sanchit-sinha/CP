// checking whether a number is prime or not
ll isprime(ll n){
    if(n==1) return 0;
    else if(n==2) return 1;
    else{
        for(ll i=2;i<=sqrt(n);i++){
            if(n%i==0) return 0;
        }
    return 1;   
    }
}
// returning vector containing all prime numbers less than a given number
vector<ll> get_prime_factors_less_than(ll n){
    vector<ll> factor;
    vector<ll> prime(n,1);
    prime[0]=0,prime[1]=0;
    for(ll i = 2 ; i <= n ; i++){
        if(prime[i]==1){
            for(ll j=i*i;j<=n;j=j+i) prime[j]=0; 
            factor.push_back(i);
        }
    }
    return factor;
}

// finding shortest prime factor//SPF -- Nlog(n)
ll spf[mX];
void seive (){
    spf[1] = 1;
    for (ll i = 2; i < mX; i++){
        if (spf[i] == 0){
            spf[i] = i;
            for (ll j = 1ll * i * i; j < mX; j += i){
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
}


ll power(ll x, ll y) { if (y == 0) return 1;  ll a = power(x,y/2);if (y % 2 == 0) return a * a; else return x * a * a; }
ll powermod(ll x, ll ex , ll md) {ll ans = 1ll;while (ex > 0) {    if (ex & 1ll) ans = (ans * x) % md;    ex >>= 1ll;x = (x * x) % md;}

// finding prime factors in sqrt logn
vector<ll> prime;
ll temp= x;
for(ll i = 2 ; i <= sqrt(x) ; i++){
    if(temp%i == 0){
        while(temp%i == 0) temp /= i;
        prime.pb(i);

    }
}
if(temp != 1) prime.pb(temp);