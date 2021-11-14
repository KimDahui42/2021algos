#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
#define INF 99999999
#define pair pair<int,int>
int main(void) {
	int a, b, c, n, m;
	cin >> n >> m;
	vector<vector<pair>>w(n + 1);
	vector<int>dijkstra(n+1,INF);
	vector<bool> visited(n + 1, false);
	while (m--) {
		cin >> a >> b >> c;
		w[a].push_back({ b,c });
		w[b].push_back({ a,c });
	}
	priority_queue<pair>pq;
	pq.push({ 1,0 });
	dijkstra[1] = 0;
	while (!pq.empty()) {
		int current = pq.top().first;
		int weight = -pq.top().second;
		pq.pop();
		if (dijkstra[current] < weight)continue;
		for (int i = 0; i < w[current].size(); ++i) {
			int next = w[current][i].first;
			int nextWeight = weight+w[current][i].second;
			if (nextWeight < dijkstra[next]) {
				dijkstra[next] = nextWeight;
				pq.push({ next,-dijkstra[next] });
			}
		}
	}
	cout << dijkstra[n] << '\n';
	return 0;
}
