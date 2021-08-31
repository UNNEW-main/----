//https://programmers.co.kr/learn/courses/30/lessons/12981
//


#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, vector<string> words) {
  vector<int> answer;
  int a=11, b=101;
  for(int i=0;i<words.size()-1;++i){
    for(int j=i+1;j<words.size();++j){
      if(words[i] == words[j] && b>j/n+1){            
        a=j%n+1;
        b=j/n+1;
      }
    }
    if(words[i][words[i].length()-1] != words[i+1][0] && b>(i+1)/n+1){
      a=(i+1)%n+1;
      b=(i+1)/n+1;
    }
  }

  if(a ==11 && b==101){
    answer.push_back(0);
    answer.push_back(0);
  }else{
    answer.push_back(a);
    answer.push_back(b);
  }
  return answer;
}