#include <ctime>
#include <iostream>

#include "Eigen/Core"
#include "Eigen/Dense"
#include "Eigen/Geometry"
#include "Eigen/src/Core/Matrix.h"
#include "Eigen/src/Core/util/Constants.h"
#include "Eigen/src/Eigenvalues/SelfAdjointEigenSolver.h"

using std::cout;
using std::endl;

int main() {
  cout << "===============Simple matrix operation===============" << endl;
  Eigen::Matrix<float, 2, 3> matrix23;
  Eigen::Vector3d v3d;
  Eigen::Matrix3d matrix33 = Eigen::Matrix3d::Zero();

  Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrixDynamic;

  Eigen::MatrixXd matrixX;

  cout << "Insert matrix23 << 1, 2, 3, 4, 5, 6" << endl;
  matrix23 << 1, 2, 3, 4, 5, 6;
  cout << "matrix23:" << endl << matrix23 << endl;

  cout << "Using for loop to operate matrix23:" << endl;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cout << matrix23(i, j) << " ";
    }
    cout << endl;
  }

  cout << "Insert v3d << 3, 2, 1" << endl;
  v3d << 3, 2, 1;
  cout << "v3d:" << endl << v3d << endl;

  // Can't not operate two different data type.
  // Eigen::Matrix<double, 2, 1> result_wrong = matrix23 * v3d;

  // It can use cast() operation to convert consistent data type.
  Eigen::Matrix<double, 2, 1> result = matrix23.cast<double>() * v3d;
  cout << "matrix23 * v3d:" << endl << result << endl;

  matrix33 = Eigen::Matrix3d::Random();
  cout << "Random matrix33:" << endl << matrix33 << endl;
  cout << "matrix33 transpose:" << endl << matrix33.transpose() << endl;
  cout << "matrix33 sum:" << endl << matrix33.sum() << endl;
  cout << "matrix33 trace:" << endl << matrix33.trace() << endl;
  cout << "10 * matrix33:" << endl << 10 * matrix33 << endl;
  cout << "matrix33 inverse:" << endl << matrix33.inverse() << endl;
  cout << "matrix33 determinant:" << endl << matrix33.determinant() << endl;

  Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigenSolver(
      matrix33.transpose() * matrix33);
  cout << "matrix33 eigen values:" << endl
       << eigenSolver.eigenvalues() << std::endl;
  cout << "matrix33 eigen vectors:" << endl
       << eigenSolver.eigenvectors() << std::endl;

  cout << "Compare directly inverse solution and Qr composition" << endl;
  constexpr int MATRIX_SIZE = 50;

  Eigen::Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrixNN;
  matrixNN = Eigen::MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
  Eigen::Matrix<double, MATRIX_SIZE, 1> vNd;
  vNd = Eigen::MatrixXd::Random(MATRIX_SIZE, 1);

  clock_t timeStart = clock();
  Eigen::Matrix<double, MATRIX_SIZE, 1> x = matrixNN.inverse() * vNd;
  cout << "Time use in normal inverse is:"
       << 1000 * (clock() - timeStart) / static_cast<double>(CLOCKS_PER_SEC)
       << " ms" << endl;

  timeStart = clock();
  x = matrixNN.colPivHouseholderQr().solve(vNd);
  cout << "Time use in Qr composition is:"
       << 1000 * (clock() - timeStart) / static_cast<double>(CLOCKS_PER_SEC)
       << " ms" << endl;

  return 0;
}