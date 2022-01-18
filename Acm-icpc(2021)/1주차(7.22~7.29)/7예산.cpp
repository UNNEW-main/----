//https://programmers.co.kr/learn/courses/30/lessons/12982

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
  int answer = 0;
  int result = 0;

  sort(d.begin(), d.end());
  for(int i=0; i <=d.size(); ++i){
      if(result > budget) {
          answer = i-1;
          break;
      }
      if(i==d.size() ||result == budget){
          answer = i;
          break;
      }
      
    result += d[i];
  }

  return answer;
}