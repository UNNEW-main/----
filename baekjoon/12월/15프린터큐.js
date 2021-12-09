//https://www.acmicpc.net/problem/1966
//전에 풀었던 우선수위 프린터 큐
let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let [count, ...numbers] = input;
let arr = [];

for (let i = 0; i < count; ++i) {
  arr[i] = new Array();
  arr[i][0] = numbers[i * 2].split(' ').map((item) => Number(item));
  arr[i][1] = numbers[i * 2 + 1].split(' ').map((item, index) => {
    if (index === arr[i][0][1]) {
      return (item = [Number(item), 99]);
    } else {
      return (item = [Number(item), 0]);
    }
  });
}
for (let i = 0; i < count; ++i) {
  Priority_Queue(arr[i][1]);
}
// [
//   [[1, 0], [5]],
//   [
//     [4, 2],
//     [1, 2, 3, 4],
//   ],
//   [
//     [6, 0],
//     [1, 1, 9, 1, 1, 1],
//   ],
// ];

// [
//   [[1, 0], [[5,99]]],
//   [
//     [4, 2],
//     [[1, 0], [2, 0], [3,99], [4, 0]],
//   ],
//   [
//     [6, 0],
//     [[1,99], [1, 0], [9, 0], [1, 0], [1, 0], [1, 0]],
//   ],
// ];

function Priority_Queue(arrProps) {
  let arrTemp = arrProps;
  let result = 0;
  let arrLength = arrProps.length;
  while (arrLength !== 0) {
    let temp = arrTemp[0];
    let check = 0;
    arrTemp.shift();
    arrLength--;
    for (let i = 0; i < arrLength; ++i) {
      if (temp[0] < arrTemp[i][0]) {
        arrTemp.push(temp);
        arrLength++;
        check = 1;
        break;
      }
    }
    if (check === 0) {
      result++;
      if (temp[1] === 99) {
        return console.log(result);
      }
    }
  }
}
