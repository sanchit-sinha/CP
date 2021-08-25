#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <assert.h>
#include <stack>
#include <string>
#define int long long int
using namespace std;
//author: Legendary Grandmaster mshiladityam
//Simple... for a 900...I guess 
vector<vector<int>> adj;
int n;
void surgery(vector<int> &v)
{
	int k=v.size();
	for (int j=0; j<k-1; j++)
	{
		adj[v[j]].push_back(v[j+1]);
		adj[v[j+1]].push_back(v[j]);
	}
	adj[n].push_back(v[0]);
	adj[v[0]].push_back(n);
}
int solve()
{
	cin>>n;
	adj.resize(n+1);
	vector<int> freq(n+1, 0);
	set<int> s; //unused elements 
	for (int j=1; j<=n; j++)
	{
		s.insert(j);
	}
	bool f = true;
	for (int j=0; j<n-1; j++)
	{
		int a, b; cin>>a>>b;
		if (b!=n)
		{
			f = false;
		}
		freq[a]++;
		if (s.find(a)!=s.end())
		{
			s.erase(a);
		}
	}
	if (!f)
	{
		cout << "NO\n";
		return 0;
	}
	vector<pair<int, vector<int>>> v;
	for (int j=1; j<=n; j++)
	{
		if (freq[j]>0)
		{
			vector<int> d(freq[j]);
			d[freq[j]-1]=j;
			v.push_back({j, d});
		}
	}
	sort(v.begin(), v.end());
	for (int j=0; j<v.size(); j++)
	{
		for (int i=0; i<freq[v[j].first]-1; i++)
		{
			if (s.size()==0)
			{
				cout<<"NO\n";
				return 0;
			}
			if (*s.begin()>v[j].first)
			{
				cout<<"NO\n";
				return 0;
			}
			v[j].second[i]=*s.begin();
			s.erase(s.begin());
		}
		surgery(v[j].second);
	}
	cout<<"YES\n";
	int ct = 0;
	for (int j=1; j<=n; j++)
	{
		for (int i=0; i<adj[j].size(); i++)
		{
			if (adj[j][i]>j)
			{
				ct++;
				// cout<<j<<" "<<adj[j][i]<<"\n";
			}
		}
	}
	// cout << ct << "\n";
	return 0;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	//cin >> t;
	t=1;
	while (t--)
	{
		solve();
	}
	return 0;
}