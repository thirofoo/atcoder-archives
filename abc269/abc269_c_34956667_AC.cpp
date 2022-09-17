/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc269/submissions/34956667
 * Submitted at: 2022-09-17 23:34:53
 * Problem URL: https://atcoder.jp/contests/abc269/tasks/abc269_c
 * Result: AC
 * Execution Time: 68 ms
 */

/**
*    created: 17.09.2022 20:58:09
**/

#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    using ll = long long;
    ll n;
    cin >> n;
    vector<int> b(70, 0);
    if(n % 2 == 1){
        b[0] = 1;
    }
    ll k = 1;
    
    while(n > 0){
        n /= 2;
        if(n % 2 == 1){
            b[k] = 1;   
        }
        k++;
    }
    vector<ll> ans{0};
    for(ll i = 0; i < 70; i++){
        if(b[i] == 1){
            ll pre = ans.size();
            for(ll j = 1; j < pre; j++){
                ans.push_back(ans[j] + (ll)pow(2LL, i));
            }
            ans.push_back((ll)pow(2LL, i));
        }
    }
    sort(ans.begin(), ans.end());
    for(ll i = 0; i < (ll)ans.size(); i++){
        cout << ans[i] << endl;
    }
    
    return 0;
}