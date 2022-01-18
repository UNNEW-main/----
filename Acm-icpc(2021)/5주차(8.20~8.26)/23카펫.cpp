//https://programmers.co.kr/learn/courses/30/lessons/42842
//20분?
//질문하기 살짝 참고

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
  vector<int> answer;
  
  for(int i=3;i<=5000;++i){
    for(int j=3;j<=i;++j){
      if(i*j - (i-2)*(j-2) == brown && (i-2)*(j-2)==yellow){
        answer.push_back(i);
        answer.push_back(j);
        return answer;  
      }
    }
  }
}