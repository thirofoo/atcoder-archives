/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc249/submissions/31220716
 * Submitted at: 2022-04-24 09:53:40
 * Problem URL: https://atcoder.jp/contests/abc249/tasks/abc249_b
 * Result: AC
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

int main() {
    string s; cin >> s;
    map<char,int> a;
    int size = s.size();

    bool frag = true;
    rep(i,size)if('A' <= s[i] && s[i] <= 'Z')frag = false;
    if(frag)return cout << "No" << endl,0;

    frag = true;
    rep(i,size)if('a' <= s[i] && s[i] <= 'z')frag = false;
    if(frag)return cout << "No" << endl,0;
 
    rep(i,size){
        if(a[s[i]])return cout << "No" << endl,0;
        a[s[i]]++;
    }
    cout << "Yes" << endl;
    return 0;
}