// https://www.acmicpc.net/problem/1238
//다익스트라...

let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
let visit = []; //방문했는지.
let dist = []; //거리에 대한 최솟값Í
let MAX = Number.MAX_SAFE_INTEGER;
let [N, M, X] = input[0].split(' ').map(Number);
X -= 1;
let road = Array.from(Array(N), () => Array(N).fill(MAX));
let result = Array.from(Array(N), () => 0);

for (let i = 1; i <= M; ++i) {
  let temp = input[i].split(' ').map(Number);
  road[temp[0] - 1][temp[1] - 1] = temp[2];
}

//1. 시작노드에서 연결된 노드의 거리를 dist에 입력
//2. 연결된 노드에서 이어진 다음 노드로 이동
//3. 다음노드의 거리를 dist에 입력(단, 이미 입력된 값이 더 크면 새로 갱신)
for (let i = 0; i < N; ++i) {
  dist = Array.from(Array(N), () => MAX);
  visit = Array.from(Array(N), () => false);
  dijkstra(i);
  if (i === X) {
    for (let j = 0; j < N; ++j) {
      result[j] += dist[j];
    }
  } else {
    result[i] += dist[X];
  }
}
console.log(Math.max(...result)); //결과

function dijkstra(start) {
  for (let i = 0; i < N; ++i) {
    dist[i] = road[start][i];
  }
  dist[start] = 0;
  visit[start] = true;
  for (let i = 0; i < N - 1; ++i) {
    let next = find_Shortest_Node();
    visit[next] = true;
    for (let i = 0; i < N; ++i) {
      if (visit[i] === true) continue;
      if (dist[i] > dist[next] + road[next][i]) {
        dist[i] = dist[next] + road[next][i];
      }
    }
  }
}
//dist중에 가장 적은 값 찾는 함수
function find_Shortest_Node() {
  let temp = MAX;
  let index;
  for (let i = 0; i < N; ++i) {
    if (visit[i] === true) continue;
    if (dist[i] < temp) {
      temp = dist[i];
      index = i;
    }
  }
  return index;
}
