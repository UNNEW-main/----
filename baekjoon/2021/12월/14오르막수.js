//https://www.acmicpc.net/problem/11057
//처음 방법대로 쓸껄...

let input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ');

let num = Number(input);
let dp = Array.from(Array(1001), () => Array(10).fill(0));
let result = 0;

for (let i = 0; i < 10; ++i) {
  dp[1][i] = 1;
}
for (let i = 2; i <= num; ++i) {
  for (let j = 0; j < 10; ++j) {
    for (let k = j; k < 10; ++k) {
      dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
    }
  }
}
for (let i = 0; i < 10; ++i) {
  result = (result + dp[num][i]) % 10007;
}
console.log(result);
