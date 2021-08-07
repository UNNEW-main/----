//https://programmers.co.kr/learn/courses/30/lessons/42746
//리더가 아파서 내가 하나 고름
//2시간
//참고

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp (string a, string b){
  return a+b > b+a;
}

string solution(vector<int> numbers) {
  string answer = "";
  vector<string> temp;
  
  for(int i=0;i<numbers.size();++i){
    temp.push_back(to_string(numbers[i]));
  }
  sort(temp.begin(), temp.end(), cmp);
  
  for(int i=0;i<temp.size();++i){
    answer += temp[i];
  }
  if(answer[0] == '0') return "0";
  
  return answer;
}