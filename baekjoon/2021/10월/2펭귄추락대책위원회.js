//https://www.acmicpc.net/problem/18228

let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

let arr = input[1].split(' ').map(Number);

let temp = arr[0];
let result = 0;

arr.forEach((item) => {
  if (item === -1) {
    result += temp;
    temp = arr[arr.length - 1];
    return;
  }
  if (item < temp) temp = item;
});
result += temp;
console.log(result);
