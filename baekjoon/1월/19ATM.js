//https://www.acmicpc.net/problem/11399

let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

let [count, numbers] = input;
numbers = numbers
  .split(' ')
  .map(Number)
  .sort((a, b) => a - b);
//[ 1, 2, 3, 3, 4 ]

let result = 0;

for (let i = 0; i < count; ++i) {
  result += numbers[i] * (count - i);
  //첫번째 숫자는 5번 나오니까 * 5
  //두번째 숫자는 4번 나오니까 * 4
}
console.log(result);
