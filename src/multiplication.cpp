#include "multiplication.hpp"
#include <cstdlib>

std::vector<std::vector<int> > multiplication::result(const std::vector<std::vector<int> >& A,
                                                      const std::vector<std::vector<int> >& B) {

  int row_A = A.size();
  int col_A = A[0].size();
  if (col_A != B.size()) {
    exit(1);
  }
  int col_B = B[0].size();

  std::vector<std::vector<int> > to_return;
  to_return.resize(row_A);
  for (int i = 0; i < row_A; i++) {
    to_return[i].resize(col_B);
  }

  // matrix A x matri B
  for (int i = 0; i < row_A; i++) {
    for (int j = 0; j < col_B; j++) {
      to_return[i][j] = 0;
      for (int k = 0; k < col_A; k++) {
        to_return[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  return to_return;
}
