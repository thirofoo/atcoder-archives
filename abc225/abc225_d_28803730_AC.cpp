/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc225/submissions/28803730
 * Submitted at: 2022-01-26 12:33:29
 * Problem URL: https://atcoder.jp/contests/abc225/tasks/abc225_d
 * Result: AC
 * Execution Time: 272 ms
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

int main() {
    int n,q; cin >> n >> q;
    vector<int> tree(n+1,0);
    vector<int> tree_reverse(n+1,0);
    queue<int> count;
    rep(i,q){
        int a; cin >> a;
        if(a ==1){
            int x,y; cin >> x >> y;
            tree[x] = y;
            tree_reverse[y] = x;
        }
        else if(a ==2){
            int x,y; cin >> x >> y;
            tree[x] = 0;
            tree_reverse[y] = 0;
        }
        else{
            int tmp; cin >> tmp;
            while(tree_reverse[tmp])tmp = tree_reverse[tmp];
            while(tmp){
                count.push(tmp);
                tmp = tree[tmp];
            }
            cout << count.size() << " ";
            while(!count.empty()){
                int x = count.front(); count.pop();
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}