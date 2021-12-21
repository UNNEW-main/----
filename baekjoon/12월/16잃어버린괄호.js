//https://www.acmicpc.net/problem/1541
//접근은 쉬웠지만 계산이 귀찮

let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('-');
let result = 0;
for (let i = 0; i < input.length; ++i) {
  let temp = 0;

  let noPlus = input[i].split('+');
  for (let j = 0; j < noPlus.length; ++j) {
    temp += Number(noPlus[j]);
  }
  if (i === 0) result += temp;
  else result -= temp;
}
console.log(result);
