//https://programmers.co.kr/learn/courses/30/lessons/72411?language=cpp
//3시간, 너무 어렵누
//참고


//모든 경우의 수를 찾고 그것을 map에 보관(경우의 수와 보관된 횟수)
//보관된 횟수를 내림차순으로 정렬 후 가장 큰 횟수를 가진 경우의 수들만 answer에 push_back
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
bool cmp(pair<string, int> &a, pair<string, int> &b){
  if(a.second == b.second){
    return a.first > b.first;
  }
  return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
  vector<string> answer;
  sort(orders.begin(), orders.end());
  
  for(int j=0;j< course.size(); ++j){
    map<string, int> dic;
    for(int i=0;i<orders.size();++i){
      sort(orders[i].begin(), orders[i].end());
      if(course[j] > orders[i].length()) continue;
      vector<int> temp;
      for(int k=0;k<course[j];++k)
        temp.push_back(1);
      for(int k=course[j];k<orders[i].length();++k)
        temp.push_back(0);
      do{
        string s = "";
        for(int k=0;k<temp.size();++k)
          if(temp[k] == 1)
            s.push_back(orders[i][k]);
        sort(s.begin(), s.end());
        dic[s]++;
      }while(prev_permutation(temp.begin(), temp.end()));
    }
    vector<pair<string, int> > vec(dic.begin(), dic.end());
    sort(vec.begin(), vec.end(), cmp);
    int max;
    if (!vec.empty())
      max = vec[0].second;
    if (max != 1)
      for (auto m : vec)
        if (max == m.second)
          answer.push_back(m.first);
  }
  sort(answer.begin(), answer.end());
  return answer;
}