//https://programmers.co.kr/learn/courses/30/lessons/42839
//30분~1시간


#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(string numbers) {
    int answer = 0;
    vector<int> v;
    map<int, int> dic;

    for(int i=0;i<numbers.length();++i){
        v.push_back(numbers[i] - '0');
    }
    sort(v.begin(), v.end());

    do{
        int count = 0;
        vector<int> temp;
        for(int i=0;i<numbers.length();++i){
            temp.push_back(0);
        }
        for(int j=0;j<temp.size();++j){
            temp[count] = 1;
            string s = "";
            for(int i=0;i<temp.size();++i){
                if(temp[i] == 1) s += to_string(v[i]);
            }
            
            int temp_number = stoi(s);
            if(temp_number==1 || temp_number==0) {
                count++;
                continue;
            }
            dic[temp_number]++;
            if(dic[temp_number] > 1){
                count++;
                continue;
            }
            bool check=true;
            for(int i=2;i<=temp_number/2;++i){
                if(temp_number%i == 0){
                    check=false;
                    break;
                }
            }
            count++;
            if(check) answer++;
        }
    }while(next_permutation(v.begin(),v.end()));

    return answer;
}