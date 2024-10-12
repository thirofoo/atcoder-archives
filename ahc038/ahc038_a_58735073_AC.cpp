/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc038/submissions/58735073
 * Submitted at: 2024-10-13 00:32:33
 * Problem URL: https://atcoder.jp/contests/ahc038/tasks/ahc038_a
 * Result: AC
 * Execution Time: 23 ms
 */

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

using ll = long long;
using P  = pair<int, int>;
using T  = tuple<int, int, int>;

// right | down | left | up
#define DIR_NUM 4
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

inline bool outField(P now, int h, int w) {
  auto&& [x, y] = now;
  if(0 <= x && x < h && 0 <= y && y < w) return false;
  return true;
}

struct Solver {
  int N, M, V, base_V;
  int root_x, root_y;
  int base_x, base_y; // 不変
  ll situation;
  vector<int> arm_length;
  vector<string> s, t, answer;
  vector<vector<vector<ll>>> graph;

  vector<pair<P, P>> moves;
  vector<P> before_points, after_points;

  Solver() {
    this->input();
  }

  void input() {
    cin >> N >> M >> V;
    base_V = V;
    s.resize(N);
    t.resize(N);
    rep(i, N) cin >> s[i];
    rep(i, N) cin >> t[i];
    rep(i, N) rep(j, N) {
      if(s[i][j] == '1' && t[i][j] == '1') continue;
      if(s[i][j] == '1') before_points.emplace_back(i, j);
      if(t[i][j] == '1') after_points.emplace_back(i, j);
    }

    if(V == 5) arm_length = {1, 2, 4, 8};
    else if(V == 6) arm_length = {1, 2, 4, 8, 16};
    else if(V == 7) arm_length = {1, 1, 2, 4, 8, 16};
    else if(V == 8) arm_length = {1, 1, 1, 2, 4, 8, 16};
    else if(V == 9) arm_length = {1, 1, 1, 1, 2, 4, 8, 16};
    else if(V == 10) arm_length = {1, 1, 1, 1, 1, 2, 4, 8, 16};
    else if(V <= 12) arm_length = {1, 2, 4, 8, 16};
    else if(V <= 14) arm_length = {1, 1, 2, 4, 8, 16};
    else if(V <= 15) arm_length = {1, 1, 1, 2, 4, 8, 16};

    // arm が長すぎてしまう場合は調整
    rep(i, arm_length.size()) arm_length[i] = min(arm_length[i], N - 1);
    arm_length.back()                       = min(arm_length.back(), N / 2);
    for(int i = arm_length.size() - 2; i >= 0; i--) {
      // 前と 1 : 2 になるように調整
      arm_length[i] = max(min(arm_length[i], (arm_length[i + 1] + 1) / 2), 1);
    }
    V = arm_length.size() + 1;

    for(int i = arm_length.size() - 2; i >= 0; i--) {
      arm_length[i] += arm_length[i + 1];
    }
    return;
  }

  vector<vector<vector<ll>>> createGraph() {
    vector<int> possible_dir;
    vector res(2 * arm_length[0] + 1, vector<vector<ll>>(2 * arm_length[0] + 1, vector<ll>{}));
    int sx, sy;
    auto dfs = [&](auto self, int depth, P now, int now_dir, ll now_situation) -> void {
      auto [now_x, now_y] = now;
      if(depth == V - 1) {
        if(outField(now, 2 * arm_length[0] + 1, 2 * arm_length[0] + 1)) return;
        res[now_x][now_y].emplace_back(now_situation);
        return;
      }
      for(auto dir_d: possible_dir) {
        int n_dir      = (now_dir + dir_d + DIR_NUM) % DIR_NUM;
        int n_x        = now_x + arm_length[depth] * (dx[n_dir] - dx[now_dir]);
        int n_y        = now_y + arm_length[depth] * (dy[n_dir] - dy[now_dir]);
        ll n_situation = now_situation * DIR_NUM + dir_d;
        self(self, depth + 1, P(n_x, n_y), n_dir, n_situation);
      }
    };
    sx = arm_length[0], sy = 2 * arm_length[0];

    possible_dir = {0, 1, 2, 3};
    dfs(dfs, 0, P(sx, sy), 0, 0LL);
    return res;
  }

  inline void catchOrRelease(ll after_sit) {
    // 機械本体の移動はしないでたこ焼きを移動する関数
    ll s1, s2, before_sit = situation;
    vector<string> res(2, "");
    rep(i, 2) rep(j, 2 * V) res[i] += ".";

    int max_rotate_time = 0;
    for(int i = V - 1; i > 0; i--) {
      s1        = before_sit % DIR_NUM;
      s2        = after_sit % DIR_NUM;
      int diff1 = (s2 - s1 + DIR_NUM) % DIR_NUM, diff2 = (s1 - s2 + DIR_NUM) % DIR_NUM;
      int rotate_time = min(diff1, diff2);
      max_rotate_time = max(max_rotate_time, rotate_time);
      if(diff1 <= diff2) rep(j, rotate_time) res[j][i] = 'R';
      else rep(j, rotate_time) res[j][i] = 'L';

      before_sit /= DIR_NUM;
      after_sit /= DIR_NUM;
    }
    rep(i, max_rotate_time) answer.emplace_back(res[i]);
    answer.back().back() = 'P';
    return;
  }

