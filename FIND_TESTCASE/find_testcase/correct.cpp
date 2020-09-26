#include<bits/stdc++.h>
#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define PI 3.1415926535897932384626
#define all(x) x.begin(), x.end()

typedef long long ll;


using namespace std;

void solve() {

  ll N ;

  ll Ai ;
  
  ll rSum = 0;

  cin>>N;

  for(int i = 0 ; i < N ; i++){
     
      cin>>Ai;
     
       if(Ai > 0){
     	
     	rSum = rSum + Ai%(i+1);
     	
      } else {
     	rSum = rSum + Ai ;
     }

      
  }  
	
	if(rSum == 0) cout<<"YES";
	else cout<<"NO";
			
  cout<<endl;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int T = 1;
//     cin >> T;
    while(T--) {
      solve();
    }

    return 0;
}
