//https://programmers.co.kr/learn/courses/30/lessons/42747
//문제이해불가로 질문하기 이용
//30분?
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int big = 0;
    //정렬
    sort(citations.begin(), citations.end());
    //자신의 값을 가리키는 반복문
    for(int i=0;i<citations.size();++i){
        //비교를 위한 반복문
        for(int j=0;j<citations.size();++j){
            //자신의 값보다 크면 카운트+1
            if(citations[i] <= citations[j]){
                big++;
            }
        }
        //자신의 값을 넘지 않으며 과거의 카운트값보다 크면 실행
        if(citations[i] >= big && big>answer){
            answer = big;
        }
        //카운트값은 다시 0으로 초기화
        big = 0;
    }
    return answer;
}