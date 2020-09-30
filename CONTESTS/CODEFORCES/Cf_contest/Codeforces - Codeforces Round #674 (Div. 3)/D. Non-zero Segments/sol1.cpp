/**
 *    Author:  Sanchit Sinha
 *    Created: 28.09.2020 14:30:11       
**/
#include "bits/stdc++.h"
#include <iostream>
#include <unordered_map>
using namespace std; 

#define ll long long 
ll powermod(ll x,ll ex,ll md){ll ans=1ll;while(ex>0){if(ex&1ll) ans=(ans*x)%md; ex>>=1ll;x=(x*x)%md;}return ans;}
inline ll gcd(ll a,ll b) {if(b==0)return a;a%=b;return gcd(b,a);}
inline ll max(ll a,ll b) {return((a>b)?a:b);}
inline ll min(ll a,ll b) {return((a>b)?b:a);}


vector< pair<ll,ll>> intervalss;
ll ans=0;
// Function to print all sub-arrays with 0 sum present
// in the given array
void printallSubarrays(ll arr[], ll n)
{
	// create an empty multi-map to store ending index of all
	// sub-arrays having same sum
	unordered_multimap<ll, ll> map;

	// insert (0, -1) pair llo the map to handle the case when
	// sub-array with 0 sum starts from index 0
	map.insert(pair<ll, ll>(0, -1));

	ll sum = 0;

	// traverse the given array
	for (ll i = 0; i < n; i++)
	{
		// sum of elements so far
		sum += arr[i];

		// if sum is seen before, there exists at-least one
		// sub-array with 0 sum
		if (map.find(sum) != map.end())
		{
			auto it = map.find(sum);
                        bool enter=0;

			// find all sub-arrays with same sum
			while (it != map.end() && it->first == sum)
			{
                                enter = 1;
                                intervalss.push_back(make_pair(i , it->second+1));
				// cout << "Subarray [" << it->second + 1 << ".." << i << "]\n";
				it++;
			}
                        if(enter) ans++;
		}

		// insert (sum so far, current index) pair into multi-map
		map.insert(pair<ll, ll>(sum, i));
	}
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        printallSubarrays(a,n);
        cout<<ans-1<<"\n";
        return 0;

        ll len=(int)intervalss.size();
        sort(intervalss.begin() , intervalss.end());
        ll ans=0;
        if(len==0) cout<<"0\n";
        else{
                ll prev = intervalss[0].first;
                ans =1;
                for(ll i=1;i<len;i++){
                        ll r=intervalss[i].first;
                        ll l = intervalss[i].second;

                        if(l >= prev){
                                ans++;
                                prev = r;
                        }
                }
                cout << ans<<"\n";
        }
        return 0;
}
