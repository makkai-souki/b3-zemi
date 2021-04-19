#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
  const int dataCount = 5;
  double scoreA, scoreB, scoreC, scoreD, scoreE;
  double sum = 0, ave = 0, variance = 0, sDiv = 0;
  double divA = 0, divB = 0, divC = 0, divD = 0, divE = 0;

  cout << "5人の得点を入力" << endl;
  cin >> scoreA >> scoreB >> scoreC >> scoreD >> scoreE;

  sum = scoreA + scoreB + scoreC + scoreD + scoreE;
  ave = sum / dataCount;
  // 分散の式
  variance = (pow(scoreA, 2) + pow(scoreB, 2) + pow(scoreC, 2) + pow(scoreD, 2) + pow(scoreE, 2)) / dataCount - pow(ave, 2);
  // 標準偏差の式
  sDiv = sqrt(variance);
  // それぞれの偏差値の計算
  divA = (scoreA - ave) * 10 / sDiv + 50;
  divB = (scoreB - ave) * 10 / sDiv + 50;
  divC = (scoreC - ave) * 10 / sDiv + 50;
  divD = (scoreD - ave) * 10 / sDiv + 50;
  divE = (scoreE - ave) * 10 / sDiv + 50;

  cout << "平均:" << ave << endl;
  cout << "分散：" << variance << endl;
  cout << "標準偏差：" << sDiv <<endl;
  cout << "偏差値：1人目" << divA << endl;
  cout << "偏差値：2人目" << divB << endl;
  cout << "偏差値：3人目" << divC << endl;
  cout << "偏差値：4人目" << divD << endl;
  cout << "偏差値：5人目" << divE << endl;

  return 0;
}
