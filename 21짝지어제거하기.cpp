//https://programmers.co.kr/learn/courses/30/lessons/12973
//약 20분
//효율성체크가 힘들어서 참고

#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
  int answer = -1;
  stack<char> str;
  for(int i=0;i<s.length();i++){
    if(str.empty() || str.top() != s[i]) str.push(s[i]);
    else if(str.top() == s[i]) str.pop();
  }
  if(str.empty()) return 1;

  return 0;
}