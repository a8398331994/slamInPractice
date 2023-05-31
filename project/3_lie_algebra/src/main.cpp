#include "sophus/se3.hpp"
#include "sophus/so3.hpp"
#include <cmath>
#include <iostream>

#include "Eigen/Core"
#include "Eigen/Geometry"

using Sophus::SE3;
using Sophus::SO3;
using std::cout;
using std::endl;

typedef Eigen::Matrix<double, 6, 1> Vector6d;

int main() {
  Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI / 2.0F, Eigen::Vector3d(0, 0, 1))
                          .toRotationMatrix();

  cout << "===========SO3 operation===========" << endl;

  cout << "Create matrix R with follow element:" << endl << R.matrix() << endl;
  SO3<double> so3R(R);

  Eigen::Quaterniond q(R);
  cout << "Create quaternion q with existed R:" << endl << q.coeffs() << endl;
  SO3<double> so3Q(q);

  cout << "SO(3) from matrix:" << endl << so3R.params() << endl;
  cout << "SO(3) from quaternion:" << endl << so3R.params() << endl;

  Eigen::Vector3d so3 = so3R.log();
  cout << "so3:" << endl << so3 << endl;

  cout << "so3 hat:" << endl << SO3<double>::hat(so3) << endl;
  cout << "so3 hat vee:" << endl
       << SO3<double>::vee(SO3<double>::hat(so3)) << endl;

  Eigen::Vector3d updateSO3(1e-4, 0, 0);
  SO3<double> so3Updated = SO3<double>::exp(updateSO3) * so3R;

  cout << "so3 update:" << endl << so3Updated.params() << endl;

  cout << "===========SE3 operation===========" << endl;

  Eigen::Vector3d t(1, 0, 0);
  SE3<double> se3RT(R, t);
  SE3<double> se3Qt(q, t);

  cout << "SE3 from rotation matrix and translation:" << endl
       << se3RT.params() << endl;
  cout << "SE3 from quaternion and translation:" << endl
       << se3Qt.params() << endl;

  Vector6d se3 = se3RT.log();
  cout << "se3:" << endl << se3 << endl;

  cout << "se3 hat:" << endl << SE3<double>::hat(se3) << endl;
  cout << "se3 hat vee:" << endl
       << SE3<double>::vee(SE3<double>::hat(se3)) << endl;

  Vector6d updateSE3;
  updateSE3.setZero();
  updateSE3(0, 0) = 1e-4;
  SE3<double> se3Updated = SE3<double>::exp(updateSE3) * se3RT;

  cout << "se3 update:" << endl << se3Updated.matrix() << endl;
}