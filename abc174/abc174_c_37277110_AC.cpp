/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc174/submissions/37277110
 * Submitted at: 2022-12-15 09:53:21
 * Problem URL: https://atcoder.jp/contests/abc174/tasks/abc174_c
 * Result: AC
 * Execution Time: 1802 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

struct Timer {
    timespec start;

    void begin() {
        clock_gettime(CLOCK_REALTIME, &start);
    }

    double stopwatch() {
        timespec end;
        clock_gettime(CLOCK_REALTIME, &end);
        double sec = end.tv_sec - start.tv_sec;
        double nsec = end.tv_nsec - start.tv_nsec;
        return sec + 1e-9 * nsec;
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll k; input(k);
    ll ans = 1,now = 7%k;
    Timer timer;
    timer.begin();
    bool f = false;
    while(timer.stopwatch() <= 1.8){
        if(now == 0){
            f = true;
            break;
        }
        now *= 10;
        now += 7;
        now %= k;
        ans++;
    }
    print(f ? ans : -1);
    
    return 0;
}