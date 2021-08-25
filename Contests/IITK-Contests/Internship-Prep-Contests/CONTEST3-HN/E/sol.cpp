/******************READ-ONLY PART BEGINS*****************/
#include <bits/stdc++.h>
using namespace std;
/*******************READ-ONLY PART ENDS******************/

#define ll long long
long long getNumberOfOptions(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D, int budgeted) {
    vector<ll> price;
    ll mx = 1ll * budgeted;

    ll a = (int)A.size();
    ll b = (int)B.size();
    ll c = (int)C.size();
    ll d = (int)D.size();

    for(ll i = 0 ; i < c ; i++){
        for(ll j = 0 ; j < d ; j++) price.push_back(C[i] + D[j]);
    }

    sort(price.begin() , price.end());

    // cout << "PRICE\n";
    // for(ll i =0  ; i < price.size() ; i++) cout << price[i] << " ";
    //     cout << "\n";


    ll ans = 0ll;
    for(int i = 0 ; i < a ; i++){
        for(int j = 0 ; j < b ; j++){
            ll price_remaining = mx - A[i] - B[j];
            auto it = upper_bound(price.begin(), price.end(), price_remaining);

            // cout << A[i] << " " << B[j] << " : " << price_remaining << " " << it - price.begin() << "\n";
            ans += (it - price.begin());
        }
    }

    return ans;
}

/******************READ-ONLY PART BEGINS*****************/
vector<int> process_vec();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto priceOfJeans = process_vec();
    auto priceOfShoes = process_vec();
    auto priceOfSkirts = process_vec();
    auto priceOfTops = process_vec();

    int budgeted; cin >> budgeted;
    auto res = getNumberOfOptions(priceOfJeans, priceOfShoes, priceOfSkirts, priceOfTops, budgeted);
    
    cout << res << endl;
    return 0;
}

vector<int> process_vec() {
    int n; cin >> n;
    vector<int> vec(n);
    for(auto &ele : vec) {
        cin >> ele;
    }

    return vec;
}
/*******************READ-ONLY PART ENDS******************/