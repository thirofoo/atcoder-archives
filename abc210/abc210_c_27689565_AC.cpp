/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc210/submissions/27689565
 * Submitted at: 2021-12-04 19:37:01
 * Problem URL: https://atcoder.jp/contests/abc210/tasks/abc210_c
 * Result: AC
 * Execution Time: 226 ms
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
    int n,k;
    cin >> n >> k;
    vector<int> color(n);
    for(int i=0;i<n;i++)cin >> color[i];

    map<int,int> map;
    rep(i,k) map[color[i]]++;
    int ans = map.size();

    for(int i=k;i<n;i++){
        map[color[i]]++;
        map[color[i-k]]--;
        if(map[color[i-k]] == 0)map.erase(color[i-k]);
        int size = map.size();
        ans = max(ans,size);
    }
    cout << ans << endl;
    return 0;
}