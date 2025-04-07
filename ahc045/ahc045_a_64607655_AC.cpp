/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc045/submissions/64607655
 * Submitted at: 2025-04-07 16:15:47
 * Problem URL: https://atcoder.jp/contests/ahc045/tasks/ahc045_a
 * Result: AC
 * Execution Time: 1734 ms
 */

#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); i++)

constexpr int TIME_LIMIT = 1800;
constexpr int GRID = 200;
constexpr int FIELD_SIZE = 10000;

namespace utility {
	struct Timer {
		chrono::system_clock::time_point start;
		void startTimer() { start = chrono::system_clock::now(); }
		double elapsed() const {
			using namespace std::chrono;
			return double(duration_cast<milliseconds>(system_clock::now() - start).count());
		}
	} timer;
}

inline unsigned int rand_int() {
	static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
	unsigned int tt = (tx ^ (tx << 11));
	tx = ty; ty = tz; tz = tw;
	return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
}

inline double rand_double() {
	return (double) (rand_int() % (int) 1e9) / 1e9;
}

using P = pair<int, int>;
using T = tuple<int, int, double>;

int N, M, Q, L, W;
vector<int> G;

struct Point {
	int x, y;
	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}
	Point operator+(const Point &other) const { return Point(x + other.x, y + other.y); }
	Point operator-(const Point &other) const { return Point(x - other.x, y - other.y); }
	Point operator*(const int &k) const { return Point(x * k, y * k); }
	bool operator==(const Point &other) const { return x == other.x && y == other.y; }
	bool operator!=(const Point &other) const { return !(*this == other); }
	bool operator<(const Point &other) const { return (x != other.x ? x < other.x : y < other.y); }
};

struct Rect {
	int x1, x2, y1, y2;
	Point ul, dl, ur, dr, expect;
	vector<T> existProb;
	bool expect_update;

	Rect(int _x1, int _x2, int _y1, int _y2)
		: x1(_x1), x2(_x2), y1(_y1), y2(_y2),
			ul(_x1, _y1), dl(_x2, _y1), ur(_x1, _y2), dr(_x2, _y2) {
		double areaSum = 0.0;
		int nGridX = FIELD_SIZE / GRID;
		int nGridY = FIELD_SIZE / GRID;
		rep(i, nGridX) rep(j, nGridY) {
			int cell_x1 = max(i * GRID, x1), cell_y1 = max(j * GRID, y1);
			int cell_x2 = min((i + 1) * GRID, x2), cell_y2 = min((j + 1) * GRID, y2);
			if (cell_x1 >= cell_x2 || cell_y1 >= cell_y2) continue;
			double area = (cell_x2 - cell_x1) * (cell_y2 - cell_y1);
			existProb.emplace_back((cell_x1 + cell_x2) / 2, (cell_y1 + cell_y2) / 2, area);
			areaSum += area;
		}
		for (auto &[cx, cy, prob] : existProb) prob /= areaSum;
		expect_update = false;
		assert(fabs(areaSum - (x2 - x1) * (y2 - y1)) < 1e-9);
		return;
	}

	inline Point getExpectation() {
		if (existProb.empty()) return Point((x1 + x2) / 2, (y1 + y2) / 2);
		if (expect_update) return expect;
		double tx = 0.0, ty = 0.0;
		for (const auto& [cx, cy, prob] : existProb) {
			tx += (double) cx * prob;
			ty += (double) cy * prob;
		}
		this->expect_update = true;
		return (expect = Point(llround(tx), llround(ty)), expect);
	}

	inline double getVariance() {
		if (existProb.size() <= 1) return 0.0;
		Point expPt = getExpectation();
		double variance = 0.0;
		for (const auto& [cx, cy, prob] : existProb) {
			double dx = double(cx) - expPt.x;
			double dy = double(cy) - expPt.y;
			variance += prob * (dx * dx + dy * dy);
		}
		return variance;
	}
};

