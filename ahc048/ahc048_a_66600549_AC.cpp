/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc048/submissions/66600549
 * Submitted at: 2025-06-08 16:01:16
 * Problem URL: https://atcoder.jp/contests/ahc048/tasks/ahc048_a
 * Result: AC
 * Execution Time: 2904 ms
 */

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;
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
		using namespace chrono;
		return (double) duration_cast<milliseconds>(system_clock::now() - start).count();
	}
	} mytm;
}

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
#define TIME_LIMIT 2900
inline double temp(double start) {
	double start_temp = 100, end_temp = 1;
	return start_temp + (end_temp - start_temp) * ((utility::mytm.elapsed() - start) / TIME_LIMIT);
}

// 焼きなましの採用確率
inline double prob(int best, int now, int start) {
	return exp((double) (now - best) / temp(start));
}

constexpr double kEps = 1e-9;
constexpr int Dthreshold = 300;

// right | down | left | up
#define DIR_NUM 4
vector<P> delta = {P(0, 1), P(1, 0), P(0, -1), P(-1, 0)};
inline bool outField(pair<int, int> now, int h, int w) {
	auto &&[x, y] = now;
	if(0 <= x && x < h && 0 <= y && y < w) return false;
	return true;
}
enum class DIR {
	RIGHT, DOWN, LEFT, UP, NONE
};
// prev → now に行く時の方向を返す
inline DIR getDir(const P& prev, const P& now) {
	if (prev.first == now.first) {
		if (prev.second < now.second) return DIR::RIGHT;
		else return DIR::LEFT;
	} else {
		if (prev.first < now.first) return DIR::DOWN;
		else return DIR::UP;
	}
}
inline DIR revDir(DIR d) {
	switch (d) {
		case DIR::RIGHT: return DIR::LEFT;
		case DIR::DOWN:  return DIR::UP;
		case DIR::LEFT:  return DIR::RIGHT;
		case DIR::UP:    return DIR::DOWN;
		default:         assert(false); return DIR::NONE;
	}
}

struct Color {
	double c, m, y;
	Color() = default;
	Color(double C, double M, double Y) : c(C), m(M), y(Y) {}
	Color operator+(const Color& o) const {return {c + o.c, m + o.m, y + o.y};}
	Color operator*(double k) const {
		if (k < kEps) return {0, 0, 0};
		return {c * k, m * k, y * k};
	}
	Color operator/(double k) const {
		if (k < kEps) return {0, 0, 0};
		return {c / k, m / k, y / k};
	}
	bool operator==(const Color& o) const {
		return abs(c - o.c) < 1e-9 && abs(m - o.m) < 1e-9 && abs(y - o.y) < 1e-9;
	}
	double dist2(const Color& o) const {
		double dc = c - o.c, dm = m - o.m, dy = y - o.y;
		return sqrt(dc*dc + dm*dm + dy*dy);
	}
	bool operator<(const Color& o) const {
		if (c != o.c) return c < o.c;
		if (m != o.m) return m < o.m;
		return y < o.y;
	}
};

/* ---------- 分割重みテーブル ---------- */
struct W2 {uint8_t div; double wA, wT;};
struct W3 {uint8_t d1,d2; double wA,wB,wT;};
struct W4 {uint8_t d0,d1,d2; double wA,wB,wC,wT;};

array<W2,4>  tab2;           // div = 1..4
array<W3,16> tab3;           // 4^2

bool builded = false;
void buildWeightTable(int W){
  for(int d=2; d<=W; ++d){
    double den=d+W;
    tab2[d-1]={uint8_t(d), double(d)/den, double(W)/den};
  }
  int p=0;
  for(int d1=1; d1<=W; ++d1)for(int d2=1; d2<=W; ++d2){
    double den=d1+d2+W;
    tab3[p++]={uint8_t(d1),uint8_t(d2),
               double(d1)/den,double(d2)/den,double(W)/den};
  }
}

