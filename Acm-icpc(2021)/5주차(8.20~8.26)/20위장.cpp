//https://programmers.co.kr/learn/courses/30/lessons/42578
//포기, 참고 (경우의 수, 수학적 계산 지식 필요)
//30분

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string> > clothes) {
  int answer = 1;
  map<string, int> dic;
  
  for(auto m : clothes){
    dic[m[1]]++;
  }
  for(auto n : dic){
    answer *= n.second+1;
  }
  
  return answer-1;
}