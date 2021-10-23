//https://www.acmicpc.net/problem/15238

let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');

let count = input[0]; //맨 앞 입력값, 몇개를 입력받을 거냐
let string = input[1]; //input값을 받을 변수

let dic = {};

for (let i = 0; i < count; ++i) {
  if (!(string[i] in dic)) dic[string[i]] = 1;
  else dic[string[i]]++;
}

let sortedItem = Object.keys(dic)
  .map((key) => [key, dic[key]])
  .sort((first, second) => second[1] - first[1]);

console.log(sortedItem[0][0], sortedItem[0][1]);
