//https://www.acmicpc.net/problem/2565
//LIS 응용...
//trim()의 중요성

let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let [count, ...lines] = input;
count = Number(count);
lines = lines.map((i) => i.split(' ').map((v) => Number(v)));

lines.sort((a, b) => a[0] - b[0]);
let dp = Array(count).fill(1);

for (let i = 1; i < count; ++i) {
  let num = 0;
  for (let j = 0; j < i; ++j) {
    if (lines[i][1] > lines[j][1]) {
      num = Math.max(num, dp[j]);
    }
  }
  dp[i] = num + 1;
}
console.log(count - Math.max(...dp));
