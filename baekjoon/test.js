//https://www.acmicpc.net/problem/1520

let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

let size = input[0].split(' ').map(Number); //세로 , 가로
let rooms = [];
let xx = [1, -1, 0, 0];
let yy = [0, 0, 1, -1];
let v = Array.from(Array(size[0]), () => Array(size[1]).fill(-1)); //방문한 값 저장
//값 입력받기
for (let i = 1; i < input.length; i++) {
  if (input[i] !== '') {
    rooms.push(input[i].split(' ').map(Number));
  }
}

let result = dps(0, 0);
console.log(result);

function dps(x, y) {
  if (x === size[1] - 1 && y === size[0] - 1) return 1;
  if (v[y][x] !== -1) return v[y][x];
  v[y][x] = 0;
  for (let i = 0; i < 4; ++i) {
    let nextX = x + xx[i];
    let nextY = y + yy[i];
    if (nextX >= 0 && nextY >= 0 && nextX < size[1] && nextY < size[0] && rooms[y][x] > rooms[nextY][nextX]) {
      v[y][x] += dps(nextX, nextY);
    }
  }
  return v[y][x];
}
