// const A = [3, 2, 2, -5, 2, 4, -4, 6, -1, 4, -8, -7, 6, -1, -1, -1, -1, 2];

// const A = [3, 2, 6, 2, 1, 3, 2];
// const A = [3, 2, 6, -1, 4, 5, -1, 2];

const arr = [...A];
let result = 0;
arr.shift();
arr.pop();
const MIN = Math.min(...arr);
// console.log('MIN', MIN);

const MinIndex = arr.indexOf(MIN);
// console.log('MinIndex', MinIndex);

if (MIN >= 0) {
  for (let i = 1; i < A.length - 1; ++i) {
    if (MinIndex + 1 !== i) {
      result += A[i];
    }
  }
} else {
  let FrontMIN = Math.min(...arr.slice(0, MinIndex));
  let BackMIN = Math.min(...arr.slice(MinIndex + 1, arr.length));
  let FrontMINIndex = arr.indexOf(FrontMIN);
  let BackMINIndex = arr.indexOf(BackMIN, MinIndex + 1);
  // console.log('FrontMIN,', FrontMIN);
  // console.log('BackMIN,', BackMIN);
  // console.log('FrontMINIndex', FrontMINIndex);
  // console.log('BackMINIndex', BackMINIndex);

  let before = 0;
  let all = 0;
  for (let i = 0; i < MinIndex; ++i) {
    if (i < FrontMINIndex) {
      before += arr[i];
    } else if (i === FrontMINIndex) {
      if (before + FrontMIN < 0) {
        all -= before;
        continue;
      }
    }
    all += arr[i];
  }
  // console.log('frontAll,', all);
  result += all;
  before = 0;
  all = 0;
  for (let i = arr.length - 1; i > MinIndex; --i) {
    if (i > BackMINIndex) {
      before += arr[i];
    } else if (i === BackMINIndex) {
      if (before + BackMIN < 0) {
        all -= before;
        continue;
      }
    }
    all += arr[i];
    console.log(i, all);
  }
  // console.log('Backbefore,', before);

  // console.log('BackAll,', all);

  result += all;
}

console.log('result', result);
