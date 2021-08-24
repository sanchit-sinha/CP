ll fact[N],invfact[N];
void factorial(){
    fact[0]=invfact[0]=1;
    for(ll i=1;i<N;i++){
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
    }
    invfact[N-1]=powermod(fact[N-1],mod-2,mod);
    for(ll i=N-2;i>0;i--){
        invfact[i]=invfact[i+1]*(i+1);
        invfact[i]%=mod;
    }
}
ll ncr(ll n,ll r){
    if(r > n || n < 0 || r < 0)return 0;
    ll p=(fact[n]*invfact[r])%mod;
    p*=invfact[n-r];
    return p%mod;
}