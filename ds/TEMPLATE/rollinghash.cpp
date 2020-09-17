    // storing hash values of prefixes of string
    const ll pr_for_hash = 31;
    const ll mod_for_hash = 1e9 + 9;
    int len = s.size();
    vector<ll> hash_value(len + 1, 0);
    vector<ll> power_for_hash(len  , 1);
    for(int i = 1 ;i < len ; i++){
        power_for_hash[i] = (power_for_hash[i - 1] * pr_for_hash) % mod_for_hash;
    }
    // index based hashing
    for(int i = 0 ; i < len ; i++){
        hash_value[i] = ((s[i] - 'a' + 1) * power_for_hash[i]) % mod_for_hash;
        if(i != 0) hash_value[i] += hash_value[i - 1] ;
        hash_value[i] %= mod_for_hash;
    }


    // function to compute hash value
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}



    /*ROLLING HASH
    Rabin-Karp algorithm for pattern matching in a string in O(n) time
    Calculating the number of different substrings of a string in O(n2logn)
    Calculating the number of palindromic substrings in a string.
    */
    
// 0 - indexed hashing
// const ll PR = 31;
// ll primeNum2 = 53;
// const ll  MOD = 1e9 + 9;
// incase of large hash queries use double hashing with two primes
class rollinghash{
   public:
   string s;
   ll PR;
   ll MOD;
   vector<ll> ro;
   vector<ll> minv;
   vector<ll> pw;
   rollinghash(string s , ll pr , ll mod){
      s = ss; PR = pr; MOD = mod; int N = (int) s.length(); ll p = 1ll, val = 0;
      ro.resize(N); minv.resize(N + 1); pw.resize(N + 1);
      for(int i = 0; i < N ; i++){
          val += (((s[i] - 'a' + 1) * p) % MOD); val %= MOD; p = (p * PR)%MOD; ro[i] = val;
      }
      pw[0] = 1; minv[0] = 1; minv[1] = powermod(PR , MOD - 2, MOD);
      for(int i = 1; i <= N ; i++) pw[i] = (pw[i - 1] * PR) % MOD;
      for(int i = 2; i <= N ; i++) minv[i] = (minv[i - 1] * minv[1]) % MOD; 
   }
   ll get(int ii , int jj){
     return ((minv[ii] * (ro[jj] - ((ii - 1 >= 0) ? ro[ii - 1] : 0)))%MOD + MOD)%MOD;
   }
};
// constructing rolling has of prefixes -rollinghash r (str , PR , MOD);
// getting prefix of substring - r.get(l1 , r1)