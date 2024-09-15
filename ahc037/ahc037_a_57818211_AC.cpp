/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc037/submissions/57818211
 * Submitted at: 2024-09-15 21:26:39
 * Problem URL: https://atcoder.jp/contests/ahc037/tasks/ahc037_a
 * Result: AC
 * Execution Time: 9 ms
 */

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

namespace utility {
  struct timer {
    chrono::system_clock::time_point start;
    // 開始時間を記録
    void CodeStart() {
      start = chrono::system_clock::now();
    }
    // 経過時間 (ms) を返す
    double elapsed() const {
      using namespace std::chrono;
      return (double) duration_cast<milliseconds>(system_clock::now() - start).count();
    }
  } mytm;
} // namespace utility

inline unsigned int rand_int() {
  static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
  unsigned int tt = (tx ^ (tx << 11));
  tx = ty, ty = tz, tz = tw;
  return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
}

inline double rand_double() {
  return (double) (rand_int() % (int) 1e9) / 1e9;
}

// 温度関数
#define TIME_LIMIT 1850
inline double temp(double start) {
  double start_temp = 100, end_temp = 1;
  return start_temp + (end_temp - start_temp) * ((utility::mytm.elapsed() - start) / TIME_LIMIT);
}

// 焼きなましの採用確率
inline double prob(int best, int now, int start) {
  return exp((double) (now - best) / temp(start));
}

//-----------------以下から実装部分-----------------//

using Point = pair<int, int>;

struct Answer {
  int x1, y1, x2, y2;
  Answer() : x1(0), y1(0), x2(0), y2(0) {}
  Answer(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};

// right | down | left | up
#define DIR_NUM 4
vector<int> dx = { 0, 1, 0,-1};
vector<int> dy = { 1, 0,-1, 0};

inline bool outField(pair<int, int> now, int h, int w) {
  auto &&[x, y] = now;
  if(0 <= x && x < h && 0 <= y && y < w) return false;
  return true;
}

struct Solver {
  int n;
  vector<int> px, py, cpx, cpy, comp_x, comp_y;
  vector<vector<bool>> need_soda;
  vector<Point> points;
  vector<Answer> answers;

  Solver() {
    this->input(); // 入力受付
    sort(comp_x.begin(), comp_x.end());
    sort(comp_y.begin(), comp_y.end());
    comp_x.erase(unique(comp_x.begin(), comp_x.end()), comp_x.end());
    comp_y.erase(unique(comp_y.begin(), comp_y.end()), comp_y.end());

    cpx.assign(n, 0);
    cpy.assign(n, 0);
    need_soda.assign(comp_x.size(), vector<bool>(comp_y.size(), false));
    rep(i, n) {
      cpx[i] = lower_bound(comp_x.begin(), comp_x.end(), px[i]) - comp_x.begin();
      cpy[i] = lower_bound(comp_y.begin(), comp_y.end(), py[i]) - comp_y.begin();
      need_soda[cpx[i]][cpy[i]] = true;
    }
    return;
  }

  void input() {
    cin >> n;
    px.assign(n, 0);
    py.assign(n, 0);
    rep(i, n) {
      cin >> px[i] >> py[i];
      points.emplace_back(px[i], py[i]);
      comp_x.emplace_back(px[i]);
      comp_y.emplace_back(py[i]);
    }
    return;
  }

  void output() {
    cout << answers.size() << endl;
    for(auto &&ans : answers) {
      cout << ans.x1 << " " << ans.y1 << " " << ans.x2 << " " << ans.y2 << endl;
    }
    return;
  }