struct Solver {
	vector<Rect> rects;
	vector<vector<int>> ansGroup;
	int divinationCount = 0;
	int step;

	Solver() {
		utility::timer.startTimer();
		this->input();
		ansGroup.assign(M, vector<int>{});
		step = L;
		return;
	}

	void input() {
		utility::timer.startTimer();
		cin >> N >> M >> Q >> L >> W;
		G.resize(M);
		rep(i, M) cin >> G[i];
		rep(i, N) {
			int x1, x2, y1, y2;
			cin >> x1 >> x2 >> y1 >> y2;
			rects.emplace_back(x1, x2, y1, y2);
		}
		return;
	}

	vector<pair<vector<int>, vector<P>>> answers;
	void output() {
		cout << "!" << "\n";
		for (auto &p : answers) {
			auto [group, mstEdges] = p;
			for (int id : group)
				cout << id << " ";
			cout << "\n" << flush;
			for (auto &[u, v] : mstEdges)
				cout << u << " " << v << "\n" << flush;
		}
		cerr << "Code End Time: " << utility::timer.elapsed() << "ms\n";
	}

	inline vector<P> queryDivination(const vector<int> &group) {
		assert(group.size() > 1 && group.size() <= (size_t)L);
		assert(divinationCount < Q);
		cout << "? " << group.size() << " ";
		for (auto g : group) cout << g << " ";
		cout << "\n" << flush;
		vector<P> res;
		for (size_t i = 0; i < group.size() - 1; i++) {
			int a, b;
			cin >> a >> b;
			res.emplace_back(a, b);
		}
		divinationCount++;
		return res;
	}

	vector<int> used_cnt;
	inline vector<int> selectGroup() {
		if (used_cnt.size() < N) used_cnt.assign(N, 0);
		vector<pair<int, int>> varianceScores;
		// UCB
		rep(j, N) {
			long long sigma = sqrt(rects[j].getVariance());
			varianceScores.emplace_back(sigma - sqrt(2 * log(divinationCount + 1) / (used_cnt[j] + 1)), j);
		}
		sort(varianceScores.rbegin(), varianceScores.rend()); // 逆順 (分散が高いものを占う)
		// cerr << "Max variance: " << varianceScores[0].first << '\n';

		int core = (varianceScores.empty() ? rand_int() % N : varianceScores[0].second);
		vector<int> group = { core };
		Point expCore = rects[core].getExpectation();
		vector<pair<long long, int>> neighbors;
		rep(j, N) {
			if (j == core) continue;
			Point expOther = rects[j].getExpectation();
			long long dsq = sqrt((long long)(expCore.x - expOther.x) * (expCore.x - expOther.x) + (long long)(expCore.y - expOther.y) * (expCore.y - expOther.y));
			dsq += sqrt(rects[j].getVariance());
			neighbors.emplace_back(dsq, j);
		}
		sort(neighbors.begin(), neighbors.end());
		for (const auto &[dsq, nb] : neighbors) {
			if (group.size() >= (size_t)L) break;
			group.emplace_back(nb);
		}
		for (auto g : group) used_cnt[g]++;
		return group;
	}

	inline void processMSTEdges(const vector<P> &mstEdges, const vector<int>& group) {
		set<int> nodes;
		for (const auto &[u, v] : mstEdges) {
			nodes.insert(u); nodes.insert(v);
		}
		for (int id : group) nodes.insert(id);
		vector<int> idx(nodes.begin(), nodes.end());
		map<int, int> comp;
		rep(i, idx.size()) comp[idx[i]] = i;
		vector<P> compEdges;
		for (const auto &edge : mstEdges)
			compEdges.emplace_back(comp[edge.first], comp[edge.second]);
		for (const auto &edge : compEdges) {
			int u = edge.first, v = edge.second;
			dsu uf(idx.size());
			for (const auto &[nu, nv] : compEdges) {
				if ((nu == u && nv == v) || (nu == v && nv == u))
					continue;
				if (!uf.same(nu, nv))
					uf.merge(nu, nv);
			}
			auto groups = uf.groups();
			if (groups.size() != 2) continue;
			int leaderU = uf.leader(u);
			vector<int> groupU, groupV;
			for (const auto &g : groups)
				(uf.leader(g[0]) == leaderU ? groupU : groupV) = g;
			if (groupU.empty() || groupV.empty()) continue;
			int origU = idx[u], origV = idx[v];
			for (int cu : groupU) {
				int orig = idx[cu];
				if (orig == origU || orig == origV) continue;
				updateProb(rects[origV], rects[origU], rects[orig]);
			}
			for (int cv : groupV) {
				int orig = idx[cv];
				if (orig == origU || orig == origV) continue;
				updateProb(rects[origU], rects[origV], rects[orig]);
			}
		}
	}

