//https://programmers.co.kr/learn/courses/30/lessons/12921
//참고
#include <iostream>

using namespace std;

int solution(int n) {
  int answer = 0;
  int numbers[n+1];
  
  for(int i=2;i<=n;++i) 
    numbers[i] = i;
  
  for(int i=2;i<=n;++i){
    if(numbers[i] == 0) 
      continue;
    for(int j=2*i ;j<=n; j+=i) 
      numbers[j] = 0;
  } 
  
  for(int i=2;i<=n;++i) 
    if(numbers[i] != 0)  
      answer++; 
  return answer;
}