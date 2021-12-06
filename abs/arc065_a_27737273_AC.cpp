/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abs/submissions/27737273
 * Submitted at: 2021-12-06 19:06:39
 * Problem URL: https://atcoder.jp/contests/abs/tasks/arc065_a
 * Result: AC
 * Execution Time: 10 ms
 */

#include <bits/stdc++.h>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < n; ++i)

int main(){
    string s;
    cin >> s;
    bool frag = true;
    while(frag && s.size() >= 5){
        if(s.substr(s.size()-5,5) == "dream" || s.substr(s.size()-5,5) == "erase"){
            s.erase(s.size()-5);
            continue;
        }
        else if(s.size() >= 6 && s.substr(s.size()-6,6) == "eraser"){
            s.erase(s.size()-6);
            continue;
        }
        else if(s.size() >= 7 && s.substr(s.size()-7,7) == "dreamer"){
            s.erase(s.size()-7);
            continue;
        }
        frag = false;
    }
    if(s == "")cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}