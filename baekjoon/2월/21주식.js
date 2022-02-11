//https://www.acmicpc.net/problem/11501
//실패
//시간없어서 더이상은 못품....
let input = require('fs').readFileSync('baekjoon/test.txt').toString().trim().split('\n');

let [count, ...numbers] = input;
let arr = [];
for (let i = 0; i < count; ++i) {
  arr[i] = new Array();
  arr[i] = numbers[i * 2 + 1].split(' ').map(Number);
}

//[ [ 10, 7, 6 ], [ 3, 5, 9 ], [ 1, 1, 3, 1, 2 ] ]
let result = [];
arr.forEach((element, index) => {
  let elementResult = 0;
  let myStock = [0];
  let MaxElement = Math.max(...element);
  let MaxElementIndex = element.indexOf(MaxElement);
  for (let i = 0; i < element.length; ++i) {
    //마지막 날일때
    if (i === element.length - 1) {
      if (myStock.length > 1) {
        elementResult += myStock.reduce((prev, curr) => {
          return (prev += element[i] - curr);
        });
      }
      break;
    }
    //내일이 상향이면...가즈아!
    if ((MaxElement > element[i] && MaxElementIndex > i) || element[i] <= element[i + 1]) {
      myStock.push(element[i]);
    } else if (element[i] > element[i + 1] && MaxElement <= element[i]) {
      if (myStock.length > 1) {
        elementResult += myStock.reduce((prev, curr) => {
          return (prev += element[i] - curr);
        });
        myStock = [0];
      }
    }
  }
  result[index] = elementResult;
});
for (let i = 0; i < arr.length; ++i) {
  console.log(result[i]);
}
