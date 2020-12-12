//2019017410_Moon MyeongKyun_12838

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, timer;
bool cycle = false;

class G{

public:
    
	int clr;
    int t1;
    int t2;
	int num;
   
	vector<int> adj;
    G(int t1 , int t2, int clr){
        this->t1 = t1;
        this->t2 = t2;
        this->clr = clr;
    }
};

void DFS_VISIT(vector<G> &nodes, int x){
    timer++;
    nodes[x].t1 = timer;
    nodes[x].clr = 2;
	
    int num;
    for(int i=0; i<nodes[x].adj.size(); i++){
        num = nodes[x].adj[i];
        G *adjNodes = &nodes[num];
        if(adjNodes -> clr == 2){
            cycle = true;
            return;
        }
        else if(adjNodes -> clr == 1){
            DFS_VISIT(nodes, num);
        }
    }

    timer++;
    nodes[x].clr = 3;
    nodes[x].t2 = timer;
}

void DFS(vector<G> &nodes){
    timer = 0;
    for(int i=1; i<=N; i++){
        if(nodes[i].clr == 1){
            DFS_VISIT(nodes, i);
            if(cycle) 
				return;
        }
    }
}



bool cmp(G v1, G v2){
    return v1.t2 < v2.t2;
}

void TPS(vector<G> nodes){
    sort(nodes.begin(), nodes.end(), cmp);
    for(int i=N; i>=1; i--){
        cout << nodes[i].num << " ";
    }
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	int x,y;
	
    cin >> N >> M;

    vector<G> nodes(N+1, G(0, 0, 1));
    for(int i=1; i<=N; i++){
        nodes[i].num = i;
	}
    for(int i = 0;i < M;i++){
        cin >> x >> y;
        nodes[x].adj.push_back(y);
    }
    for(int i = 1; i <= N; i++){
        sort(nodes[i].adj.begin(), nodes[i].adj.end());
    }
    DFS(nodes);

    if(cycle)
        cout << "0\n";
    else{
        cout << "1\n";
        TPS(nodes);
    }
}
