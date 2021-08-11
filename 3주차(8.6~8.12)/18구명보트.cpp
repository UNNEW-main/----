//https://programmers.co.kr/learn/courses/30/lessons/42885
//40분?

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//맨 처음과 맨 마지막을 더해서 비교
//안되면 맨처음과 맨 마지막-1 을 더해서 비교
//되면 두번째와 맨 마지막 -2을 더해서 비교

int solution(vector<int> people, int limit) {
  int answer = 0;
  int next = people.size()-1;
  sort(people.begin(), people.end());
  for(int i=0;i<people.size();++i){
    if(people[i] == 0) continue;
    if(next <= i){
      next++;
      answer++;
      continue;
    }
    for(next; next>=i;--next){
      if(people[next] != 0){
        if(next==i){
          answer++;
          next = next-1;
          people[next] = 0;
          break;
        }
        if(people[i] + people[next] <= limit){
          answer++;
          people[next] = 0;
          next = next-1;
          break;
        }
      }
    }
  }
  return answer;
}