	const int HILBERT_ORDER = 14;
	inline uint64_t get_hilbert_order(int x, int y) {
		const int n = 1 << HILBERT_ORDER;
		uint64_t d = 0;
		x = max(0, min(n - 1, x * n / FIELD_SIZE));
		y = max(0, min(n - 1, y * n / FIELD_SIZE));
		for (int s = n / 2; s > 0; s /= 2) {
			int rx = (x & s) > 0;
			int ry = (y & s) > 0;
			d += (uint64_t)s * s * ((3 * rx) ^ ry);
			if (ry == 0) {
				if (rx == 1) {
					x = (s - 1) - x;
					y = (s - 1) - y;
				}
				swap(x, y);
			}
		}
		return d;
	}

	pair<vector<vector<int>>, long long> buildGroups(bool useHilbertOrder = true) {
		vector<Point> expectations(N);
		vector<double> variances(N);
		rep(i, N) {
			expectations[i] = rects[i].getExpectation();
			variances[i] = rects[i].getVariance();
		}
		vector<Point> centroids(M);
		if (useHilbertOrder) {
			vector<int> hilbert_order(N);
			iota(hilbert_order.begin(), hilbert_order.end(), 0);
			sort(hilbert_order.begin(), hilbert_order.end(), [&](int a, int b) {
				return get_hilbert_order(expectations[a].x, expectations[a].y) < get_hilbert_order(expectations[b].x, expectations[b].y);
			});
			vector<int> prefix_sum(M + 1, 0);
			rep(i, M) prefix_sum[i + 1] = prefix_sum[i] + G[i];
			rep(j, M) {
				int start_idx = min(prefix_sum[j], N);
				int end_idx = min(prefix_sum[j + 1], N);
				if (start_idx >= end_idx) {
					centroids[j] = Point(rand_int() % FIELD_SIZE, rand_int() % FIELD_SIZE);
					continue;
				}
				long long sum_x = 0, sum_y = 0;
				for (int k = start_idx; k < end_idx; k++) {
					int point_id = hilbert_order[k];
					sum_x += expectations[point_id].x;
					sum_y += expectations[point_id].y;
				}
				int count = end_idx - start_idx;
				centroids[j].x = llround((double)sum_x / count);
				centroids[j].y = llround((double)sum_y / count);
			}
		} else {
			vector<double> min_dist_sq(N, numeric_limits<double>::max());
			if (N > 0) {
				int first_centroid_idx = rand_int() % N;
				centroids[0] = expectations[first_centroid_idx];
				for (int i = 0; i < N; ++i) {
					long long dx = expectations[i].x - centroids[0].x;
					long long dy = expectations[i].y - centroids[0].y;
					min_dist_sq[i] = (double)dx * dx + dy * dy;
				}
				min_dist_sq[first_centroid_idx] = 0;
				for (int j = 1; j < M; ++j) {
					double dist_sq_sum = 0.0;
					for (int i = 0; i < N; ++i) {
						if (min_dist_sq[i] > 0) {
							dist_sq_sum += min_dist_sq[i];
						}
					}
					dist_sq_sum += 1e-9 * (N - j);
					if (dist_sq_sum < 1e-9) {
						for (int k = j; k < M; ++k)
							centroids[k] = Point(rand_int() % FIELD_SIZE, rand_int() % FIELD_SIZE);
						break;
					}
					uniform_real_distribution<double> dist(0.0, dist_sq_sum);
					double r = rand_double() * dist_sq_sum;
					double current_sum = 0.0;
					int next_centroid_idx = -1;
					for (int i = 0; i < N; ++i) {
						if (min_dist_sq[i] == 0)
							continue;
						current_sum += min_dist_sq[i] + 1e-9;
						if (r <= current_sum) {
							next_centroid_idx = i;
							break;
						}
					}
					if (next_centroid_idx == -1) {
						for (int i = N - 1; i >= 0; --i)
							if (min_dist_sq[i] > 0) {
								next_centroid_idx = i;
								break;
							}
					}
					if (next_centroid_idx != -1) {
						centroids[j] = expectations[next_centroid_idx];
						for (int i = 0; i < N; ++i) {
							long long dx = expectations[i].x - centroids[j].x;
							long long dy = expectations[i].y - centroids[j].y;
							min_dist_sq[i] = min(min_dist_sq[i], (double)dx * dx + dy * dy);
						}
						min_dist_sq[next_centroid_idx] = 0;
					} else {
						for (int k = j; k < M; ++k)
							centroids[k] = Point(rand_int() % FIELD_SIZE, rand_int() % FIELD_SIZE);
						break;
					}
				}
			}
		}

		const int FIXED_ITERATIONS = 10;
		const int K_NEIGHBORS = 10;
		vector<vector<int>> groupsAssign(M);
		long long final_mcf_cost = 1e18, prev_cost = -1;

		rep(iter, FIXED_ITERATIONS) {
			if (utility::timer.elapsed() > TIME_LIMIT - 200) {
				if (iter == 0 && N > 0 && groupsAssign.empty())
					groupsAssign = buildGroupsSnakeOrder();
				break;
			}
			mcf_graph<int, long long> mcf(N + M + 2);
			int s = N + M, t = N + M + 1;
			rep(i, N) mcf.add_edge(s, i, 1, 0);
			rep(j, M) if (G[j] > 0) mcf.add_edge(N + j, t, G[j], 0);
			rep(i, N) {
				vector<pair<long long, int>> dist_to_centroids;
				rep(j, M) {
					if (G[j] == 0) continue;
					long long dx = expectations[i].x - centroids[j].x;
					long long dy = expectations[i].y - centroids[j].y;
					long long cost = dx * dx + dy * dy;
					dist_to_centroids.emplace_back(cost, j);
				}
				sort(dist_to_centroids.begin(), dist_to_centroids.end());
				for (int rank = 0; rank < min((int)dist_to_centroids.size(), K_NEIGHBORS); rank++) {
					long long cost = dist_to_centroids[rank].first;
					int group_idx = dist_to_centroids[rank].second;
					mcf.add_edge(i, N + group_idx, 1, cost);
				}
			}
			auto result = mcf.flow(s, t, N);
			if (result.first < N) {
				if (iter == 0)
					groupsAssign = buildGroupsSnakeOrder();
				break;
			}
			final_mcf_cost = result.second;
			if (iter > 0 && final_mcf_cost == prev_cost)
				break;
			prev_cost = final_mcf_cost;

			vector<vector<int>> current_groups_iter(M);
			for (auto &edge : mcf.edges())
				if (edge.from >= 0 && edge.from < N && edge.to >= N && edge.to < N + M && edge.flow == 1)
					current_groups_iter[edge.to - N].emplace_back(edge.from);
			bool size_ok = true;
			rep(j, M) {
				if (current_groups_iter[j].size() != (size_t)G[j]) {
					size_ok = false;
					break;
				}
			}
			if (!size_ok) {
				if (iter == 0)
					groupsAssign = buildGroupsSnakeOrder();
				break;
			}
			groupsAssign = current_groups_iter;
			vector<Point> next_centroids(M);
			rep(j, M) {
				if (groupsAssign[j].empty())
					next_centroids[j] = centroids[j];
				else {
					long long sx = 0, sy = 0;
					for (auto pid : groupsAssign[j]) {
						sx += expectations[pid].x;
						sy += expectations[pid].y;
					}
					next_centroids[j].x = llround((double)sx / groupsAssign[j].size());
					next_centroids[j].y = llround((double)sy / groupsAssign[j].size());
				}
			}
			centroids = next_centroids;
		}
		if (groupsAssign.empty() || (N > 0 && groupsAssign.empty()))
			groupsAssign = buildGroupsSnakeOrder();

		rep(j, M) {
			if (groupsAssign[j].size() > 1)
				sort(groupsAssign[j].begin(), groupsAssign[j].end(), [&](int a, int b) {
					return get_hilbert_order(expectations[a].x, expectations[a].y) < get_hilbert_order(expectations[b].x, expectations[b].y);
				});
		}
		rep(j, M) {
			if (groupsAssign[j].size() != (size_t)G[j]) {
				cerr << "Critical Error: Final group size mismatch..." << '\n';
				groupsAssign = buildGroupsSnakeOrder();
			}
		}
		return make_pair(groupsAssign, final_mcf_cost);
	}

