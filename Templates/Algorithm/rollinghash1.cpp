class rollinghash{
   public:
   string s;
   ll PR;
   ll MOD;
   vector<ll> ro;
   vector<ll> minv;
   vector<ll> pw;
   rollinghash(string ss , ll pr , ll mod){
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