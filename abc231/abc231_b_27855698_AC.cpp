/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc231/submissions/27855698
 * Submitted at: 2021-12-12 00:04:56
 * Problem URL: https://atcoder.jp/contests/abc231/tasks/abc231_b
 * Result: AC
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    vector<string> tohyo(n);
    set<string> name;
    vector<pair<string,int>> count;
    rep(i,n){
        cin >> tohyo[i];
        name.insert(tohyo[i]);
    }
    int number = name.size();
    rep(i,number){
        count.push_back(make_pair(*name.begin(),0));
        name.erase(*name.begin());
    }
    rep(i,n)rep(j,count.size())if(tohyo[i] == count[j].first)count[j].second++;
    sort(count.begin(),count.end(),[](pair<string,int> a,pair<string,int> b){
        return a.second > b.second;
    });
    cout << count[0].first << endl;
    return 0;
}