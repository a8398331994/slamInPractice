#include "Eigen/Core"
#include "Eigen/Geometry"
#include "Eigen/src/Geometry/AngleAxis.h"
#include "Eigen/src/Geometry/Quaternion.h"
#include "Eigen/src/Geometry/Transform.h"
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Eigen::Matrix3d rotationMatrix = Eigen::Matrix3d::Identity();

  cout << "Set rotation vector with angle (x:0, y:0, z:45)" << endl;
  Eigen::AngleAxisd rotationVector(M_PI / 4, Eigen::Vector3d(0, 0, 1));

  cout.precision(3);
  cout << "Rotation vector to matrix:" << endl
       << rotationVector.matrix() << endl;

  rotationMatrix = rotationVector.toRotationMatrix();
  cout << "Rotation vector convert to rotation matrix:" << endl
       << rotationMatrix << endl;

  cout << "Create a vector v1(1, 0, 0)" << endl;
  Eigen::Vector3d v1(1, 0, 0);
  Eigen::Vector3d v1Rotated = rotationVector * v1;

  cout << "Vector v1 after multiply by rotation vector:" << endl
       << v1Rotated << endl;

  v1Rotated = rotationMatrix * v1;
  cout << "Vector v1 after multiply by rotation matrix:" << endl
       << v1Rotated << endl;

  cout << "Create euler angle e1 by existed rotation matrix in ZYX order"
       << endl;
  Eigen::Vector3d e1 = rotationMatrix.eulerAngles(2, 1, 0);
  cout << "e1 in z, y, x order:" << endl << e1 * 180.0F / M_PI << endl;

  Eigen::Isometry3d T = Eigen::Isometry3d::Identity();
  cout << "Create 4x4 transformation matrix T:" << endl << T.matrix() << endl;

  cout << "Apply T with rotation vector." << endl
       << "Apply T with translate vector (1, 3, 4)." << endl;

  T.rotate(rotationVector);
  T.pretranslate(Eigen::Vector3d(1, 3, 4));

  cout << "Transform matrix:" << endl << T.matrix() << endl;

  Eigen::Vector3d v1Transformed = T * v1;
  cout << "v1 after apply transform matrix:" << endl << v1Transformed << endl;

  Eigen::Quaterniond q = Eigen::Quaterniond(rotationVector);
  cout << "Create quaternion and apply rotation vector:" << endl
       << q.coeffs() << endl;

  q = Eigen::Quaterniond(rotationMatrix);
  cout << "Set quaternion with rotation matrix:" << endl << q.coeffs() << endl;

  v1Rotated = q * v1;
  cout << "Vector v1 after apply quaternion:" << endl << v1Rotated << endl;

  return 0;
}