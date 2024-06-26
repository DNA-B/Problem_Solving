#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10001
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int T, N, D, C;
/***********************/

pair<int, int> dijk(vector<pair<int, int>> adj[BOUND], int st) {
	int cnt = 0, t = -1;
	int d[BOUND];
	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> pq;

	fill(d, d + (N + 1), INT_MAX);

	d[st] = 0;
	pq.push({ d[st], st });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if (d[cur.Y] != cur.X)
			continue;

		cnt++; // 다익스트라는 각 정점을 한 번씩만 방문함

		for (auto nxt : adj[cur.Y]) {
			if (d[nxt.Y] > d[cur.Y] + nxt.X) {
				d[nxt.Y] = d[cur.Y] + nxt.X;
				pq.push({ d[nxt.Y], nxt.Y });
			}
		}
	}

	for (int i = 1; i <= N; i++) { // INT_MAX가 아닌 d 값중 최대값이 맨 마지막에 감염된 컴퓨터
		if (d[i] == INT_MAX)
			continue;

		if (t < d[i])
			t = d[i];
	}

	return { cnt, t };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		vector<pair<int, int>> adj[BOUND];

		cin >> N >> D >> C;

		for (int a, b, s, i = 0; i < D; i++) {
			cin >> a >> b >> s;
			adj[b].push_back({ s, a });
		}

		auto [cnt, t] = dijk(adj, C);
		cout << cnt << " " << t << "\n";
	}

	return 0;
}