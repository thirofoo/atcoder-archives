/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/41930929
 * Submitted at: 2023-06-03 18:51:17
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_i
 * Result: AC
 * Execution Time: 734 ms
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
typedef pair<ld, ld> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

double getangle2(double I1, double I2) {
	double res = abs(I1 - I2);
	if (res >= 180.0) return 360.0 - res;
	return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    // 解説AC 偏角sort
    // 各頂点を原点と見なした時の偏角を前計算 → 二分探索
    ll n; input(n);
    vector<P> v;
    rep(i,n){
        ld x,y; input(x,y);
        v.push_back(P(x,y));
    }

    ld ans = 0;
    rep(i,n){
        auto &&[x1,y1] = v[i];
        vector<ld> angle;
        rep(j,n){
            if(i == j)continue;
            auto &&[x2,y2] = v[j];
            ld dx = x2-x1, dy = y2-y1;
            angle.push_back( atan2(dx,dy)*180.0 / M_PI );
        }
        sort(angle.begin(),angle.end());

        ld cand = 0.0;
        for(auto a:angle){
            ld ideal = a + 180.0;
            if(ideal >= 360.0)ideal -= 360.0;
            int pos1 = lower_bound(angle.begin(), angle.end(), ideal) - angle.begin();

		    // 点 C の候補は高々 2 つに絞れる
		    int CandIdx1 = pos1 % angle.size();
		    int CandIdx2 = (pos1 + angle.size() - 1) % angle.size();
		    ld Candidate1 = getangle2(a, angle[CandIdx1]);
		    ld Candidate2 = getangle2(a, angle[CandIdx2]);
		    cand = max({ cand, Candidate1, Candidate2 });
        }
        ans = max(ans,cand);
    }
    print(ans);
    
    return 0;
}