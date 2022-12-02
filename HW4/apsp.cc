#include <fstream>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
#define ll long long
#define P pair<int, int>
#define INF 987654321
using namespace std;

vector<vector<P>> graph;
int u, v, w;
int vertex_num;
int max_len = 0;
int start_v, end_v;

int vertex_opt[3] = {16000, 32000, 1000000};
time_t start_time, end_time;
mutex mtx;

void dijkstras(int start) {
  priority_queue<P, vector<P>, greater<P>> pq;
  vector<int> dist(vertex_num, INF);

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

  int local_max_len = 0;
  int local_end_v;
  for (int i = 0; i < vertex_num; i++) {
    if (dist[i] != INF && dist[i] > local_max_len) {
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
  int max_thread_num = thread::hardware_concurrency();
  thread threads[max_thread_num];

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
  for (int i = 0; i < vertex_num; i++) {
    int th_idx = i % max_thread_num;

    if (threads[th_idx].joinable()) {
      threads[th_idx].join();
    }

    threads[th_idx] = thread{dijkstras, i};

    if (!(i % 100)) {
      printf("%d / %d\n", i, vertex_num);
      print_elapsed_time();
      cout << "\n";
    }
  }

  for (int i = 0; i < 10; i++) {
    if (threads[i].joinable()) {
      threads[i].join();
    }
  }

  printf("start_v: %d, end_v: %d, max_len: %d\n", start_v, end_v, max_len);
  return 0;
}