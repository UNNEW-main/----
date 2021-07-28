//https://programmers.co.kr/learn/courses/30/lessons/12940
//참고
#include <string>
#include <vector>

using namespace std;
int GCD(int a, int b){
    if(b==0) return a;
    else return GCD(b, a%b);
}
int LCM(int a,int b){
    return a*b/GCD(a,b);
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(GCD(n ,m));
    answer.push_back(LCM(n, m));
    

    return answer;
}