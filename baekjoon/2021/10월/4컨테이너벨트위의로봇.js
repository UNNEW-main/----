//https://www.acmicpc.net/problem/20055

let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

let [N, K] = input[0].split(' ').map(Number);

let valt = input[1].split(' ').map(Number); //벨트 내구도
let robot = []; //로봇의 위치
let start = 0,
  end = N - 1;
let answer = 0;
let zero = 0;
let visit = Array.from(Array(2 * N), () => false);
//1. 벨트움직이기
//      -1
//2. 기계 움직이기
//      다음칸에 기계가 없으며, 내구도가 1이상
//3. 기계 놓기
//      내구도 0이면 안됌
//4. 내구도확인

function ValtMove() {
  start--;
  end--;
  if (start < 0) start = 2 * N - 1;
  if (end < 0) end = 2 * N - 1;
}

function RobotMove() {
  let size = robot.length;
  for (let i = 0; i < size; ++i) {
    let cur = robot[0];
    robot.shift();
    visit[cur] = false;
    if (cur === end) continue;
    let next = cur + 1;
    if (next >= 2 * N) next = 0;
    if (visit[next] === false && valt[next] > 0) {
      valt[next]--;
      if (valt[next] == 0) zero++;

      if (next == end) continue;
      robot.push(next);
      visit[next] = true;
    } else {
      robot.push(cur);
      visit[cur] = true;
    }
  }
}
function RobotPush() {
  if (valt[start] > 0 && visit[start] === false) {
    robot.push(start);
    visit[start] == true;
    valt[start]--;
    if (valt[start] == 0) zero++;
  }
}

while (zero < K) {
  ValtMove();
  RobotMove();
  RobotPush();
  answer++;
}
console.log(answer);
