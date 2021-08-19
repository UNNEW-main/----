//https://programmers.co.kr/learn/courses/30/lessons/12985
//30분?


//a와 b의 차가 1이 될때, a가 홀수일때 까지 while()
using namespace std;

int solution(int n, int a, int b)
{
  int answer = 1;
	//만약 a가 b보다 크다면 계산의 편의를 위해 둘의 값을 바꾼다.
  if(a>b){
    int t = a;
    a = b;
    b = t;
  }
  //a가 홀수이며, 두 값의 차가 1일때까지 반복한다.
  while(!(a%2 == 1 && b-a==1)){
		//a or b가 홀수면 2로 나눈후 1을 더하고 짝수면 그냥 2를 나눈다.
    a = a%2 == 1 ? a/2+1 : a/2;
		b = b%2 == 1 ? b/2+1 : b/2;
		//카운트+1한다.
    answer++;
  }
  return answer;
}