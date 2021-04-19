#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  unsigned long target = 0;
  int checkSum = 0, digit = 0;
  bool evenFlag = false;

  cout << "14-16桁の数を入力" << endl;
  cin >> target;

  while(target > 0) {
    digit = target % 10;
    if (evenFlag) {
      digit = digit * 2;
      if (digit >= 10) digit = digit / 10 + digit % 10;
    }
    checkSum += digit;
    target /= 10;
    evenFlag = !evenFlag;
  }

  if (checkSum % 10 == 0) cout << "正常" << endl; 
  else cout << "異常" << endl;

  return 0;
}
