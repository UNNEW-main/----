//https://programmers.co.kr/learn/courses/30/lessons/12909
//10분

#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
  bool answer = true;
  int left = 0;
  int right = 0;
  for(int i=0;i<s.length();++i)
  {
    if(s[i] == '('){
      left++;
    }else{
      right ++;
    }
    if(right>left){
      break;
    }
  }
  if(!(left != 0 && right != 0 && left == right))
    answer = false;
  return answer;
}