  void solve() {
    // ========== シュタイナー木山登り解法 ==========
    // 1. シュタイナー木に含まれても良い候補点を作成
    // 2. 訪れても良い点群の変更を近傍とする山登り法
    // 3. 最終的な点群から効率の良いソーダの割り方を求める

    utility::mytm.CodeStart();

    // 1. シュタイナー木に含めても良い候補点を作成
    cerr << "Start Steiner Tree Candidate!\n";
    vector in_steiner(cpx.size(), vector<bool>(cpy.size(), false));
    rep(i, n) in_steiner[cpx[i]][cpy[i]] = true;
    rep(i, n) for(int j = i + 1; j < n; j++) {
      // px[i] < px[j] && py[i] > py[j] の時は右下の頂点は不要 (明らかに遠回りのため)
      if(cpx[i] < cpx[j] && cpy[i] > cpy[j]) {
        in_steiner[cpx[i]][cpy[j]] = true;
      } else if(cpx[i] > cpx[j] && cpy[i] < cpy[j]) {
        in_steiner[cpx[j]][cpy[i]] = true;
      } else {
        in_steiner[cpx[i]][cpy[j]] = true;
        in_steiner[cpx[j]][cpy[i]] = true;
      }
    }
    int steiner_points_cnt = 0;
    rep(i, cpx.size()) rep(j, cpy.size()) steiner_points_cnt += in_steiner[i][j];
    cerr << "steiner_points_cnt: " << steiner_points_cnt << endl;

    // 2. 訪れても良い点群の変更を近傍とする山登り法
    // ※ 今はランダムで 5N 点選択
    cerr << "Start Steiner Tree Climbing!\n";
    vector<vector<bool>> used(cpx.size(), vector<bool>(cpy.size(), false));
    vector<Point> used_points;
    rep(i, n) used_points.emplace_back(cpx[i], cpy[i]);
    // rep(i, 4 * n) {
    //   while(true) {
    //     int x = rand_int() % cpx.size();
    //     int y = rand_int() % cpy.size();
    //     if(used[x][y]) continue;
    //     used[x][y] = true;
    //     used_points.emplace_back(x, y);
    //     break;
    //   }
    // }
    // createGreatSoda(used_points);

    // 3. 最終的な点群から効率の良いソーダの割り方を求める
    cerr << "Start Soda Making!\n";
    answers = createSoda(used_points);

    return;
  }

  void createGreatSoda(vector<Point> &points) {
    // points に含まれる点群を隣接頂点に移動させる近傍でより良いソーダの割り方を求める
    while(utility::mytm.elapsed() < TIME_LIMIT) {
      // 近傍 : 1 頂点をランダムで隣接する上下左右に移動
      int idx = rand_int() % points.size();
      int dir = rand_int() % DIR_NUM;
      auto &&[x, y] = points[idx];
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(outField(Point(nx, ny), cpx.size(), cpy.size())) continue;

    }

    return;
  }

  long long calcScore(vector<Point> &points) {
    // シュタイナー木を作成する時のスコアを計算
    long long score = 0;

    return score;
  }

