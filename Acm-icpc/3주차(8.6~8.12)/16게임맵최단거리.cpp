//https://programmers.co.kr/learn/courses/30/lessons/1844
//와 이거 어려웠다. 포기
//참고

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
  int answer = 1;
  int r = maps.size();
  int c = maps[0].size();
  queue<pair<int, int> > q;
  vector<vector<bool> > visited(r, vector<bool>(c,false));
  int directX[4] ={-1, 1, 0, 0};
  int directY[4] ={0, 0, 1, -1};
  
  q.push(make_pair(0,0));
  visited[0][0] = true;
  
  while(!q.empty()){
    int size = q.size();
    for(int i=0;i<size;++i){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for(int j=0;j<4;++j){
        int nextX = x+directX[j];
        int nextY = y+directY[j];
        
        if(nextX >= 0 && nextX < r && nextY >=0 && nextY <c && !visited[nextX][nextY] && maps[nextX][nextY] != 0){
          if(nextX == maps.size()-1 && nextY == maps[0].size()-1){
            return answer+1;
          }
          q.push(make_pair(nextX, nextY));
          visited[nextX][nextY] = true;
        }
      }
    }
    answer++;
  }
  
  return -1;
}