#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

ll zero,one,two,three;
int main(){
    IOS;
    cin>>zero>>one>>two>>three;
    bool done=0;

    if(one==0 && zero==0 && !done){
        if(two==0 && !done){
            if(three==1){
                cout<<"YES\n";
                cout<<"3 \n";
                done=1;
            }
            else cout<<"NO\n",done=1;
        }

        if(three==0 && !done){
            if(two==1){
                cout<<"YES\n";
                cout<<"2 \n";
                done=1;
            }
            else cout<<"NO\n",done=1;
        }

        if(two==three && !done){
            // 2323
            cout<<"YES\n";
            for(ll i=0;i<two;i++) cout<<"2 3 ";
            cout<<"\n";

            done=1;
        }
        
        if(two==three+1 && !done){
            //  232
            cout<<"YES\n";
            cout<<"2 ";
            for(ll i=0;i<three;i++) cout<<"3 2 ";
            cout<<"\n";

            done=1;
        }
        
        if(three==two+1 && !done){
            //  323
            cout<<"YES\n";
            cout<<"3 ";
            for(ll i=0;i<two;i++) cout<<"2 3 ";
            cout<<"\n";

            done=1;
        }

        if(!done) cout<<"NO\n",done=1;
        return 0;
    }

    if(two==three&& two==0 && !done){
        if(one==0 && !done){
            if(zero==1){
                cout<<"YES\n";
                cout<<"0 \n";
                done=1;
            }
            else cout<<"NO\n",done=1;
        }

        if(zero==0 && !done){
            if(one==1) cout<<"YES\n1\n",done=1;
            else cout<<"NO\n",done=1;
        }

        if(one==zero && !done){
            // 0101
            cout<<"YES\n";
            for(ll i=0;i<zero;i++) cout<<"1 0 ";
            cout<<"\n";

            done=1;
        }
        
        if(one==zero+1 && !done){
            // 10101 
            cout<<"YES\n";
            cout<<"1 ";
            for(ll i=0;i<zero;i++) cout<<"0 1 ";
            cout<<"\n";

            done=1;
        }
        
        if(zero==one+1 && !done){
            cout<<"YES\n";
            cout<<"0 ";
            for(ll i=0;i<one;i++) cout<<"1 0 ";
            cout<<"\n";
            done=1;
        }

        if(!done) cout<<"NO\n",done=1;
        return 0;
    }

    if(!done && (zero>one || three>two)) cout<<"NO\n";
    else{
        
        ll rem_one=0,rem_two=0;
        // case1 : 0101 .. 2323 or 0101 21 2323
        rem_one=one-zero,rem_two=two-three;
        if(rem_one==rem_two && !done){
            cout<<"YES\n";
            
            for(ll i=0;i<zero;i++) cout<<"0 1 ";
            for(ll i=0;i<rem_one;i++) cout<<"2 1 ";
            for(ll i=0;i<three;i++) cout<<"2 3 ";
            cout<<"\n";
            
            done=1;
        }

        // 0101 .. 23232 or 0101 .21.. 23232
        rem_one=one-zero , rem_two=two-1-three;
        if(!done && rem_two>=0 && rem_one==rem_two){
            cout<<"YES\n";

            for(ll i=0;i<zero;i++) cout<<"0 1 ";
            for(ll i=0;i<rem_one;i++) cout<<"2 1 ";
            for(ll i=0;i<three;i++) cout<<"2 3 ";
            cout<<"2";
            cout<<"\n";
            
            done=1;
        }

        // 10101 .. 2323 or 10101 .. 21 .. 2323
        rem_one=one-1-zero , rem_two=two-three;
        if(!done && rem_one>=0 && rem_one==rem_two){
            cout<<"YES\n";
            
            cout<<"1 ";
            for(ll i=0;i<zero;i++) cout<<"0 1 ";
            for(ll i=0;i<rem_one;i++) cout<<"2 1 ";
            for(ll i=0;i<three;i++) cout<<"2 3 ";
            cout<<"\n";
            
            done=1;
        }

        //10101 .. 23232..
        rem_one=one-1-zero , rem_two=two-1-three;
        if(!done && rem_one>=0 && rem_two>=0 && rem_two==rem_one){
            cout<<"YES\n";
            
            cout<<"1 ";
            for(ll i=0;i<zero;i++) cout<<"0 1 ";
            for(ll i=0;i<rem_one;i++) cout<<"2 1 ";
            for(ll i=0;i<three;i++) cout<<"2 3 ";
            cout<<"2";
            cout<<"\n";
            
            done=1;
        }
        
        if(!done) cout<<"NO\n";
    }
}
