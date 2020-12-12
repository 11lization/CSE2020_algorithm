//2019017410_Moon MyeongKyun_12838

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int findset(int parent[], int x) {
	if (x == parent[x]) return x;
	return parent[x] = findset(parent, parent[x]);
}

void unionset(int parent[], int a, int b) {
	a = findset(parent, a);
	b = findset(parent, b);
	if (a < b)parent[b] = a;
	else parent[a] = b;
}

int find(int parent[], int a, int b) {
	a = findset(parent, a);
	b = findset(parent, b);
	if (a == b) {
		return 1;
	}
	else {
		return 0;
	}
}
class Edge {
public:
	int node[2];
	int weight;
	Edge(int a, int b, int weight) {
		this->node[0] = a;
		this->node[1] = b;
		this->weight = weight;
	}
};

struct compare {
	bool operator()(Edge a, Edge b) {
		if (a.weight != b.weight)
			return a.weight > b.weight;
		else if (a.node[0] != b.node[0])
			return a.node[0] > b.node[0];
		else return a.node[1] > b.node[1];
	}
};

int main() {	
	
	int N, M;
	priority_queue<Edge, vector<Edge>, compare> v;
	
	vector<Edge> vv;
	cin >> N >> M;
	int *set = new int[N];
	for (int i = 0; i < M; i++) {
		int temp1, temp2, temp3;
		cin >> temp1 >> temp2 >> temp3;
		v.push(Edge(temp1, temp2, temp3));
	}

	for (int i = 0; i < N; i++)
	{
		set[i] = i;
	}
	int count = 0;
	for (int i = 0; i < M; i++)
	{
		if (!find(set, v.top().node[0] - 1, v.top().node[1] - 1)) {
			count++;
			unionset(set, v.top().node[0] - 1, v.top().node[1] - 1);
			vv.push_back(v.top());
		}
		v.pop();
	}

	cout << count << endl;
	for (int i = 0; i < count; i++) {
		cout << vv[i].node[0] << " " << vv[i].node[1] << " " << vv[i].node[2] << "\n";
	}
	return 0;
}