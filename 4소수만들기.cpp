//https://programmers.co.kr/learn/courses/30/lessons/12977

#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
  int answer = 0;
  
  for(int i=0;i<nums.size()-2;++i){
      for(int j=i+1;j<nums.size()-1;++j){
          for(int k=j+1;k<nums.size();++k){
              int result =0;
              for(int num = 2; num <= (nums[i] + nums[j] + nums[k])/2;++num){
                  if((nums[i] + nums[j] + nums[k])%num ==0) {
                      result ++;
                  }
              }
              if(result == 1){
                  answer++;
                  result=0;
              }
          }
      }
  }
  return answer;
}