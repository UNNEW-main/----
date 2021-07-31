//https://programmers.co.kr/learn/courses/30/lessons/42586
//약 1시간 소요
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int check = 0;
    int size = 0;
    while(progresses.size()!=0){
        check = 0;
        for(int i=0;i<progresses.size();++i){
            progresses[i]+=speeds[i];
            q.push(progresses[i]);
        }
        size = q.size();
        progresses.clear();
        if(q.front()>=100){
            for(int i=0;i<size;++i){
                q.pop();
                check++;
                speeds.erase(speeds.begin());
                if(q.front()<100){
                    break;
                }
            }    
        }
        size = q.size();
        for(int i=0;i<size;++i){
            progresses.push_back(q.front());
            q.pop();
        }
        if(check!=0) answer.push_back(check);
    }
    return answer;
}