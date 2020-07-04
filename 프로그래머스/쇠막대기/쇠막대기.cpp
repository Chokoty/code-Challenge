#include <string>
#include <stack>
#include <iostream>
using namespace std;


int solution(string arrangement) {
    stack<char> Stack;     //스택을 이용한다
    string input; 
    input =  arrangement; //매개변수 값 넣어 주고

    int cntLaser = 0, cntStick = 0, total = 0;
                          //레이저, (잘릴) 막대, 총 잘린막대 개수
    char temp;

    for(int i = 0; i < input.size(); i++){//입력받은 문자열 끝까지 반복
      temp = input[i];

      //isLaser or isStick
      if(temp == '('){ // '(' 가 나오면 스택에 넣어준다.(막대인지 레이저인지 아직 모르지만 일단 막대라고 생각하고 막대개수를 늘린다.)
          Stack.push(temp);
          cntStick += 1;
      }else if(temp == ')'){// ')'가 나오면 이전에 나온게 '('인지 ')'에 따라서 레이저인지 막대인지 알 수 있다.
        if(input[i-1] == '('){
          //isLaser -> cutStick
          cntLaser += 1;
          cntStick -= 1;  //'('가 레이저의 일부인걸 알았으므로 막대개수에서 1 뺀다.
          total += cntStick;
          
        }else{
          //endStick
          cntStick -= 1;
          total += 1;

        }
        Stack.pop();
      }
      //cout << cntLaser <<'\n';
     // cout << cntStick <<'\n';
     // cout << total <<'\n'<<'\n';
    }

    int answer = total;
    return answer;
}


int main(){
  string input = "()(((()())(())()))(())";
  cout << solution(input) <<'\n';
  return 0;
}
