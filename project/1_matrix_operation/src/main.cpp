#include <iostream>
#include "Eigen/Core"
#include "Eigen/Geometry"

int main()
{
    Eigen::Matrix3d rotationMatrix = Eigen::Matrix3d::Identity();

    std::cout << "rotation matrix:" << rotationMatrix.matrix() << std::endl;
}