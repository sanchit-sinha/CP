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