struct Mix2Result {
	int ci;
	int div;
	double err;
};

struct Mix3Result {
  int nti;
  int divA, divB;
  int divT;
  int ci;
  double err;
  array<DIR,2> dirs;
};

Mix2Result findBest2mix(const Color& X, const Color& A, int W,
                        const vector<Color>& tubes){
  double bestErr=1e9; int bestDiv=1,bestCi=0;
  for(const auto& w: tab2){
    Color base = A*w.wA;
    for(int ci=0; ci<(int)tubes.size(); ++ci){
      Color mix = base + tubes[ci]*w.wT;
      double err = mix.dist2(X);
      if(err<bestErr){bestErr=err;bestDiv=w.div;bestCi=ci;}
    }
  }
  return {bestCi,bestDiv,bestErr};
}

Mix3Result findBest3mix(const Color& X,const Color& A,
        int ti,int pr,int pc,int SQ,int W,
        const vector<Color>& tubes,
        const vector<DIR>&   PathDir,
  			const vector<Color>& tileCol)
{
  double bestErr = 1e30;
  Mix3Result best{-1,0,0,0,0,bestErr,{DIR::NONE,DIR::NONE}};

  for(int dir=0; dir<DIR_NUM; ++dir){
    int nr=pr+delta[dir].first, nc=pc+delta[dir].second;
    if(outField({nr,nc},SQ,SQ)) continue;
    int nti = nr*SQ+nc;
    const Color& B = tileCol[nti];
	
    for(int dA=1; dA<=W; ++dA) for(int dB=1; dB<=W; ++dB) for(int tsel=0; tsel<4; ++tsel) {
      int dT = (tsel==0?0 : tsel==1?W : tsel==2?dA : dB);
      if(dA+dB+dT < W) continue;
		
      double den = double(dA+dB+dT);
      double wA=dA/den, wB=dB/den, wT=dT/den;
	
      for(int ci=0; ci<(int)tubes.size(); ++ci){
        Color mix{
          A.c*wA + B.c*wB + tubes[ci].c*wT,
          A.m*wA + B.m*wB + tubes[ci].m*wT,
          A.y*wA + B.y*wB + tubes[ci].y*wT
        };
        double err = mix.dist2(X);
        if(err < best.err){
          best = {nti,dA,dB,dT,ci,err,{DIR::NONE,DIR::NONE}};
          DIR d0 = getDir({pr,pc},{nr,nc});
          DIR d1 = revDir(d0);
          best.dirs[0] = (PathDir[ti]!=d0?d0:DIR::NONE);
          best.dirs[1] = (PathDir[nti]!=d1?d1:DIR::NONE);
        }
    }
    }
  }
  return best;
}

struct Trace {
	char op; // 'A' : 2 色混色, 'B' : 3 色混色
	int colorIdx; // 1 グラム滴下する色の index
	int parentId; // 親の Trace id
	vector<int> tileIdxs, divIdxs; // タイル index, 仕切り index
	vector<DIR> tileDirIdxs; // タイルの仕切り方向の index
	Trace() : op(0), tileIdxs(), divIdxs(), colorIdx(0), parentId(0) {}
	Trace(char o, vector<int> tIdxs, vector<int> dIdxs, int cIdx, int pId, vector<DIR> tileDirIdxs = {})
		: op(o), tileIdxs(tIdxs), divIdxs(dIdxs), colorIdx(cIdx), parentId(pId), 
		  tileDirIdxs(tileDirIdxs) {}
};

struct State {
	vector<Color> tileCol;
  vector<DIR>   PathDir;
	double score = 0.0;
	int depth = 0;
	int id = 0;
	int op_cnt = 0;
	bool operator<(const State& o) const { return score < o.score; }
};

vector<P> snake(int U, int D, int L, int R, bool reverse = false) {
	vector<P> p;
	p.reserve((D - U) * (R - L));
	for (int r = U; r <= D; r++) {
		bool flag = reverse ^ (r & 1) ^ (U & 1);
		if (flag) for (int c = R; c >= L; --c) p.emplace_back(r, c);
		else 			 for (int c = L; c <= R; ++c) p.emplace_back(r, c);
	}
	return p;
}

