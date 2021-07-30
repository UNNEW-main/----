//https://programmers.co.kr/learn/courses/30/lessons/42583

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;
  int allWeight = 0;
  int endTruck = 0;
  int vlist =0;
  vector<vector<int>> v;
  
  queue<int> stay;
  queue<int> ing;
  
  for(int i=0;i<truck_weights.size();++i){
    stay.push(truck_weights[i]);
  }
  
  while (endTruck != truck_weights.size()) {
    for(int i=0;i<vlist;++i){
      v[i][0]--;
      if(v[i][0] == 0) {
        endTruck++;
        allWeight -= ing.front();
        ing.pop();
      }
    }
    if(!stay.empty() && weight >= allWeight + stay.front()){
      allWeight += stay.front();
      v.push_back(vector<int>());
      v[vlist++].push_back(bridge_length);
      ing.push(stay.front());
      stay.pop();
    }
    answer ++; 
  }
  return answer;
}