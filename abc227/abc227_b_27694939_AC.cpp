/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc227/submissions/27694939
 * Submitted at: 2021-12-04 22:52:58
 * Problem URL: https://atcoder.jp/contests/abc227/tasks/abc227_b
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < n; ++i)

int main(){
    int n;
    int count = 0;
    cin >> n;
    vector<int> s(n);
    rep(i,n)cin >> s[i];
    set<int> s_set;
    for(int i=1;i<1000;i++){
        for(int j=1;j<1000;j++){
            if(4*i*j+3*i+3*j <= 1000)s_set.insert(4*i*j+3*i+3*j);
        }
    }
    rep(i,n){
        if(s_set.count(s[i]))continue;
        count++;
    }
    cout << count << endl;
    return 0;
}