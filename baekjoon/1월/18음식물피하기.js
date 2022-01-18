//https://www.acmicpc.net/problem/1743
let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let [front, ...numbers] = input;
let [y, x, count] = front.split(' ').map((i) => Number(i));
numbers = numbers.map((i) => i.split(' ').map((j) => Number(j - 1)));

//[ 3, 4, 5 ]
//[ [ 3, 2 ], [ 2, 2 ], [ 3, 1 ], [ 2, 3 ], [ 1, 1 ] ]

let arr = Array.from(Array(y), () => Array(x).fill(0));
let result = 0;
let temp = 0;

//복도에 쓰레기 놓기
for (let i = 0; i < count; ++i) {
  arr[numbers[i][0]][numbers[i][1]] = 1;
}
//복도에 쓰레기 살펴보기
for (let i = 0; i < y; ++i) {
  for (let j = 0; j < x; ++j) {
    if (arr[i][j] === 1) {
      maze(i, j, arr);
      temp = 0;
    }
  }
}

console.log(result);

function maze(i, j, arr) {
  //방문표시 == 2
  arr[i][j] = 2;
  //쓰레기 몇개인지 카운트
  temp++;
  //카운트한 쓰레기수가 가장 높은 수보다 높으면 재등록
  if (temp > result) {
    result = temp;
  }

  //동
  if (j + 1 < x && arr[i][j + 1] === 1) maze(i, j + 1, arr);
  //서
  if (j - 1 >= 0 && arr[i][j - 1] === 1) maze(i, j - 1, arr);
  //남
  if (i - 1 >= 0 && arr[i - 1][j] === 1) maze(i - 1, j, arr);
  //북
  if (i + 1 < y && arr[i + 1][j] === 1) maze(i + 1, j, arr);
}
