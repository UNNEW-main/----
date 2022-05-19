// a = [1, 3, 6, 4, 1, 2];

// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

const A = Array.from({ length: 100 });
for (let i = 0; i < A.length; ++i) {
  A[i] = i;
}
console.log(A);
// function solution(A) {
// write your code in JavaScript (Node.js 8.9.4)
let result = 1;
A.sort((a, b) => a - b);
for (let i = 0; i < A.length; ++i) {
  console.log(A[i]);
  if (A[i] === result) {
    console.log(result);
    result++;
  }
}
return result;
// }
