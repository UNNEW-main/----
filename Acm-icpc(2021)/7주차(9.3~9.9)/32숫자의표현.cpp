//https://programmers.co.kr/learn/courses/30/lessons/12924
//5분

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 1;
  for(int i=1;i<n-1;++i){
    int result = i;
    for(int j=i+1;j<n;++j){
      result += j;
      if(result > n)
        break;
      if(result == n)
        answer++;
    }
  }
  return answer;
}