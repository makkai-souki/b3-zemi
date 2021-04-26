#include <iostream>
#include <vector>

using namespace std;

unsigned long calculatePattern(int stepNumber, vector<bool>& holes)
{
  if (stepNumber < 0) return 0;
  if (stepNumber == 0) return 1;
  if (holes[stepNumber]) return 0;
  return calculatePattern(stepNumber - 1, holes) + calculatePattern(stepNumber - 2, holes);
}

int main(int argc, char const *argv[])
{
  int n, k, tmpPosition;
  unsigned long result = 0;
  cout << "段数と穴の数を入力" << endl;
  cin >> n >> k;
  vector<bool> holes(n, false);
  for (int i = 0; i < k; i++)
  {
    cin >> tmpPosition;
    holes[tmpPosition] = true;
  }
  result = calculatePattern(n, holes);
  cout << result << endl;
  return 0;
}
