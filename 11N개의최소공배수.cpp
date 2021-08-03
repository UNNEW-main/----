//https://programmers.co.kr/learn/courses/30/lessons/12953
//30분정도..?
//마지막 테스트 10이 안풀려서 참고

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b){
    if(b==0) return a;
    else return GCD(b, a%b);
}
int LCM(int a, int b){
    return a*b/GCD(a,b);
}

int solution(vector<int> arr) {
    int answer = 0;
    int result = 1;
    
    for(int i=0;i<arr.size();++i){
        result = LCM(result, arr[i]);
    }
    answer = result;
    return answer;
}