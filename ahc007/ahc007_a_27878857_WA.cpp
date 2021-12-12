/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc007/submissions/27878857
 * Submitted at: 2021-12-12 19:09:03
 * Problem URL: https://atcoder.jp/contests/ahc007/tasks/ahc007_a
 * Result: WA
 * Execution Time: 40 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    vector<P> locate(0);
    vector<ll> length(0);
    rep(i,400){
        ll a,b;
        cin >> a >> b;
        locate.push_back(make_pair(a,b));
    }
    rep(i,1995){
        ll a,b,length_;
        cin >> a >> b;
        length_ = sqrt(pow(locate[a].first-locate[b].first,2)+pow(locate[a].second-locate[b].second,2));
        length.push_back(length_);    
    }
    sort(length.begin(),length.end());
    rep(i,1995){
        int x;cin >> x;
        ll low = abs(*lower_bound(length.begin(),length.end(),x)-x);
        ll up = abs(*upper_bound(length.begin(),length.end(),x)-x);
        ll good = low > up ? up : low;
        double seido = 1.1;
        if(abs(good+x) >= x*seido && abs(good-x) <= x*seido)cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}