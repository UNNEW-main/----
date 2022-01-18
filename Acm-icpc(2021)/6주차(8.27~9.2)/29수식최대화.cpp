//https://programmers.co.kr/learn/courses/30/lessons/67257
//약 1시간 참고
//1. 먼저 연산자와 숫자를 분리
//2. 연산자의 우선순위 모든 경우의 수를 탐색하면서 계산

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<char> vc;
    vector<long long> num;
    string n = "";
    for(int i=0;i<expression.length();++i){
        if(expression[i] == '-' || expression[i] =='+' || expression[i] == '*'){
            vc.push_back(expression[i]);
            num.push_back(stoi(n));
            n="";
        }else n += expression[i];
    }
    num.push_back(stoi(n));
    
    vector<int> perm ={0, 1, 2};
    string op = "+-*";
    do{
        vector<long long> temp_num = num;
        vector<char> temp_vc = vc;
        for(int i=0;i<perm.size();++i){
            for(int j=0;j<temp_vc.size();){
                if(temp_vc[j] == op[perm[i]]){
                    long long res;
                    if(temp_vc[j] == '+')
                        res = temp_num[j] + temp_num[j+1];
                    else if(temp_vc[j] == '-')
                        res = temp_num[j] - temp_num[j+1];
                    else if(temp_vc[j] == '*')
                        res = temp_num[j] * temp_num[j+1];
                    
                    temp_num.erase(temp_num.begin()+j);
                    temp_num.erase(temp_num.begin()+j);
                    temp_num.insert(temp_num.begin()+j, res);
                    temp_vc.erase(temp_vc.begin()+j);
                    
                }else j++;
            }
        }
        answer = max(answer, abs(temp_num[0]));
    }while(next_permutation(perm.begin(), perm.end()));
        
    
    return answer;
}