/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc208/submissions/29599632
 * Submitted at: 2022-02-23 14:35:17
 * Problem URL: https://atcoder.jp/contests/abc208/tasks/abc208_b
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int p; cin >> p;
    map<int,int> money;
    vector<int> money_kinds;
    int kaizyo = 1,cnt = 0;
    for(int i=1;i<=10;i++){
        kaizyo *= i;
        money_kinds.push_back(kaizyo);
        money[kaizyo] = 100;
    }
    sort(money_kinds.begin(),money_kinds.end(),[](int a,int b){
        return a > b;
    });
    for(auto k:money_kinds){
        while(p >= k && money[k] > 0){
            p -= k; cnt++; money[k]--;
        }
    }
    cout << cnt << endl;
    return 0;
}