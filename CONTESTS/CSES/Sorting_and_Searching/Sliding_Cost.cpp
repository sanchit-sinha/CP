#include "bits/stdc++.h"
using namespace std; 

#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define ll long long 

const ll N=2e5+11;
ll n,k,a[N];
multiset<ll ,less<ll>> max_heap;
multiset<ll ,greater<ll>> min_heap;
ll mn_sum,mx_sum;

int main(){
    IOS;
    cin>>n>>k;
    for(ll i=0;i<n;i++)
        cin>>a[i];

    vector<ll> first_window;
    for(ll i=0;i<k;i++) first_window.push_back(a[i]);
    sort(first_window.begin(),first_window.end());

    for(ll i=0;i<k;i++){
        if(i<(k+1)/2) {
            min_heap.insert(first_window[i]);
            mn_sum+=first_window[i];
        }
        else{
            max_heap.insert(first_window[i]);
            mx_sum+=first_window[i];
        }
    }

    ll median=*min_heap.begin();
    cout<<(median*((k+1)/2)-mn_sum)+(mx_sum-(median*(k/2)))<<" ";

    for(ll i=k;i<n;i++){
        // ai <= median -> insert in min_heap
        if(a[i]<=median) {
            min_heap.insert(a[i]);
            mn_sum+=a[i];
        }
        else {
            max_heap.insert(a[i]);
            mx_sum+=a[i];
        }

        // a[i-k] <= median -> delete from min heap
        if(a[i-k]<=median){
            min_heap.erase(min_heap.find(a[i-k]));
            mn_sum-=a[i-k];
        }
        else {
            max_heap.erase(max_heap.find(a[i-k]));
            mx_sum-=a[i-k];
        }
        // resizing
        ll size_of_min_heap=(int)min_heap.size();
        ll size_of_max_heap=(int)max_heap.size();

        if(size_of_min_heap<size_of_max_heap+(k&1)){
            // max->min
            ll top=*max_heap.begin();
            max_heap.erase(max_heap.begin());
            min_heap.insert(top);
            mx_sum-=top,mn_sum+=top;
        }
        else if(size_of_min_heap>size_of_max_heap+(k&1)){
            // min->max
            ll top=*min_heap.begin();
            min_heap.erase(min_heap.begin());
            max_heap.insert(top);
            mn_sum-=top,mx_sum+=top;
        }

        median=*min_heap.begin();
        cout<<(median*((k+1)/2)-mn_sum)+(mx_sum-(median*(k/2)))<<" ";
    }


}
