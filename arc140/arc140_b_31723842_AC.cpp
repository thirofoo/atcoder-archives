/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc140/submissions/31723842
 * Submitted at: 2022-05-15 22:09:46
 * Problem URL: https://atcoder.jp/contests/arc140/tasks/arc140_b
 * Result: AC
 * Execution Time: 31 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;string s; cin >> n >> s;
    //ARCという文字列があったらそのAのidxをまず集める。
    vector<int> idx;
    rep(i,n-2){
        if(s[i] == 'A' && s[i+1] == 'R' && s[i+2] == 'C')idx.push_back(i);
    }

    //各ARCの横にAとCがあればその個数をカウント。
    map<int,int> ac;
    for(auto k:idx){
        int cnt = 1;
        while(k-cnt >= 0 && k+2+cnt < n){
            if(s[k-cnt] == 'A' && s[k+2+cnt] == 'C')cnt++;
            else break;
        }
        ac[k] = cnt-1;
    }

    queue<int> no;
    priority_queue<int> have;
    deque<int> todo;
    for(auto k:idx){
        if(ac[k] == 0)no.push(1);
        else have.push(ac[k]);
    }
    while(!have.empty()){
        todo.push_back(have.top());
        have.pop();
    }

    
    //acの数が多いARCを大切にしつつACが隣に無いARCを身代わりにする。
    int turn = 0;
    while(!todo.empty() || !no.empty()){
        if(turn%2 == 0){
            int tmp;
            if(!todo.empty()){
                tmp = todo.front();
                todo.pop_front();
                tmp--;
                if(tmp == 0)no.push(1);
                else todo.push_front(tmp);
            }
            else{
                tmp = no.front();
                no.pop();
            }
        }
        else{
            if(!no.empty())no.pop();
            else{
                if(!todo.empty())todo.pop_front();
                else break;
            }
        }
        turn++;
    }
    cout << turn << endl;

    return 0;
}