	vector<vector<int>> buildGroupsSnakeOrder() {
		vector<Point> expectations(N);
		rep(i, N) expectations[i] = rects[i].getExpectation();
		vector<int> perm(N);
		iota(perm.begin(), perm.end(), 0);
		int num_cols = FIELD_SIZE / GRID;
		num_cols = max(1, num_cols);
		int cellWidth = (FIELD_SIZE + num_cols - 1) / num_cols;
		map<int, vector<int>> groupsByCol;
		for (int id : perm) {
			int cx = max(0, min(FIELD_SIZE - 1, expectations[id].x));
			int col = min(cx / cellWidth, num_cols - 1);
			groupsByCol[col].emplace_back(id);
		}
		vector<int> snakeOrder;
		snakeOrder.reserve(N);
		for (auto &p : groupsByCol) {
			int col_idx = p.first;
			auto &vec = p.second;
			sort(vec.begin(), vec.end(), [&](int a, int b) {
				return expectations[a].y < expectations[b].y;
			});
			if (col_idx % 2 == 1)
				reverse(vec.begin(), vec.end());
			for (int id : vec)
				snakeOrder.emplace_back(id);
		}
		vector<vector<int>> groups(M);
		vector<int> prefix(M + 1, 0);
		rep(i, M) prefix[i + 1] = prefix[i] + G[i];
		rep(i, M) {
			int start = prefix[i];
			int sz = G[i];
			if (start >= (int)snakeOrder.size()) continue;
			int end = min(start + sz, (int)snakeOrder.size());
			groups[i].reserve(end - start);
			for (int k = start; k < end; k++)
				groups[i].emplace_back(snakeOrder[k]);
		}
		int total_assigned = 0;
		for (auto &g : groups)
			total_assigned += g.size();
		if (total_assigned != N)
			cerr << "Warning: Snake Order total assigned points (" << total_assigned << ") != N (" << N << ")" << '\n';
		return groups;
	}

