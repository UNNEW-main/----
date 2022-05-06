const N = 5;
const A = [6, 6, 6, 6, 6, 6];
// const N = 5;
// const A = [3, 4, 4, 6, 1, 4, 4];
//[3, 2, 2, 4, 2]

//5, [6, 6, 6, 6, 6, 6] => [0, 0, 0, 0, 0]
const arr = Array.from({ length: N }, () => 0);
let max = 0;
for (let i = 0; i < A.length; ++i) {
  if (A[i] === N + 1) {
    max = Math.max(...arr);
  } else if (max > arr[A[i] - 1]) {
    arr[A[i] - 1] = max + 1;
  } else {
    arr[A[i] - 1]++;
  }
}
arr.map((data) => (data > max ? data : max));

console.log(arr);

// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');
