//https://programmers.co.kr/learn/courses/30/lessons/42883
//예제는 풀었지만 체점에서 경고가 떠서 결국 참고
//number길이가 6이고 k가 2면 4개의 길이가 나온다.

//index 0부터 number길이-k까지 가장 큰 수를 answer에 넣고,
//그 큰수의 자리위치 다음부터 number길이-k+1만큼 탐색해서 가장 큰 수를 answer에 넣고
//반복...

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
  string answer = "";
  for (int j = 0, index = -1; j < number.length() - k; j++) {
    char max = 0;
    for (int i = index + 1; i <= k + j; i++) {
      if (max < number[i]) {
        index = i;
        max = number[i];
      }
    }
    answer += max;
  }
  return answer;
}