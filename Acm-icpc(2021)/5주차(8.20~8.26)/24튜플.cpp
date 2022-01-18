//https://programmers.co.kr/learn/courses/30/lessons/64065
//약 30분~1시간?

#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(pair<string, int> &a, pair<string, int> &b){
  return a.second > b.second;
}

vector<int> solution(string s) {
  vector<int> answer;
  map<string, int> dic;
  for(int i=1;i<s.length()-1;++i){
    if(s[i] != '{' && s[i] != ',' && s[i] != '}'){
      for(int j=i+1;j<s.length()-1;++j){
        if(s[j]=='}' || s[j] == ','){
          dic[s.substr(i, j-i)] ++;
          i = j;
          break;
        }
      }
    }
  }
  vector<pair<string, int> > v(dic.begin(), dic.end());
  sort(v.begin(), v.end(), cmp);
  for(auto m : v){
    answer.push_back(stoi(m.first));
  }
  return answer;
}