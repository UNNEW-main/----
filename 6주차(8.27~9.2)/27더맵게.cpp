//이 문제는 30일(월)에 풀었다. 28일에 못푼 실력테스트 문제다.
//https://programmers.co.kr/learn/courses/30/lessons/42626
//스스로 문제 정해서 품


#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue< int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
    while(pq.size()!=1 && pq.top() < K){
        int first = pq.top();
        pq.pop();
        int second= pq.top();
        pq.pop();
        pq.push(first + second*2);
        answer++;
    }
    
    if(pq.top() < K) return answer= -1;
    return answer;
}