  inline ll slideMachine(P to) {
    // 機械本体の移動のみを行う関数
    int min_dis = 1e9, min_rotate_time = 1e9;
    int move_dx = 0, move_dy = 0;
    ll next_situation = 0;
    auto [to_x, to_y] = to;
    rep(i, graph.size()) {
      rep(j, graph[i].size()) {
        if(graph[i][j].empty()) continue;
        int cand_dx = i - graph.size() / 2, cand_dy = j - graph[i].size() / 2;
        int dis    = abs(root_x + cand_dx - to_x) + abs(root_y + cand_dy - to_y);
        int tmp_dx = to_x - (root_x + cand_dx), tmp_dy = to_y - (root_y + cand_dy);

        // 極力移動はさせない
        if(root_x + tmp_dx < base_x - max(1, N - arm_length[0]) || base_x + max(1, N - arm_length[0]) < root_x + tmp_dx) continue;
        if(root_y + tmp_dy < base_y - max(1, N - arm_length[0]) || base_y + max(1, N - arm_length[0]) < root_y + tmp_dy) continue;
        if(outField(P(root_x + tmp_dx, root_y + tmp_dy), N, N)) continue;

        rep(k, graph[i][j].size()) {
          ll cand_sit     = graph[i][j][k];
          ll tmp_sit      = situation;
          int rotate_time = 0;
          rep(l, V) {
            int s1      = cand_sit % DIR_NUM;
            int s2      = tmp_sit % DIR_NUM;
            rotate_time = max({rotate_time, min((s1 - s2 + DIR_NUM) % DIR_NUM, (s2 - s1 + DIR_NUM) % DIR_NUM)});
            cand_sit /= DIR_NUM;
            tmp_sit /= DIR_NUM;
          }
          if(dis < min_dis || (dis == min_dis && rotate_time < min_rotate_time)) {
            min_dis         = dis;
            min_rotate_time = rotate_time;
            move_dx         = tmp_dx;
            move_dy         = tmp_dy;
            next_situation  = graph[i][j][k];
          }
        }
      }
    }
    rep(i, abs(move_dx)) {
      string op = move_dx > 0 ? "D" : "U";
      rep(j, 2 * V - 1) op += ".";
      answer.emplace_back(op);
    }
    rep(i, abs(move_dy)) {
      string op = move_dy > 0 ? "R" : "L";
      rep(j, 2 * V - 1) op += ".";
      answer.emplace_back(op);
    }
    root_x += move_dx;
    root_y += move_dy;
    return next_situation;
  }

  inline void move(P before, P after) {
    if(before == after) return;

    // たこ焼きの元へ移動
    ll next_situation = slideMachine(before);
    catchOrRelease(next_situation);
    situation = next_situation;

    // 目標配置場所へ移動
    next_situation = slideMachine(after);
    catchOrRelease(next_situation);
    situation = next_situation;
    return;
  }

