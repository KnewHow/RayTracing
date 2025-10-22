#ifndef geometry_vector3_hpp
#define geometry_vector3_hpp

#include<iostream>
class Vector3 {
  public:
    // Vector3 Public Methods
    Vector3() { x = y = z = 0; }
    Vector3(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {  }
    double x, y, z;
};
#endif  // geometry_vector3_hpp