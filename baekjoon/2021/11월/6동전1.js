//https://www.acmicpc.net/problem/2293
//이거 풀이는 맞는데 js문제로 무조건 메모리초과남

let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

let [count, result] = input[0].split(' ').map(Number); //count: n, result: k
let coins = []; //코인들
let temp = [];
for (let i = 1; i <= count; ++i) {
  coins.push(Number(input[i]));
}
temp[0] = 1;
for (let i = 0; i < count; ++i) {
  for (let j = coins[i]; j <= result; ++j) {
    temp[j] += temp[j - coins[i]];
  }
}
console.log(temp[result]);
