// https://programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<vector<int>> arr;
    for(int j=0;j<commands.size();++j){
        arr.push_back(vector<int>());
        for(int i=commands[j][0];i<=commands[j][1];++i)
            arr[j].push_back(array[i-1]);
        sort(arr[j].begin(),arr[j].end());
        answer.push_back(arr[j][commands[j][2]-1]);    
    }
    
    return answer;
}