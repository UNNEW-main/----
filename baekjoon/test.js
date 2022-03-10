let input = require('fs').readFileSync('baekjoon/test.txt').toString().trim().split('\n');

let [count, costs, ...ways] = input;
costs = costs.split(' ').map(Number);

console.log(count);
console.log(costs);
console.log(ways);
let result = 0;
let 전체도시 = Array.from(Array(Number(count)), () => 0);
// [0,0,0,0,0]

console.log(costs.indexOf(Math.min(...costs)));

function gogogo(시작점index, 이동한도시들index) {}
