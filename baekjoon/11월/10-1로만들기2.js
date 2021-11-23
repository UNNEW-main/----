//https://www.acmicpc.net/problem/12852

let input = Number(require('fs').readFileSync('/dev/stdin').toString());

let MAX = Number.MAX_SAFE_INTEGER;
let dp = []; //값 넣는 녀석
dp[0] = 0;
dp[1] = 0;
dp[2] = 1;
dp[3] = 1;
dp[MAX] = MAX;

let process = []; //과정 넣는 녀석
process[0] = 0;
process[1] = [1];
process[2] = [2, 1];
process[3] = [3, 1];
process[MAX] = [MAX];

if (input > 3) {
  let temp = [MAX, MAX, MAX];
  for (let i = 4; i <= input; ++i) {
    temp = [MAX, MAX, MAX];
    if (i % 3 === 0) {
      temp[0] = i / 3;
    }
    if (i % 2 === 0) {
      temp[1] = i / 2;
    }
    temp[2] = i - 1;

    //3값중 가장 작은 값은?
    let tempMIN = MAX;
    let index = 0;
    for (let j = 0; j < 3; ++j) {
      if (tempMIN > dp[temp[j]]) {
        tempMIN = dp[temp[j]];
        index = j;
      }
    }
    //값 저장
    dp[i] = dp[temp[index]] + 1;
    //과정 저장
    let arr = [];
    arr.push(i);
    arr.push(...process[temp[index]]);
    process[i] = arr;
  }
  console.log(dp[input]); //값 출력
  console.log(...process[input]); //과정 출력
} else {
  console.log(dp[input]); //값 출력
  console.log(...process[input]); //과정 출력
}
