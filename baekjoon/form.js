//////////////실행
//node baekjoon/test.js (현재경로)

//////////////한 줄에 한 단어 입력

let input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ');

let num = Number(input);

for (let i = 1; i <= num; i++) {
  console.log(i);
}

/////////////한 줄에 여러 단어 입력

let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

let [...numbers] = input;
numbers = numbers.map((i) => Number(i));
console.log(num);

//////////////여러 줄 입력

let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

let [count, ...numbers] = input;
numbers = numbers.map((i) => Number(i));

//처리방법1
for (let i = 1; i < input.length; i++) {
  //맨 앞에 count를 입력받았으니 index 1부터 시작
  if (input[i] !== '') {
    numbers.push(input[i].split(' '));
  }
}
//처리방법2
for (let i = 0; i < count; ++i) {
  arr[i] = new Array();
  arr[i][0] = numbers[i * 2].split(' ').map((item) => Number(item));
  arr[i][1] = numbers[i * 2 + 1].split(' ').map((item) => Number(item));
}
