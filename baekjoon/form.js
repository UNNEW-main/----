//////////////실행
//node baekjoon/1주차/test.js (현재경로)

//////////////한 줄에 한 단어 입력

let input = require('fs').readFileSync('/dev/stdin').toString().split(' ');

let num = Number(input);

for (let i = 1; i <= num; i++) {
  console.log(i);
}

/////////////한 줄에 여러 단어 입력

let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
let num = [];
for (let i = 0; i < input.length; ++i) {
  num.push(Number(input[i]));
}
console.log(num);

//////////////여러 줄 입력

let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

let count = input[0]; //맨 앞 입력값, 몇개를 입력받을 거냐
let numbers = []; //input값을 받을 변수

for (let i = 1; i < input.length; i++) {
  //맨 앞에 count를 입력받았으니 index 1부터 시작
  if (input[i] !== '') {
    numbers.push(input[i].split(' '));
  }
}

for (let i = 0; i < numbers.length; i++) {
  let num1 = Number(numbers[i][0]);
  let num2 = Number(numbers[i][1]); //만약 3개를 받는다면 하나 더 추가해야한다.

  console.log(num1 + num2);
}
