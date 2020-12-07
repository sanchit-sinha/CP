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