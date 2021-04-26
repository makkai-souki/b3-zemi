#include <iostream> 
#include <vector>

using namespace std;


void printMatrix(vector<vector<int> > &dispMat){
  for (int i = 0; i < dispMat.size(); i++)
  {
    for (int j = 0; j < dispMat[i].size(); j++)
    {
      cout << dispMat[i][j] << '\t';
    }
    cout << endl;    
  }
}

void inputMatrix(vector<vector<int> > &targetMat){
  cout << "配列の値を入力" << endl;
  for (int i = 0; i < targetMat.size(); i++)
  {
    for (int j = 0; j < targetMat[i].size(); j++)
    {
      cin >> targetMat[i][j];
    }
  }
}

void productMat(vector<vector<int> > &matA, vector<vector<int> > &matB, vector<vector<int> > &ans)
{
  int aRowSize = matA.size();
  int aColSize = matA[0].size();
  int bColSize = matB[0].size();
  int tmp = 0;
  cout << aRowSize << aColSize << bColSize << endl;
  for (int i = 0; i < aRowSize; i++)
  {
    for (int j = 0; j < bColSize; j++)
    {
      tmp = 0;
      for (int k = 0; k < aColSize; k++)
      {
        tmp += matA[i][k] * matB[k][j];
      }
      ans[i][j] = tmp;
    }
  }
}

int main(int argc, char const *argv[])
{
  int row1, row2, col1, col2;
  cout << "1つ目の行列の行数・列数を入力" << endl;
  cin >> row1 >> col1;
  cout << "2つ目の行列の行数・列数を入力" << endl;
  cin >> row2 >> col2;
  vector<vector<int> > mat1(row1, vector<int>(col1));
  vector<vector<int> > mat2(row2, vector<int>(col2));
  inputMatrix(mat1);
  inputMatrix(mat2);
  if(col1 == row2){
    vector<vector<int> > ans(row1, vector<int>(col2));
    productMat(mat1, mat2, ans);
    printMatrix(ans);
  } else {
    cout << "-" << endl;
  }
  return 0;
}
