//https://www.acmicpc.net/problem/19941

let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

let counts = input[0];
let table = input[1];
let [N, K] = counts.split(' ').map(Number);
let arr = Array.from(Array(N), () => 0);

let result = 0;
for (let i = 0; i < N; ++i) {
  //햄버거면 무시
  if (table[i] === 'H') continue;
  //사람이면 아래껄 실행
  if (table[i] === 'P') {
    let check = 0;
    //먼저 왼쪽을 봄
    for (let j = K; j >= 1; --j) {
      //왼쪽에 범위안에 0이 있으면 먹고 1로 만듬
      if (i - j >= 0 && arr[i - j] === 0 && table[i - j] === 'H') {
        result += 1;
        arr[i - j] = 1;
        check = 1;
        break;
      }
    }
    if (check === 1) continue;
    //왼쪽에 없으면 오른쪽 봄
    for (let j = 1; j <= K; ++j) {
      //오른쪽 범위안에 0이 있으면 먹고 1로 만듬
      if (i + j < N && arr[i + j] === 0 && table[i + j] === 'H') {
        result += 1;
        arr[i + j] = 1;
        check = 1;
        break;
      }
    }
    //둘다 없으면 넘김
  }
}
console.log(result);
