//https://programmers.co.kr/learn/courses/30/lessons/42747
//문제이해불가로 질문하기 이용
//30분?

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int big = 0;
    int check = 0;
    // 0 1 3 5 6
    sort(citations.begin(), citations.end());
    for(int i=0;i<citations.size();++i){
        for(int j=0;j<citations.size();++j){
            if(citations[i] <= citations[j]){
                big++;
            }
        }
        if(citations[i] >= big && big>check){
            check = big;
        }else if(citations[i] < big && citations[i] > check){
            check = citations[i];
        }
        big = 0;
    }
    
    
    return answer = check;
}