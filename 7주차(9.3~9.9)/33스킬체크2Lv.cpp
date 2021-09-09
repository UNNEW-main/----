//통과 45분정도걸림

//1
//최대값과 최솟값
//10분?
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
  string answer = "";
  vector<int> v;
  
  string temp = "";
  for(int i=0;i<=s.length();++i){
    temp +=s[i];
    if(s[i+1] == ' '){
      v.push_back(stoi(temp));
      temp="";
      
    }
  }
  v.push_back(stoi(temp));
  
  sort(v.begin(), v.end());
  
  answer += to_string(v[0]);
  answer += " ";
  answer += to_string(v[v.size()-1]);
  return answer;
}



//2
//삼각달팽이
//30분?
//구조 참고
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
  vector<int> answer;
  int state = 0, x = 0, y = 0;
  int num = 1;
  int arr[1001][1001] ={};
  
  for(int i=0;i<n;++i){
    if(state == 0){
      for(int j=i;j<n;++j){
        arr[x++][y]=num++;
      }
      x--;
      y++;
      state = 1;
    }else if(state == 1){
      for(int j=i;j<n;++j){
        arr[x][y++]=num++;
      }
      x--;
      y-= 2;
      state = -1;
    }else if(state == -1){
      for(int j=i;j<n ; ++j){
        arr[x--][y--]=num++;
      }
      x+=2;
      y++;
      state = 0;
    }
  }
  
  for(int i=0;i<n;++i){
    for(int j=0;j<=i;++j)
      answer.push_back(arr[i][j]);
  }
  return answer;
}
