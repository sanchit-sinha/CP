#include<bits/stdc++.h>
#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626
#define all(x) x.begin(), x.end()

typedef long long ll;



using namespace std;



bool checkDivisibility(int n, int digit) 
{ 
    
    return (digit != 0 && n % digit == 0); 
} 
  


void solve() {

  ll n;
  cin>>n;

     int temp = n; 


    while (temp > 0) { 
  
        
        int digit = temp % 10;
        
        
        if(digit != 0){
            
            if (!(checkDivisibility(n, digit))){
            n = n + 1;
            temp = n;
        }
            
        }
        
        
            
  
        temp /= 10; 
    } 

    cout<<n;



}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}
