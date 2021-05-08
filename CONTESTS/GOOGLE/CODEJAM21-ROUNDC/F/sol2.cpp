#include "bits/stdc++.h"
using namespace std;
int main(){
	int test;
	cin >> test;	
	while(test--){
		long long n , k , w;
		cin >> n >> k >> w;
		long long a[n];
		long long b[n];
		long long cost[n];
		for(int i=0;i<n;i++) cin >> a[i] >> b[i];
		multiset<pair< pair<long long,long long >,long long> > m;
		long long time = a[0];
		int i = 0 ;
		while(i < n && a[i] <= time){
			pair< pair<long long,long long > ,long long > p = make_pair(make_pair(b[i] , a[i]) , i);
			m.insert(p);
			i++;
		}
		while(i < n){
			if((int)m.size() == 0){
				time = a[i];
				pair<pair<long,long >,long long> p = make_pair(make_pair(b[i],a[i]),i);
				m.insert(p);
				i++;
			}
			while(!m.empty()){
				auto it = m.begin();
				pair< pair<long,long >,long long > first_item = *it;
				long long preperationtime = first_item.first.first;
				long long ordertime = first_item.first.second;
				long long c=k*preperationtime-w*(time - ordertime);
				time = time + preperationtime;
				if(c < 0) c = 0;
				cost[first_item.second] = c;
				m.erase(it);
			}
			while(i < n && a[i] <= time){
				pair<pair<long,long >,long long> p = make_pair(make_pair(b[i],a[i]),i);
				m.insert(p);
				i++;
			}
		}
		while((int)m.size()){
			auto it = m.begin();
			pair<pair<long long,long long>,long long > first_item = *it;
			long long preperationtime = first_item.first.first;
			long long ordertime = first_item.first.second;
			long long c=k*preperationtime - w*(time - ordertime);
			time = time + preperationtime;
			if(c < 0) c = 0;
			cost[first_item.second] = c;
			m.erase(it);
		}	
		for(int i=0;i<n;i++) cout << cost[i] << " ";
		cout << "\n";
	}
}