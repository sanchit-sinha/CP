#include "bits/stdc++.h"
using namespace std; 
#define ll int
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int main(){
    IOS;
    string s;
    vector<string>v;
    cin>>s;
    sort(s.begin(),s.end());
    do{
        v.push_back(s);
    }
    while(next_permutation(s.begin(),s.end()));
    cout<<(int)(v.size())<<endl;
    for(ll i=0;i<(int)(v.size());++i) cout<<v[i]<<"\n";
}
