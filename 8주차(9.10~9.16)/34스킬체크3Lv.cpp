//2문제 중 1문제만 품
//참고
//기지국 설치
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
  int answer = 0;
  int index = 0;
  int i=1;
  while(i<=n){
    if(i>=stations[index]-w && i<= stations[index]+w){
      i = stations[index]+w;
      index++;
      i++;
    }else{
      i+=(2*w +1);
      answer++;
    }
    
  }
  
  return answer;
}