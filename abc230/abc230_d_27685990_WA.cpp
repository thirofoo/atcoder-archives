/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc230/submissions/27685990
 * Submitted at: 2021-12-04 16:19:33
 * Problem URL: https://atcoder.jp/contests/abc230/tasks/abc230_d
 * Result: WA
 * Execution Time: 130 ms
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
    int n,d;
    int j = 1;
    int ans = 0;
    cin >> n >> d;
    vector<pair<int,int>> wall;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        wall.push_back(make_pair(a,b));
    }
    sort(wall.begin(),wall.end());
    for(int i=0;i<n;i++){
        for(j;j<n;j++){
            if(wall[j].first <= wall[i].second+d-1)continue;
            break;
        }
        if(i == j){
            j++;
            continue;
        }
        i = j-1;
        ans++;
    }
    cout << ans << endl;
    return 0;
}