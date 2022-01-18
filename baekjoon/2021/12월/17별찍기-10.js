//https://www.acmicpc.net/problem/2447
//뭔가 단순히 어려웠음

let input = require('fs').readFileSync('/dev/stdin').toString();
let result = '';
for (let i = 0; i < input; ++i) {
  for (let j = 0; j < input; ++j) {
    star(i, j, input);
  }
  result += '\n';
}
console.log(result);

function star(i, j) {
  if (i % 3 === 1 && j % 3 === 1) result += ' ';
  else {
    if (Math.floor(i / 3) === 0 && Math.floor(j / 3) === 0) result += '*';
    else star(Math.floor(i / 3), Math.floor(j / 3));
  }
}
