//https://programmers.co.kr/learn/courses/30/lessons/12911
//5분

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int func(int n){
  int oneN = 0;
  while(n>0){
    if(n%2 == 1) oneN++;
    n/=2;
  }
  return oneN;
}

int solution(int n) {
  int answer = 0;
  int oneN = func(n);
  int oneN2 =0;
  while(oneN !=oneN2){
    n++;
    oneN2 = func(n);
  }
  return answer = n;
}