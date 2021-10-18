//https://programmers.co.kr/learn/courses/30/lessons/42587
//참고
//3시간

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
  int answer = 0;
  priority_queue<int> prio_que;
  queue<pair<int, int> > que;
  
  for(int i=0;i<priorities.size();++i){
    prio_que.push(priorities[i]);
    que.push(make_pair(priorities[i], i));
  }
  int number =1;
  while(!que.empty()){
    int value = que.front().first;
    int index = que.front().second;
    
    if(prio_que.top()==value){
      if(index == location){
        answer = number;
      }
      prio_que.pop();
      que.pop();
      number++;
    }else{
      que.push(make_pair(value, index));
      que.pop();
      
    }
  }
  return answer;
}