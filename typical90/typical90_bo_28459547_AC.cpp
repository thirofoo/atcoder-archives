/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28459547
 * Submitted at: 2022-01-11 12:03:09
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bo
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll ch8to10(string n){
    ll a = 1; ll to10 = 0;
    for(int i=n.size()-1;i>=0;i--){
        to10 += (n[i]-'0')*a;
        a *= 8;
    }
    return to10;
}

string ch10to9(ll a){
    string to9 = "";
    while(a%9 != a){
        to9.insert(0,to_string(a%9));
        a /= 9;
    }
    to9.insert(0,to_string(a));
    rep(i,to9.size())if(to9[i] == '8')to9[i] = '5';
    return to9;
}

int main() {
    string n,tmp;int k; cin >> n >> k;
    rep(i,k){
        if(i == 0)tmp = ch10to9(ch8to10(n));
        else tmp = ch10to9(ch8to10(tmp));
    }
    cout << tmp << endl;
    return 0;
}