struct Mask {
	int v[20][19], h[19][20];
	Mask() {
		for (auto& row : v) for (int& x : row) x = 1;
		for (auto& row : h) for (int& x : row) x = 1;
	}
	void open(const P& a, const P& b) {
		if (a.first == b.first)
			v[a.first][min(a.second, b.second)] = 0;
		else
			h[min(a.first, b.first)][a.second] = 0;
	}
	void close(const P& a, const P& b) {
		if (a.first == b.first)
			v[a.first][min(a.second, b.second)] = 1;
		else
			h[min(a.first, b.first)][a.second] = 1;
	}
	void dump(vector<string>& cmds) const {
		for (int i = 0; i < 20; i++) {
			string line;
			for (int j = 0; j < 19; j++) {
				if (j) line += ' ';
				line += to_string(v[i][j]);
			}
			cmds.emplace_back(line);
		}
		for (int i = 0; i < 19; i++) {
			string line;
			for (int j = 0; j < 20; j++) {
				if (j) line += ' ';
				line += to_string(h[i][j]);
			}
			cmds.emplace_back(line);
		}
	}
};

inline void cmdAdd(const P& p, int k, vector<string>& cmds) {cmds.emplace_back("1 " + to_string(p.first) + " " + to_string(p.second) + " " + to_string(k));}
inline void cmdTake(const P& p, vector<string>& cmds) {cmds.emplace_back("2 " + to_string(p.first) + " " + to_string(p.second));}
inline void cmdClean(const P& p, vector<string>& cmds) {cmds.emplace_back("3 " + to_string(p.first) + " " + to_string(p.second));}
inline void cmdToggle(const P& a, const P& b, vector<string>& cmds) {cmds.emplace_back("4 " + to_string(a.first) + " " + to_string(a.second) + " " + to_string(b.first) + " " + to_string(b.second));}

struct Solution {
  double    score;
  vector<string> cmd;
};