	vector<P> buildMSTWithDivination(const vector<int> &group) {
		vector<P> totalEdges;
		int n = group.size();
		if (n == 2) {
			totalEdges.emplace_back(group[0], group[1]);
		} else if (n > 2) {
			for (int start = 0; start < n - 1; start += step) {
				vector<int> subGroup;
				if (n - start >= L)
					subGroup = vector<int>(group.begin() + start, group.begin() + start + L);
				else if (n - start > 2)
					subGroup = vector<int>(group.end() - min(L, n), group.end());
				else {
					totalEdges.emplace_back(group[start], group[start + 1]);
					continue;
				}
				sort(subGroup.begin(), subGroup.end());
				auto subEdges = queryDivination(subGroup);
				totalEdges.insert(totalEdges.end(), subEdges.begin(), subEdges.end());
				if(utility::timer.elapsed() <= TIME_LIMIT) processMSTEdges(subEdges, subGroup);
			}
		}
		dsu uf(N);
		rep(i, group.size()) rep(j, group.size()) {
			int u = i / step, v = j / step;
			if (u == v) continue;
			auto [ax, ay] = rects[group[i]].getExpectation();
			auto [bx, by] = rects[group[j]].getExpectation();
			long long da = sqrt((long long)(ax - bx) * (ax - bx) + (long long)(ay - by) * (ay - by));
			da += sqrt(rects[group[j]].getVariance());
			totalEdges.emplace_back(group[i], group[j]);
		}
		sort(totalEdges.begin(), totalEdges.end(), [&](const P &a, const P &b) {
			auto [ax, ay] = rects[a.first].getExpectation();
			auto [bx, by] = rects[a.second].getExpectation();
			auto [cx, cy] = rects[b.first].getExpectation();
			auto [dx, dy] = rects[b.second].getExpectation();
			long long da = sqrt((long long)(ax - bx) * (ax - bx) + (long long)(ay - by) * (ay - by));
			long long db = sqrt((long long)(cx - dx) * (cx - dx) + (long long)(cy - dy) * (cy - dy));
			return da < db;
		});
		vector<P> mstEdges;
		for (auto &[u, v] : totalEdges) {
			if (uf.same(u, v)) continue;
			uf.merge(u, v);
			mstEdges.emplace_back(u, v);
		}
		return mstEdges;
	}

