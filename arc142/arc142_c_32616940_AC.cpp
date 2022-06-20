/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc142/submissions/32616940
 * Submitted at: 2022-06-20 12:19:48
 * Problem URL: https://atcoder.jp/contests/arc142/tasks/arc142_c
 * Result: AC
 * Execution Time: 15 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,m = INT_MAX; cin >> n;
    vector<int> p;
    for(int i=3;i<=n;i++){
        cout << "? " << 1 << " " << i << endl;
        int d1,d2; cin >> d1;
        cout << "? " << 2 << " " << i << endl;
        cin >> d2;
        m = min(d1+d2,m);
        if(d1+d2 == 3)p.push_back(i);
    }
    if(m != 3)return cout << "! " << m << endl,0;
    if(p.size() == 1)return cout << "! " << 1 << endl,0;
    cout << "? " << p[0] << " " << p[1] << endl;
    int d; cin >> d;
    if(d == 1)cout << "! " << 3 << endl;
    else cout << "! " << 1 << endl;

    return 0;
}