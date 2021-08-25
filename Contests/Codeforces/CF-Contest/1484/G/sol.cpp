#include "bits/stdc++.h"
using namespace std;

#define SIEVE
// finding shortest prime factor in O(nlog(n))
const long long mX = 1;
long long spf[mX];
void sieve (){
    spf[1] = 1;
    for(long long i = 2 ; i < mX ; i++){
         if(spf[i] == 0){
            spf[i] = i;
            for (long long j =  i * i ; j < mX ; j += i){
                if(spf[j] == 0) spf[j] = i;
            }
        }
    }
} 
void solve(){
     
}

int main(){
    cout<<fixed<<setprecision(20);
    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        factorial();
    #endif
    long long NTC=1;
    // cin>>NTC;
    long long PTC=0;
    while((PTC++)<NTC){
        // cout<<"Case #"<<PTC<<":"<<' ';
        solve();
        //cout<<"\n";
    }
    //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}

long long power(long long x,long long y){if(y==0) return 1;long long a=power(x,y/2);if(y%2==0) return a*a;else return x*a*a;}
long long powermod(long long x,long long ex,long long md){long long ans=1long long;while(ex>0){if(ex&1long long) ans=(ans*x)%md; ex>>=1long long;x=(x*x)%md;}return ans;}