//https://programmers.co.kr/learn/courses/30/lessons/60057
//30분 참고

#include <string>
#include <vector>
using namespace std;

int solution(string s) {
  int answer = s.length();
  
  for(int i=1;i<=s.length()/2;++i){
    int len=0;
    int count = 1;
    string temp = s.substr(0,i);
    
    for(int j=i;j<s.length();j+=i){
      if(temp == s.substr(j,i)) count++;
      else{
        if(count > 1) len += to_string(count).length();
        len+= temp.length();
        temp = s.substr(j,i);
        count=1;
      }
    }
    if(count > 1){
      len += to_string(count).length();
    }
    len += temp.length();
    if(len < answer) answer = len;
  }
  return answer;
}