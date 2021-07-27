//https://programmers.co.kr/learn/courses/30/lessons/12903

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string num;

	if (s.length() % 2 == 0) {
		num = s.substr( s.length() / 2-1, 2);
	}
	else
		num = s.substr(s.length() / 2,1 );
	
    string answer = num;
    return answer;
}