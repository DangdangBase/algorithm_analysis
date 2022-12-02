#include <fstream>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
#define ll long long
#define P pair<ll, int>
#define INF 9223372036854775807
using namespace std;

vector<vector<P>> graph;
int u, v, w;
int vertex_num;
ll max_len = 0;
int start_v, end_v;

int vertex_opt[3] = {16000, 32000, 1000000};
time_t start_time, end_time;
thread threads[100];
mutex mtx;

void dijkstras(int start) {
  priority_queue<P, vector<P>, greater<P>> pq;
  vector<ll> dist(vertex_num, INF);

  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (P cur : graph[u]) {
      int v = cur.first;
      int w = cur.second;

      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }

  ll local_max_len = 0;
  int local_end_v;
  for (int i = 0; i < vertex_num; i++) {
    if (dist[i] == INF && dist[i] > local_max_len) {
      local_max_len = dist[i];
      local_end_v = i;
    }
  }

  mtx.lock();
  if (local_max_len > max_len) {
    max_len = local_max_len;
    start_v = start;
    end_v = local_end_v;
  }
  mtx.unlock();

  return;
}

void print_elapsed_time() {
  end_time = time(NULL);
  ll elapsed_sec = (end_time - start_time);

  ll hour = elapsed_sec / 3600;
  elapsed_sec = elapsed_sec % 3600;

  ll minute = elapsed_sec / 60;
  elapsed_sec = elapsed_sec % 60;

  printf("%lldh : %lldm : %llds\n", hour, minute, elapsed_sec);
}

int main(int argc, char* argv[]) {
  vertex_num = vertex_opt[stoi(argv[1])];
  ifstream input("./data/" + to_string(vertex_num) + ".graph");

  if (!input.is_open()) {
    cout << "enter vertex num one of 16000, 32000 or 1000000.\n";
    return 0;
  }

  for (int i = 0; i <= vertex_num; i++) {
    graph.push_back(vector<P>());
  }

  while (input >> u) {
    input >> v >> w;
    graph[u].push_back({v, w});
  }

  start_time = time(NULL);
  for (int i = 0; i < vertex_num / 100; i++) {
    for (int j = 0; j < 100; j++) {
      threads[j] = thread{dijkstras, i * 100 + j};
    }

    for (int j = 0; j < 100; j++) {
      threads[j].join();
    }

    printf("%d / %d\n", i * 100, vertex_num);
    print_elapsed_time();
    cout << "\n";
  }

  cout << max_len << endl;
  return 0;
}