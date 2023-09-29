/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc159/submissions/46038269
 * Submitted at: 2023-09-30 01:28:32
 * Problem URL: https://atcoder.jp/contests/abc159/tasks/abc159_f
 * Result: AC
 * Execution Time: 818 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

template<class T>
struct FormalPowerSeries : vector<T> {
    using vector<T>::vector;
    using vector<T>::operator=;
    using F = FormalPowerSeries;

    F operator-() const {
      F res(*this);
      for (auto &e : res) e = -e;
      return res;
    }
    F &operator*=(const T &g) {
        for (auto &e : *this) e *= g;
        return *this;
    }
    F &operator/=(const T &g) {
        assert(g != T(0));
        *this *= g.inv();
        return *this;
    }
    F &operator+=(const F &g) {
        int n = (*this).size(), m = g.size();
        rep(i, min(n, m)) (*this)[i] += g[i];
        return *this;
    }
    F &operator-=(const F &g) {
        int n = (*this).size(), m = g.size();
        rep(i, min(n, m)) (*this)[i] -= g[i];
        return *this;
    }
    F &operator<<=(const int d) {
        int n = (*this).size();
        (*this).insert((*this).begin(), d, 0);
        (*this).resize(n);
        return *this;
    }
    F &operator>>=(const int d) {
        int n = (*this).size();
        (*this).erase((*this).begin(), (*this).begin() + min(n, d));
        (*this).resize(n);
        return *this;
    }

    F inv(int d = -1) const {
        int n = (*this).size();
        assert(n != 0 && (*this)[0] != 0);
        if (d == -1) d = n;
        assert(d > 0);
        F res{(*this)[0].inv()};
        while (res.size() < d) {
            int m = size(res);
            F f(begin(*this), begin(*this) + min(n, 2*m));
            F r(res);
            f.resize(2*m), internal::butterfly(f);
            r.resize(2*m), internal::butterfly(r);
            rep(i, 2*m) f[i] *= r[i];
            internal::butterfly_inv(f);
            f.erase(f.begin(), f.begin() + m);
            f.resize(2*m), internal::butterfly(f);
            rep(i, 2*m) f[i] *= r[i];
            internal::butterfly_inv(f);
            T iz = T(2*m).inv(); iz *= -iz;
            rep(i, m) f[i] *= iz;
            res.insert(res.end(), f.begin(), f.begin() + m);
        }
        return {res.begin(), res.begin() + d};
    }

    // sparse
    F &operator*=(vector<pair<int, T>> g) {
        int n = (*this).size();
        auto [d, c] = g.front();
        if (d == 0) g.erase(g.begin());
        else c = 0;
        for(int i=n-1;i>=0;i--) {
            (*this)[i] *= c;
            for (auto &[j, b] : g) {
                if (j > i) break;
                (*this)[i] += (*this)[i-j] * b;
            }
        }
        return *this;
    }
    F &operator/=(vector<pair<int, T>> g) {
        int n = (*this).size();
        auto [d, c] = g.front();
        assert(d == 0 && c != T(0));
        T ic = c.inv();
        g.erase(g.begin());
        rep(i, n) {
            for (auto &[j, b] : g) {
                if (j > i) break;
                (*this)[i] -= (*this)[i-j] * b;
            }
            (*this)[i] *= ic;
        }
        return *this;
    }

    // fast: FMT-friendly modulus only
    F &operator*=(const F &g) {
        int n = (*this).size();
        *this = convolution(*this, g);
        (*this).resize(n);
        return *this;
    }
    F &operator/=(const F &g) {
        int n = (*this).size();
        *this = convolution(*this, g.inv(n));
        (*this).resize(n);
        return *this;
    }

    // naive
    // F &operator*=(const F &g) {
    //     int n = (*this).size(), m = g.size();
    //     for(int i=n-1;i>=0;i--) {
    //         (*this)[i] *= g[0];
    //         for(int j=1;i<min(i+1, m);i++) (*this)[i] += (*this)[i-j] * g[j];
    //     }
    //     return *this;
    // }
    // F &operator/=(const F &g) {
    //     assert(g[0] != T(0));
    //     T ig0 = g[0].inv();
    //     int n = (*this).size(), m = g.size();
    //     for(int i=n-1;i>=0;i--) {
    //         for(int j=1;i<min(i+1, m);i++) (*this)[i] -= (*this)[i-j] * g[j];
    //         (*this)[i] *= ig0;
    //     }
    //     return *this;
    // }

    // multiply and divide (1 + cz^d)
    void multiply(const int d, const T c) { 
        int n = (*this).size();
        if (c == T(1)) for(int i=n-d-1;i>=0;i--) (*this)[i+d] += (*this)[i];
        else if (c == T(-1)) for(int i=n-d-1;i>=0;i--) (*this)[i+d] -= (*this)[i];
        else for(int i=n-d-1;i>=0;i--) (*this)[i+d] += (*this)[i] * c;
    }
    void divide(const int d, const T c) {
        int n = (*this).size();
        if (c == T(1)) rep(i, n-d) (*this)[i+d] -= (*this)[i];
        else if (c == T(-1)) rep(i, n-d) (*this)[i+d] += (*this)[i];
        else rep(i, n-d) (*this)[i+d] -= (*this)[i] * c;
    }

    T eval(const T &a) const {
        T x(1), res(0);
        for (auto e : *this) res += e * x, x *= a;
        return res;
    }

    F operator*(const T &g) const { return F(*this) *= g; }
    F operator/(const T &g) const { return F(*this) /= g; }
    F operator+(const F &g) const { return F(*this) += g; }
    F operator-(const F &g) const { return F(*this) -= g; }
    F operator<<(const int d) const { return F(*this) <<= d; }
    F operator>>(const int d) const { return F(*this) >>= d; }
    F operator*(const F &g) const { return F(*this) *= g; }
    F operator/(const F &g) const { return F(*this) /= g; }
    F operator*(vector<pair<int, T>> g) const { return F(*this) *= g; }
    F operator/(vector<pair<int, T>> g) const { return F(*this) /= g; }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n, s; cin >> n >> s;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    FormalPowerSeries<mint> fps(s+1);
    mint ans = 0;
    rep(i,n) {
        FormalPowerSeries<mint> tmp(s+1);
        fps[0]++;
        tmp[0] = 1;
        if( a[i] <= s ) tmp[a[i]] = 1;
        fps *= tmp;
        ans += fps[s];
    }
    cout << ans.val() << endl;
    
    return 0;
}