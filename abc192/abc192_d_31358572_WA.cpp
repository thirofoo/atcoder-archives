/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc192/submissions/31358572
 * Submitted at: 2022-04-30 15:49:49
 * Problem URL: https://atcoder.jp/contests/abc192/tasks/abc192_d
 * Result: WA
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

string x; ll m;
bool check(ll d){
    vector<ll> tmp;
    ll n = m;
    while(n){
        tmp.push_back(n%d);
        n /= d;
    }
    reverse(tmp.begin(),tmp.end());
    if(tmp.size() > x.size())return true;
    else if(tmp.size() < x.size())return false;

    int size = tmp.size();
    rep(i,size){
        if(x[i]-'0' < tmp[i])return true;
        else if(x[i]-'0' > tmp[i])return false;
    }
    return true;
}

int main() {
    cin >> x >> m;
    if(x.size() == 1)return cout << (m >= x[0]-'0' ? 1 : 0) << endl,0;
    ll d = -1;
    rep(i,x.size())d = max(d,(ll)(x[i]-'0'));
    ll left = d,right = (ll)1e18+1;
    while(right-left > 1){
        ll mid = (right+left)/2;
        if(check(mid))left = mid;
        else right = mid;
    }
    cout << left << " " << d << endl;
    cout << left-d << endl;
    return 0;
}