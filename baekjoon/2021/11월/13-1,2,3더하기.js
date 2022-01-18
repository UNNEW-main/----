//https://www.acmicpc.net/problem/9095
//피보나치...?

let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

let [n, ...targets] = input;
targets = targets.map((i) => Number(i));

let arr = [0, 1, 2, 4];
for (let i = 0; i < n; ++i) {
  console.log(fc(targets[i]));
}

function fc(number) {
  if (number === 1) return arr[1];
  else if (number === 2) return arr[2];
  else if (number === 3) return arr[3];

  for (let i = 4; i <= number; ++i) {
    arr[i] = (arr[i - 3] + arr[i - 2] + arr[i - 1]) % 15746;
  }
  return arr[number];
}
