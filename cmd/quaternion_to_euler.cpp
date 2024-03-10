#include <iostream>
#include <sstream>
#include <vector>

#include "gz/math/Quaternion.hh"  

int main(int argc, char* argv[]) {
  if (argc != 3 || std::string(argv[1]) != "--quat_to_euler") {
    std::cerr << "Usage: " << argv[0] << " --quat_to_euler \"w x y z\"" << std::endl;
    return 1;
  }

  // Parse quaternion from command line argument
  std::string quaternion_str(argv[2]);
  std::istringstream iss(quaternion_str);
  std::vector<double> quaternion(4);
  if (!(iss >> quaternion[0] >> quaternion[1] >> quaternion[2] >> quaternion[3])) {
    std::cerr << "Error parsing quaternion." << std::endl;
    return 1;
  }

  // Create quaternion object
  gz::math::Quaterniond q(quaternion[0], quaternion[1], quaternion[2], quaternion[3]);

  // Convert to Euler angles
  gz::math::Vector3d euler = q.Euler();

  // Print Euler angles in degrees (assuming desired output format)
  std::cout << "Euler angles (degrees):" << std::endl;
  std::cout << "  roll:  " << euler.X() * 180.0 / M_PI << std::endl;
  std::cout << "  pitch: " << euler.Y() * 180.0 / M_PI << std::endl;
  std::cout << "  yaw:   " << euler.Z() * 180.0 / M_PI << std::endl;

  return 0;
}

