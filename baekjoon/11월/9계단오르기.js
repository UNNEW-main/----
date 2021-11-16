//https://www.acmicpc.net/problem/2579
//최대값 구하는 기본적인 문제...

let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

let [count, ...numbers] = input;
numbers = numbers.map((i) => Number(i));
let dp = Array(count).fill(0);
dp[0] = numbers[0];
dp[1] = numbers[0] + numbers[1];
dp[2] = Math.max(numbers[0] + numbers[2], numbers[1] + numbers[2]);

for (let i = 3; i < numbers.length; ++i) {
  dp[i] = numbers[i] + Math.max(dp[i - 2], dp[i - 3] + numbers[i - 1]);
}
console.log(dp[count - 1]);