  vector<Answer> createSoda(vector<Point> &points) {
    // x + y が小さい順からシュタイナー木を作成する要領でソーダの割り方を求める
    sort(points.begin(), points.end(), [](Point &a, Point &b) {
      auto &&[ax, ay] = a;
      auto &&[bx, by] = b;
      return ax + ay < bx + by;
    });
    vector<vector<int>> children(points.size() + 5), parents(points.size() + 5);
    vector<Point> visited;
    visited.emplace_back(Point(0, 0));

    // O(N^2) でシュタイナー木を作成
    rep(i, points.size()) {
      auto &&[x1, y1] = points[i];
      int min_cost = 1e9;
      int min_idx = -1;
      rep(j, visited.size()) {
        auto &&[x2, y2] = visited[j];
        // (x1, y1) が (x2, y2) の右上に無い位置関係の時は NG
        if(x1 < x2 || y1 < y2) continue;
        int cost = abs(comp_x[x1] - comp_x[x2]) + abs(comp_y[y1] - comp_y[y2]);
        if(cost < min_cost) {
          min_cost = cost;
          min_idx = j;
        }
      }
      children[min_idx].emplace_back(visited.size());
      parents[visited.size()].emplace_back(min_idx);
      visited.emplace_back(points[i]);
    }

    // x + y が大きい頂点から順に、削除してスコアが上がるかを確認
    vector<bool> in_tree(visited.size(), true);
    vector<int> perm(visited.size()), perm_inv(visited.size());
    iota(perm.begin(), perm.end(), 0);
    sort(perm.begin(), perm.end(), [&](int a, int b) {
      auto &&[x1, y1] = visited[a];
      auto &&[x2, y2] = visited[b];
      return x1 + y1 > x2 + y2;
    });
    rep(i, visited.size()) perm_inv[perm[i]] = i;

    int erase_cnt = 0;

    rep(i, visited.size()) {
      int idx = perm[i];
      auto &&[x, y] = visited[idx];
      if(need_soda[x][y]) continue;
      long long cost = 0;

      // 元のコストの減少分
      for(auto &&parent : parents[idx]) {
        auto &&[px, py] = visited[parent];
        cost -= abs(comp_x[x] - comp_x[px]) + abs(comp_y[y] - comp_y[py]);
      }
      for(auto &&child : children[idx]) {
        auto &&[cx, cy] = visited[child];
        cost -= abs(comp_x[x] - comp_x[cx]) + abs(comp_y[y] - comp_y[cy]);
      }
      // cerr << "cost: " << cost << endl;

      // 新たに繋ぎ変えることによるコストの増加分
      bool ng = true;
      for(auto &&child : children[idx]) {
        auto &&[cx, cy] = visited[child];
        // 自身より x + y が小さい && 左上にいる頂点と繋ぎ変える時のコスト
        for(int j = perm_inv[child] + 1; j < visited.size(); j++) {
          if(!in_tree[perm[j]] || perm[j] == idx) continue;
          auto &&[jx, jy] = visited[perm[j]];
          if(cx < jx || cy < jy) continue;

          cost += abs(comp_x[jx] - comp_x[cx]) + abs(comp_y[jy] - comp_y[cy]);
          ng = false;
          break;
        }
      }
      if(ng) continue;

      // cerr << "cost: " << cost << endl;
      if(cost >= 0) continue;
      cerr << "erase: " << x << " " << y << endl;
      
      // コストが下がる場合は繋ぎ変える
      in_tree[idx] = false;
      for(auto child : children[idx]) {
        auto &&[cx, cy] = visited[child];
        for(int j = perm_inv[child] + 1; j < visited.size(); j++) {
          if(!in_tree[perm[j]] || perm[j] == idx) continue;
          auto &&[jx, jy] = visited[perm[j]];
          if(cx < jx || cy < jy) continue;

          parents[child].erase(find(parents[child].begin(), parents[child].end(), idx));
          children[perm[j]].emplace_back(child);
          parents[child].emplace_back(perm[j]);

          break;
        }
      }
      for(auto &&parent : parents[idx]) {
        children[parent].erase(find(children[parent].begin(), children[parent].end(), idx));
      }
      parents[idx].clear();
      children[idx].clear();
    }

    // DFS の行きがけでソーダの割り方を求める
    vector<Answer> soda;
    auto dfs = [&](auto &&f, int now) -> bool {

      // 部分木に必須のソーダ割があるかどうか
      bool need = need_soda[visited[now].first][visited[now].second];
      for(auto &&next : children[now]) {
        auto &&[x1, y1] = visited[now];
        auto &&[x2, y2] = visited[next];
        soda.emplace_back(Answer(comp_x[x1], comp_y[y1], comp_x[x2], comp_y[y2]));
        need |= f(f, next);
        if(!need) soda.pop_back();
      }
      return need;
    };
    dfs(dfs, 0);
    return soda;
  }
};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  Solver solver;
  solver.solve();
  solver.output();

  return 0;
}