  void solve() {
    // 貪欲解 (ムチ戦法)
    // 1. ムチで移動可能範囲のグラフを作成
    graph    = createGraph();
    int cnt1 = 0, cnt2 = 0;
    rep(i, N) rep(j, N) {
      cnt1 += s[i][j] == '1';
      cnt2 += t[i][j] == '1';
    }
    // cerr << cnt1 << " " << cnt2 << endl;

    // 2. 初期配置を出力
    int max_dis1 = 0;
    rep(i1, N) rep(j1, N) {
      if(s[i1][j1] != '1') continue;
      int max_dis2 = 0, mx = -1, my = -1;
      rep(i2, N) rep(j2, N) {
        if(t[i2][j2] != '1') continue;
        if(max_dis2 < abs(i1 - i2) + abs(j1 - j2)) {
          max_dis2 = abs(i1 - i2) + abs(j1 - j2);
          mx       = i2;
          my       = j2;
        }
      }
      if(max_dis2 > max_dis1) {
        max_dis1 = max_dis2;
        root_x   = (i1 + mx) / 2;
        root_y   = (j1 + my) / 2;
      }
    }
    base_x = root_x, base_y = root_y;
    situation = 0;

    auto compare = [&](P& a, P& b) {
      auto [ax, ay] = a;
      auto [bx, by] = b;
      if((ax + ay + arm_length[0] + base_x + base_y) % 2 != (bx + by + arm_length[0] + base_x + base_y) % 2) {
        return (ax + ay + arm_length[0] + base_x + base_y) % 2 < (bx + by + arm_length[0] + base_x + base_y) % 2;
      }
      return ax + ay < bx + by;
    };
    sort(before_points.begin(), before_points.end(), compare);
    sort(after_points.begin(), after_points.end(), compare);

    // 3. たこ焼きを取得し、移動するための操作を生成・出力
    rep(i, before_points.size()) move(before_points[i], after_points[i]);

    // ※ V >= 11 の時は腕を独立でもう一つ伸ばせるので処理をさせる
    if(base_V >= 11) {
      // cerr << "V >= 11" << endl;
      vector<string> store_ans;
      swap(answer, store_ans);

      if(base_V <= 12) arm_length = {1, 2, 4, 8, 16};
      else if(base_V <= 14) arm_length = {1, 1, 2, 4, 8, 16};
      else if(base_V <= 15) arm_length = {1, 1, 1, 2, 4, 8, 16};

      rep(i, arm_length.size()) arm_length[i] = min(arm_length[i], N - 1);
      arm_length.back()                       = min(arm_length.back(), N / 2);
      for(int i = arm_length.size() - 2; i >= 0; i--) arm_length[i] = max(min(arm_length[i], (arm_length[i + 1] + 1) / 2), 1);
      arm_length.back()++;
      V = arm_length.size() + 1;

      for(int i = arm_length.size() - 2; i >= 0; i--) {
        arm_length[i] += arm_length[i + 1];
      }

      graph  = createGraph();
      root_x = base_x, root_y = base_y;
      situation = 0;
      for(int i = before_points.size() - 1; i >= 0; i--) {
        auto [bx, by] = before_points[i];
        if((bx + by + arm_length[0] + base_x + base_y) % 2 != 0) break;
        move(before_points[i], after_points[i]);
      }

      // 答えを merge する
      // cerr << "store_ans.size() : " << store_ans.size() << endl;
      // cerr << "answer.size() : " << answer.size() << endl;
      vector<string> merge_ans(store_ans.size(), "");
      rep(i, store_ans.size()) rep(j, 2 * (2 * V - 1)) merge_ans[i] += ".";
      rep(i, store_ans.size()) {
        rep(j, V) merge_ans[i][j] = store_ans[i][j];
        merge_ans[i][3 * V - 2]   = store_ans[i].back();
      }
      int p_cnt = 0;
      rep(i, answer.size()) {
        if(merge_ans[i][0] != '.' || answer[i][0] != '.') break;
        rep(j, V - 1) merge_ans[i][V + j] = answer[i][j + 1];
        merge_ans[i].back()               = answer[i].back();
        if(answer[i].back() == 'P') p_cnt++;
      }

      for(int i = merge_ans.size() - 1; i >= 0; i--) {
        if(p_cnt % 2 == 0) break;
        p_cnt -= (merge_ans[i].back() == 'P');
        rep(j, V - 1) merge_ans[i][V + j] = '.';
        merge_ans[i].back()               = '.';
      }

      p_cnt       = before_points.size() * 2 - p_cnt;
      int now_cnt = 0;
      bool flag   = false;
      rep(i, merge_ans.size()) {
        if(flag) {
          rep(j, V) merge_ans[i][j] = '.';
          merge_ans[i][3 * V - 2]   = '.';
        }
        now_cnt += (merge_ans[i][3 * V - 2] == 'P');
        flag |= (now_cnt >= p_cnt);
      }
      while(true) {
        bool f = true;
        rep(i, merge_ans.back().size()) f &= (merge_ans.back()[i] == '.');
        if(!f) break;
        merge_ans.pop_back();
      }

      V = 2 * V - 1;
      swap(answer, merge_ans);

      // 出力
      cout << V << endl;
      rep(i, V / 2) cout << i << " " << arm_length[i] - (i == V / 2 - 1 ? 0 : arm_length[i + 1]) + (i == V / 2 - 1 ? -1 : 0) << endl;
      rep(i, V / 2) cout << (i == 0 ? 0 : i + V / 2) << " " << arm_length[i] - (i == V / 2 - 1 ? 0 : arm_length[i + 1]) << endl;
      cout << base_x << " " << base_y << endl;
      if(base_V >= 10) return;

      rep(i, answer.size()) {
        if(i != answer.size() - 1 && answer[i][0] != '.' && answer[i].back() != 'P' && answer[i + 1][0] == '.') {
          answer[i + 1][0] = answer[i][0];
          i++;
        }
        cout << answer[i] << endl;
      }
      return;
    }

    cout << V << endl;
    rep(i, V - 1) cout << i << " " << arm_length[i] - (i == V - 2 ? 0 : arm_length[i + 1]) << endl;
    cout << base_x << " " << base_y << endl;
    if(base_V >= 10) return;

    rep(i, answer.size()) {
      if(i != answer.size() - 1 && answer[i][0] != '.' && answer[i].back() != 'P' && answer[i + 1][0] == '.') {
        answer[i + 1][0] = answer[i][0];
        i++;
      }
      cout << answer[i] << endl;
    }

    return;
  }
};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  Solver solver;
  solver.solve();

  return 0;
}