Solution solve(int PathNum,
               int n, int k, int h, int t, int d,
               const vector<Color>& tubes,
               const vector<Color>& targets)
{
	vector<string> cmds;
	int sqrtPathNum = sqrt(PathNum);
	int tilePerPath = (n / sqrtPathNum) * (n / sqrtPathNum);
	int sqrtTilePerPath = sqrt(tilePerPath);

	vector<vector<P>> paths(PathNum);
	for (int i = 0; i < PathNum; i++) {
		int r = (i / sqrtPathNum) * (n / sqrtPathNum), c = (i % sqrtPathNum) * (n / sqrtPathNum);
		paths[i] = snake(r, r + (n / sqrtPathNum) - 1, c, c + (n / sqrtPathNum) - 1, (r + c) % 2);
	}

	Mask ms;
	for (int i = 0; i < PathNum; i++) {
		for (int j = 0; j < (int)paths[i].size() - 1; j++) {
			ms.open(paths[i][j], paths[i][j + 1]);
		}
	}
	ms.dump(cmds);
	
	vector<Color> initCol(PathNum);
	for (int i = 0; i < PathNum; i++) {
		int clr = i % k;
		cmdAdd(paths[i][0], clr, cmds);
		initCol[i] = tubes[clr];
	}

	State root;
	root.score = 0; root.depth = 0; root.id = 0, root.op_cnt = PathNum * (d < Dthreshold ? 1 : 2);
	root.tileCol.resize(PathNum);
	root.PathDir.resize(PathNum);
	for (int i = 0; i < PathNum; i++) {
		root.tileCol[i] = initCol[i];
		root.PathDir[i] = DIR::LEFT;
	}

	if (!builded) {
		builded = true;
		buildWeightTable(tilePerPath);
	}

	// ==================== Greedy 開始 ====================
	int maxTurns = h - (d < Dthreshold ? 0 : PathNum);
	for (int turn = 0; turn < maxTurns; turn++) {
		if (utility::mytm.elapsed() > TIME_LIMIT) return {1e9, cmds};

		const Color& target = targets[turn];
		int bestScore = 1e9;
		Trace bestTrace;
		
		for (int ti = 0; ti < PathNum; ti++) {
			int pr = ti / sqrtPathNum, pc = ti % sqrtPathNum;
			const Color& X = target;

			// =================== 2 色混色 Pattern ===================
			Mix2Result mix2 = findBest2mix(X, root.tileCol[ti], 4, tubes);
			if (root.score + llround(mix2.err * 10000.0) < bestScore) {
				bestTrace = Trace{'A', {ti}, {mix2.div}, mix2.ci, root.id, {}};
				bestScore = root.score + llround(mix2.err * 10000.0);
			}
				
			// =================== 3 色混色 Pattern (上下左右の path から追加で一色) ===================
			Mix3Result mix3 = findBest3mix(X, root.tileCol[ti], ti, pr, pc,
																		 sqrtPathNum, 4, tubes,
																		 root.PathDir, root.tileCol);
			int necOp = 8 + (mix3.dirs[0] != DIR::NONE ? 2 : 0) + (mix3.dirs[1] != DIR::NONE ? 2 : 0);
			if (mix3.nti >= 0
				&& t - root.op_cnt > 8 * (maxTurns - turn) + necOp
				&& root.score + llround(mix3.err * 10000.0) < bestScore) {
				bestTrace = Trace{'B', {ti, mix3.nti}, {mix3.divA, mix3.divB, mix3.divT}, mix3.ci, root.id, vector<DIR>{mix3.dirs[0], mix3.dirs[1]}};
				bestScore = root.score + llround(mix3.err * 10000.0);
			}
		}

		// cerr << "Best Color Score : " << bestScore - root.score << " at Turn " << turn << '\n';
				
		// bestTrace による状態更新
		if (bestTrace.op == 'A') {
			// ==================== 2 色混色の Pattern ==================== 
			Color newColor = (
				root.tileCol[bestTrace.tileIdxs[0]] * bestTrace.divIdxs[0] + 
				tubes[bestTrace.colorIdx] * tilePerPath
			) / (bestTrace.divIdxs[0] + tilePerPath);
			int vol1 = tilePerPath - bestTrace.divIdxs[0], vol2 = bestTrace.divIdxs[0];
			root.tileCol[bestTrace.tileIdxs[0]] = (root.tileCol[bestTrace.tileIdxs[0]] * vol1 + newColor * vol2) / (vol1 + vol2);
			root.score = bestScore;
			root.op_cnt += (bestTrace.divIdxs[0] != tilePerPath ? 4 : 2);

			// コマンド出力
			bool toggle_flag = (bestTrace.divIdxs[0] != tilePerPath);
			auto p1 = paths[bestTrace.tileIdxs[0]][0];
			auto p2 = paths[bestTrace.tileIdxs[0]][bestTrace.divIdxs[0] - 1];
			auto p3 = (toggle_flag ? paths[bestTrace.tileIdxs[0]][bestTrace.divIdxs[0]] : P(0, 0));
			if(toggle_flag) cmdToggle(p2, p3, cmds);
			cmdAdd(p1, bestTrace.colorIdx, cmds);
			cmdTake(p1, cmds);
			if(toggle_flag) cmdToggle(p2, p3, cmds);

		} else if (bestTrace.op == 'B') {
			// ==================== 3 色混色の Pattern (上下左右の path から追加で一色) ====================
			int vA = bestTrace.divIdxs[0];
			int vB = bestTrace.divIdxs[1];
			int vT = bestTrace.divIdxs[2];
			if (vT == 0) bestTrace.colorIdx = rand_int() % tubes.size();
			Color newColor  = (root.tileCol[bestTrace.tileIdxs[0]] * vA + root.tileCol[bestTrace.tileIdxs[1]] * vB +	tubes[bestTrace.colorIdx] * vT) / (vA + vB + vT);
			Color tmpColorA = (newColor * (vA + vB - (tilePerPath - vA)) + root.tileCol[bestTrace.tileIdxs[0]] * (tilePerPath - vA) +	tubes[bestTrace.colorIdx] * (tilePerPath - vA)) / (vA + vB - (tilePerPath - vA) + tilePerPath - vA + tilePerPath - vA);
			Color tmpColorB = (newColor * (vA + vB - (tilePerPath - vB)) + root.tileCol[bestTrace.tileIdxs[1]] * (tilePerPath - vB) +	tubes[bestTrace.colorIdx] * (tilePerPath - vB)) / (vA + vB - (tilePerPath - vB) + tilePerPath - vB + tilePerPath - vB);
			Color tmpColor0 = (newColor * (vA + vB - tilePerPath) +	tubes[bestTrace.colorIdx] * tilePerPath) / (vA + vB - tilePerPath + tilePerPath);

			if (vT == tilePerPath) root.tileCol[bestTrace.tileIdxs[0]] = (root.tileCol[bestTrace.tileIdxs[0]] * (tilePerPath - vA) + newColor * vA)	/ tilePerPath;
			else if (vT == 0)      root.tileCol[bestTrace.tileIdxs[0]] = (tmpColor0 * vA +	root.tileCol[bestTrace.tileIdxs[0]] * (tilePerPath - vA)) / tilePerPath;
			else if (vT == vA)     root.tileCol[bestTrace.tileIdxs[0]] = tmpColorA;
			else if (vT == vB)     root.tileCol[bestTrace.tileIdxs[0]] = (tmpColorB * vA + root.tileCol[bestTrace.tileIdxs[0]] * (tilePerPath - vA)) / tilePerPath;
			// else assert(false);

			if (vT == tilePerPath) root.tileCol[bestTrace.tileIdxs[1]] = (root.tileCol[bestTrace.tileIdxs[1]] * (tilePerPath - vB) +	newColor * vB) / tilePerPath;
			else if (vT == 0)      root.tileCol[bestTrace.tileIdxs[1]] = (tmpColor0 * vB + root.tileCol[bestTrace.tileIdxs[1]] * (tilePerPath - vB)) / tilePerPath;
			else if (vT == vA)     root.tileCol[bestTrace.tileIdxs[1]] = (tmpColorA * vB + root.tileCol[bestTrace.tileIdxs[1]] * (tilePerPath - vB)) / tilePerPath;
			else if (vT == vB)     root.tileCol[bestTrace.tileIdxs[1]] = tmpColorB;
			// else assert(false);

			root.score = bestScore;
			root.op_cnt += 4;
			for (int i = 0; i < bestTrace.tileDirIdxs.size(); i++) root.op_cnt += (bestTrace.tileDirIdxs[i] != DIR::NONE ? 2 : 0);
			
			// コマンド出力
			rep(i, bestTrace.tileDirIdxs.size()) { // Path の向き変更
				if (bestTrace.tileDirIdxs[i] == DIR::NONE) continue;
				cmdToggle(paths[bestTrace.tileIdxs[i]][0], paths[bestTrace.tileIdxs[i]].back(), cmds);
				while(root.PathDir[bestTrace.tileIdxs[i]] != bestTrace.tileDirIdxs[i]) {
					vector<P> nextPath(tilePerPath);
					for (int j = 0; j < tilePerPath; j++) nextPath[j] = paths[bestTrace.tileIdxs[i]][(j + 1) % tilePerPath];
					paths[bestTrace.tileIdxs[i]] = nextPath; // 90度回転
					root.PathDir[bestTrace.tileIdxs[i]] = DIR (((int) root.PathDir[bestTrace.tileIdxs[i]] + 1) % DIR_NUM);
				}
				cmdToggle(paths[bestTrace.tileIdxs[i]][0], paths[bestTrace.tileIdxs[i]].back(), cmds);
			}

			reverse(paths[bestTrace.tileIdxs[0]].begin(), paths[bestTrace.tileIdxs[0]].end());
			bool toggle_flag1 = (bestTrace.divIdxs[0] != tilePerPath);
			bool toggle_flag2 = (bestTrace.divIdxs[1] != tilePerPath);
			if (toggle_flag1) root.op_cnt += 2;
			if (toggle_flag2) root.op_cnt += 2;
			auto p1 = paths[bestTrace.tileIdxs[0]][bestTrace.divIdxs[0] - 1];
			auto p2 = (toggle_flag1 ? paths[bestTrace.tileIdxs[0]][bestTrace.divIdxs[0]] : P(0, 0));
			auto p3 = paths[bestTrace.tileIdxs[1]][bestTrace.divIdxs[1] - 1];
			auto p4 = (toggle_flag2 ? paths[bestTrace.tileIdxs[1]][bestTrace.divIdxs[1]] : P(0, 0));
			auto p5 = paths[bestTrace.tileIdxs[0]][0];
			auto p6 = paths[bestTrace.tileIdxs[1]][0];
			auto p7 = paths[bestTrace.tileIdxs[0]].back();
			auto p8 = paths[bestTrace.tileIdxs[1]].back();
			// assert(abs(p5.first - p6.first) + abs(p5.second - p6.second) == 1);

			bool addA = (vT == vA && vT != tilePerPath && toggle_flag1);
			bool addB = !addA && (vT == vB && vT != tilePerPath && toggle_flag2);
			if (addA) cmdAdd(p7, bestTrace.colorIdx, cmds);
			if (addB) cmdAdd(p8, bestTrace.colorIdx, cmds);
			if (toggle_flag1) cmdToggle(p1, p2, cmds);
			if (toggle_flag2) cmdToggle(p3, p4, cmds);
			cmdToggle(p5, p6, cmds);
			if (vT == tilePerPath) cmdAdd(p1, bestTrace.colorIdx, cmds);
			cmdTake(p1, cmds);
			if (vT == 0) cmdAdd(p1, bestTrace.colorIdx, cmds);
			if (addA) cmdToggle(p1, p2, cmds);
			if (addB) cmdToggle(p3, p4, cmds);
			cmdToggle(p5, p6, cmds);
			if (!addA && toggle_flag1) cmdToggle(p1, p2, cmds);
			if (!addB && toggle_flag2) cmdToggle(p3, p4, cmds);
			reverse(paths[bestTrace.tileIdxs[0]].begin(), paths[bestTrace.tileIdxs[0]].end());			

		} else assert(false);
	}
	cerr << "Root Score : " << root.score << '\n';
	cerr << "Root Op Count : " << root.op_cnt << '\n';
	if (d < Dthreshold) return {root.score, cmds};

	// ==================== 最後の PathNum ターンの余った絵具を割り当てる Phase ==================== 
	int rest = max(0, h - maxTurns);
	int V = 2 + rest + PathNum;
	int S = V - 2, Tt = V - 1;
	mcf_graph<int, ll> mcf(V);

	for (int r = 0; r < rest; ++r) {
	  mcf.add_edge(S, r, 1, 0);
	  const Color &tgt = targets[maxTurns + r];
	  for (int tIdx = 0; tIdx < PathNum; ++tIdx) {
	    ll cost = llround(root.tileCol[tIdx].dist2(tgt) * 1e4);
	    mcf.add_edge(r, rest + tIdx, 1, cost);
	  }
	}
	for (int tIdx = 0; tIdx < PathNum; ++tIdx) mcf.add_edge(rest + tIdx, Tt, 1, 0);
	mcf.flow(S, Tt, rest);

	vector<int> tarOfTile(PathNum, -1);
	vector<int> tileOfTar(rest, -1);
	for (auto &e : mcf.edges()) {
	  if (e.from >= 0 && e.from < rest && e.flow) {
	    int t  = e.to   - rest;
	    int tar = e.from;
	    tarOfTile[t] = tar;
	    tileOfTar[tar] = t;
	  }
	}

	vector<vector<double>> cost(rest, vector<double>(PathNum));
	for (int r = 0; r < rest; ++r) {
	  const Color &tgt = targets[maxTurns + r];
	  for (int t = 0; t < PathNum; ++t) cost[r][t] = root.tileCol[t].dist2(tgt);
	}
	double nowScoreRest = 0.0;
	for (int r = 0; r < rest; ++r) nowScoreRest += cost[r][ tileOfTar[r] ];
	cerr << "Now Score Rest : " << llround(nowScoreRest * 1e4) << '\n';

	// 山登りで色を 2mix してなけなしの改善
	int nonUpdated = 0;
	while (utility::mytm.elapsed() < TIME_LIMIT && t - root.op_cnt >= 10 && nonUpdated < 1000) {
	  int t1 = rand_int() % PathNum;
	  int r1 = t1 / sqrtPathNum, c1 = t1 % sqrtPathNum;
	  int dir = rand_int() % DIR_NUM;
	  int nr  = r1 + delta[dir].first;
	  int nc  = c1 + delta[dir].second;
	  if (outField({nr, nc}, sqrtPathNum, sqrtPathNum)) continue;
	  int t2 = nr * sqrtPathNum + nc;

	  int tar1 = tarOfTile[t1];
	  int tar2 = tarOfTile[t2];

	  double cur = 0.0;
	  cur += cost[tar1][t1];
	  cur += cost[tar2][t2];

	  double best = cur;
	  int bestA = -1, bestB = -1;
	  for (int dA = 1; dA <= tilePerPath; ++dA) {
	    for (int dB = 1; dB <= tilePerPath; ++dB) {
				Color newCol = (root.tileCol[t1] * dA + root.tileCol[t2] * dB) / double(dA + dB);
	      Color mix1 = (newCol * dA + root.tileCol[t1] * (tilePerPath - dA)) / double(tilePerPath);
				Color mix2 = (newCol * dB + root.tileCol[t2] * (tilePerPath - dB)) / double(tilePerPath);
	      double cand = 0.0;
	      cand += mix1.dist2(targets[maxTurns + tar1]);
	      cand += mix2.dist2(targets[maxTurns + tar2]);
	      if (cand < best) {
	        best = cand;
					bestA = dA;
					bestB = dB;
	      }
	    }
	  }

	  bool accept = false;
	  if (best < cur) accept = true;
	  if (!accept) {
			nonUpdated++;
			continue;
		}
	  Color newCol = (root.tileCol[t1] * bestA + root.tileCol[t2] * bestB) / double(bestA + bestB);
		Color mix1 = (newCol * bestA + root.tileCol[t1] * (tilePerPath - bestA)) / double(tilePerPath);
		Color mix2 = (newCol * bestB + root.tileCol[t2] * (tilePerPath - bestB)) / double(tilePerPath);
		root.tileCol[t1] = mix1;
		root.tileCol[t2] = mix2;
		cost[tar1][t1] = mix1.dist2(targets[maxTurns + tar1]);
		cost[tar2][t2] = mix2.dist2(targets[maxTurns + tar2]);

		// コマンド出力
		DIR d1 = (DIR) dir, d2 = revDir(d1);
		if (root.PathDir[t1] != d1) {
			cmdToggle(paths[t1][0], paths[t1].back(), cmds);
			while (root.PathDir[t1] != d1) {
				vector<P> nextPath(tilePerPath);
				for (int j = 0; j < tilePerPath; j++) nextPath[j] = paths[t1][(j + 1) % tilePerPath];
				paths[t1] = nextPath; // 90度回転
				root.PathDir[t1] = DIR (((int) root.PathDir[t1] + 1) % DIR_NUM);
			}
			cmdToggle(paths[t1][0], paths[t1].back(), cmds);
			root.op_cnt += 2;
		}
		if (root.PathDir[t2] != d2) {
			cmdToggle(paths[t2][0], paths[t2].back(), cmds);
			while (root.PathDir[t2] != d2) {
				vector<P> nextPath(tilePerPath);
				for (int j = 0; j < tilePerPath; j++) nextPath[j] = paths[t2][(j + 1) % tilePerPath];
				paths[t2] = nextPath; // 90 度回転
				root.PathDir[t2] = DIR (((int) root.PathDir[t2] + 1) % DIR_NUM);
			}
			cmdToggle(paths[t2][0], paths[t2].back(), cmds);
			root.op_cnt += 2;
		}
		
		bool toggle_flag1 = (bestA != tilePerPath);
		bool toggle_flag2 = (bestB != tilePerPath);
		root.op_cnt += 2;
		if (toggle_flag1) root.op_cnt += 2;
		if (toggle_flag2) root.op_cnt += 2;
		auto p1 = paths[t1][bestA - 1];
		auto p2 = (toggle_flag1 ? paths[t1][bestA] : P(0, 0));
		auto p3 = paths[t2][bestB - 1];
		auto p4 = (toggle_flag2 ? paths[t2][bestB] : P(0, 0));
		auto p5 = paths[t1][0];
		auto p6 = paths[t2].back();

		if (toggle_flag1) cmdToggle(p1, p2, cmds);
		if (toggle_flag2) cmdToggle(p3, p4, cmds);
		cmdToggle(p5, p6, cmds);
		cmdToggle(p5, p6, cmds);
		if (toggle_flag1) cmdToggle(p1, p2, cmds);
		if (toggle_flag2) cmdToggle(p3, p4, cmds);

		nonUpdated = 0;
	}

	mcf = mcf_graph<int, ll>(V);
	for (int r = 0; r < rest; ++r) {
	  mcf.add_edge(S, r, 1, 0);
	  const Color &tgt = targets[maxTurns + r];
	  for (int tIdx = 0; tIdx < PathNum; ++tIdx) {
	    ll cost = llround(root.tileCol[tIdx].dist2(tgt) * 1e4);
	    mcf.add_edge(r, rest + tIdx, 1, cost);
	  }
	}
	for (int tIdx = 0; tIdx < PathNum; ++tIdx) mcf.add_edge(rest + tIdx, Tt, 1, 0);
	mcf.flow(S, Tt, rest);

	int final_score = root.score + (PathNum + maxTurns - h) * d;
	for (auto& e : mcf.edges()) {
		if (e.from >= 0 && e.from < rest && e.flow) {
			int targIdx = maxTurns + e.from;
			int tileIdx = e.to - rest;
			cmdTake(paths[tileIdx][0], cmds);
			final_score += e.cost * e.flow;
		}
	}
	cerr << "PathNum = " << PathNum << " : Final Score : " << final_score << "\n\n";
	return {double(final_score), cmds};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, h, t, d;
	if (!(cin >> n >> k >> h >> t >> d)) return 0;
	utility::mytm.CodeStart();

	vector<Color> tubes(k), targets(h);
	for (auto& c : tubes)   cin >> c.c >> c.m >> c.y;
	for (auto& c : targets) cin >> c.c >> c.m >> c.y;

	vector<int> cand = {100, 81, 64, 49};
	// vector<int> cand = {100};
  Solution bestSol{(1LL<<60),{}};

  for (auto p : cand) {
    Solution cur = solve(p, n, k, h, t, d, tubes, targets);
    if (cur.score < bestSol.score) bestSol = move(cur);
    if (utility::mytm.elapsed() > TIME_LIMIT || d < Dthreshold) break;
  }

  for (auto& s : bestSol.cmd) cout << s << '\n';
  cerr << "best score = " << bestSol.score << '\n';

	return 0;
}
