#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <set>
using namespace std;

const int MAXN=3*111111;

const long long INF=2000000000LL*2000000000LL;

long long a[MAXN],b[MAXN],s[MAXN];
int n,i,j,l,r,ll,rr;
long long maxi=-INF;

map<long long,int> m;

int main(){
    ios_base::sync_with_stdio(0);

    cin >> n;

    for (i=1;i<=n;i++){
        cin >> a[i];
        b[i]=max(0LL,a[i]);
    }
    s[0]=0;
    for (i=1;i<=n;i++){
        s[i]=s[i-1]+b[i];
    }

    for (r=1;r<=n;r++){
        if (m.find(a[r])==m.end()) {
            m[a[r]]=r;
            continue;
        }
        else {
            l=m[a[r]];
            long long sum=s[r]-s[l-1];
            if (a[r]<0) sum+=a[r]*2LL;
            if (sum>=maxi) {
                maxi=sum;
                ll=l;
                rr=r;
            }
        }
    }
    cout << maxi << ' ';
    l=ll;
    r=rr;
    int ans=l-1+n-r;

    for (i=l+1;i<r;i++)
        if (a[i]<0) ans++;

    cout << ans << endl;

    for (i=1;i<=n;i++){
        if (i<l) cout << i << ' ';
        else if (i>r) cout << i << ' ';
        else if (i>l && i<r && a[i]<0) cout << i << ' ';
    }

    return 0;
}
