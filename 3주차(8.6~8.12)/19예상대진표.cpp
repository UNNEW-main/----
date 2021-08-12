//https://programmers.co.kr/learn/courses/30/lessons/12985
//30분?


//a와 b의 차가 1이 될때, a가 홀수일때 까지 while()
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
  int answer = 1;
  if(a>b){
    int t = a;
    a = b;
    b = t;
  }
  
  while(!(a%2 == 1 && b-a==1)){
    int nextA =0;
    int nextB = 0;
    for(int i=1;i<=a;i= i+2){
      nextA ++;
    }
    a = nextA;
    for(int i=1;i<=b;i= i+2){
      nextB ++;
    }
    b = nextB;
    answer++;
  }
  return answer;
}