	vector<P> buildMSTWithExpectation(const vector<int>& group) {
		vector<P> mst_edges;
		int n = group.size();
		if (n <= 1) return mst_edges;
		vector<tuple<long long, int, int>> potential_edges;
		potential_edges.reserve((long long)n * (n - 1) / 2);
		vector<Point> expectations_in_group(n);
		rep(i, n)
			expectations_in_group[i] = rects[group[i]].getExpectation();
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int u = group[i], v = group[j];
				const Point& pu = expectations_in_group[i];
				const Point& pv = expectations_in_group[j];
				long long dx = (long long)pu.x - pv.x;
				long long dy = (long long)pu.y - pv.y;
				long long dsq = dx * dx + dy * dy;
				potential_edges.emplace_back(dsq, u, v);
			}
		}
		sort(potential_edges.begin(), potential_edges.end());
		dsu uf(N);
		for (const auto& [dsq, u, v] : potential_edges) {
			if (mst_edges.size() == (size_t)n - 1) break;
			if (!uf.same(u, v)) {
				uf.merge(u, v);
				mst_edges.emplace_back(u, v);
			}
		}
		return mst_edges;
	}

	vector<T> newProb;
	double prob_threshold = 1e-6; // 高速化のために低確率の確率の事象は無視
	double total_prob_threshold = 1e-9;
	inline void updateProb(Rect &r1, Rect &r2, Rect &r3) {
		newProb.clear();
		double totalNewProb = 0.0;
		for (const auto &[x1, y1, prob1] : r1.existProb) {
			double condProb = 0.0;
			for (const auto &[x2, y2, prob2] : r2.existProb) {
				for (const auto &[x3, y3, prob3] : r3.existProb) {
					long long d1 = (long long)(x1 - x2) * (x1 - x2) + (long long)(y1 - y2) * (y1 - y2);
					long long d2 = (long long)(x1 - x3) * (x1 - x3) + (long long)(y1 - y3) * (y1 - y3);
					if (d1 <= d2) condProb += prob2 * prob3;
				}
			}
			double updated = prob1 * condProb;
			if (updated > prob_threshold) {
				newProb.emplace_back(x1, y1, updated);
				totalNewProb += updated;
			}
		}
		if (totalNewProb >= total_prob_threshold) {
			r1.existProb.clear();
			for (const auto &[x, y, prob] : newProb)
				r1.existProb.emplace_back(x, y, prob / totalNewProb);
		}

		// r2 phase
		newProb.clear();
		totalNewProb = 0.0;
		for (const auto &[x2, y2, prob2] : r2.existProb) {
			double condProb = 0.0;
			for (const auto &[x1, y1, prob1] : r1.existProb) {
				for (const auto &[x3, y3, prob3] : r3.existProb) {
					long long d1 = (long long)(x1 - x2) * (x1 - x2) + (long long)(y1 - y2) * (y1 - y2);
					long long d2 = (long long)(x1 - x3) * (x1 - x3) + (long long)(y1 - y3) * (y1 - y3);
					if (d1 <= d2) condProb += prob1 * prob3;
				}
			}
			double updated = prob2 * condProb;
			if (updated > prob_threshold) {
				newProb.emplace_back(x2, y2, updated);
				totalNewProb += updated;
			}
		}
		if (totalNewProb >= total_prob_threshold) {
			r2.existProb.clear();
			for (const auto &[x, y, prob] : newProb)
				r2.existProb.emplace_back(x, y, prob / totalNewProb);
		}

		// r3 phase
		newProb.clear();
		totalNewProb = 0.0;
		for (const auto &[x3, y3, prob3] : r3.existProb) {
			double condProb = 0.0;
			for (const auto &[x1, y1, prob1] : r1.existProb) {
				for (const auto &[x2, y2, prob2] : r2.existProb) {
					long long d1 = (long long)(x1 - x2) * (x1 - x2) + (long long)(y1 - y2) * (y1 - y2);
					long long d2 = (long long)(x1 - x3) * (x1 - x3) + (long long)(y1 - y3) * (y1 - y3);
					if (d1 <= d2) condProb += prob1 * prob2;
				}
			}
			double updated = prob3 * condProb;
			if (updated > prob_threshold) {
				newProb.emplace_back(x3, y3, updated);
				totalNewProb += updated;
			}
		}
		if (totalNewProb >= total_prob_threshold) {
			r3.existProb.clear();
			for (const auto &[x, y, prob] : newProb)
				r3.existProb.emplace_back(x, y, prob / totalNewProb);
		}

		r1.expect_update = false;
		r2.expect_update = false;
		r3.expect_update = false;
		return;
	}

	void solve() {
		int maxDivinations = Q;
		rep(i, M) {
			if (G[i] > 2 && G[i] <= L)
				maxDivinations--;
			else if (G[i] > L) {
				maxDivinations -= (int)((double)(G[i] - 1) / step);
				int rest = G[i] - (int)((double)(G[i] - 1) / step) * step;
				if (rest >= 3) maxDivinations--;
			}
		}
		maxDivinations = max(0, maxDivinations);
		cerr << "maxDivinations: " << maxDivinations << '\n';

		rep(i, maxDivinations) {
			if (i % 10 == 9 || i == maxDivinations - 1)
				cerr << "Divination " << i + 1 << "/" << maxDivinations << '\n';
			if (utility::timer.elapsed() > TIME_LIMIT - 200)
				break;
			auto group = selectGroup();
			auto mstEdges = queryDivination(group);
			if (mstEdges.empty()) continue;
			processMSTEdges(mstEdges, group);
		}

		auto [groups, mcf_cost] = buildGroups(true);
		cerr << "Initial groups with cost: " << mcf_cost << '\n';
		while(utility::timer.elapsed() < TIME_LIMIT * 2 / 3) {
			auto [cand_groups, cand_mcf_cost] = buildGroups(false);
			if (cand_mcf_cost < mcf_cost) {
				mcf_cost = cand_mcf_cost;
				groups = cand_groups;
				cerr << "Found better groups with cost: " << mcf_cost << '\n';
			}
		}
		ansGroup = groups;
		for (auto &group : ansGroup) {
			auto mstEdges = buildMSTWithDivination(group);
			answers.emplace_back(group, mstEdges);
		}
		return;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Solver solver;
	solver.solve();
	solver.output();
	return 0;
}
