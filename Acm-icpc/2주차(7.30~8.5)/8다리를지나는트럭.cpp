//https://programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;
  int vlist =0;
  vector<vector<int> > state;
  
  queue<int> stay;
  queue<int> crossing;
  
  for(int i=0;i<truck_weights.size();++i){
    stay.push(truck_weights[i]);
  }
  
  while (!(stay.empty() && crossing.empty())) {
    for(int i=0;i<vlist;++i){
      state[i][0]--;
      if(state[i][0] == 0) {
        weight += crossing.front();
        crossing.pop();
      }
    }
    if(!stay.empty() && weight -stay.front() >= 0){
      weight -= stay.front();
      state.push_back(vector<int>());
      state[vlist++].push_back(bridge_length);
      crossing.push(stay.front());
      stay.pop();
    }
    answer ++; 
  }
  return answer;
}