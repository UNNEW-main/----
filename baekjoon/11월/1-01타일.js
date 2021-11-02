//https://www.acmicpc.net/problem/1904
//피보나치...
let input = require('fs').readFileSync('/dev/stdin').toString();

let num = Number(input);
let answer = Array();
answer[0] = 0;
answer[1] = 1;
answer[2] = 2;
for (let i = 3; i <= num; ++i) {
  answer[i] = (answer[i - 1] + answer[i - 2]) % 15746;
}
console.log(answer[num]);
