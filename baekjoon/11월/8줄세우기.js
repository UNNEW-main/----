//https://www.acmicpc.net/problem/2631
//LIS
let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

let count = input[0]; //맨 앞 입력값, 몇개를 입력받을 거냐
let numbers = []; //input값을 받을 변수
for (let i = 1; i <= count; i++) {
  numbers.push(Number(input[i]));
}
let LIS = [];

for (let i = 0; i < numbers.length; ++i) {
  LIS[i] = 1;
  for (let j = 0; j < i; ++j) {
    if (numbers[j] < numbers[i] && LIS[j] + 1 > LIS[i]) {
      //
      LIS[i] = LIS[j] + 1;
    }
  }
}
let max = 0;
for (let i = 0; i < numbers.length; i++) max = Math.max(max, LIS[i]);
console.log(numbers.length - max);
