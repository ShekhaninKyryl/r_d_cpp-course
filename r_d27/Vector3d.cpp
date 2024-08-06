#include "Vector3d.h"

Vector3d::Vector3d(float x_val, float y_val, float z_val) : x(x_val), y(y_val), z(z_val) {}


Vector3d Vector3d::crossProduct(const Vector3d& other) const {
    float crossX = y * other.z - z * other.y;
    float crossY = z * other.x - x * other.z;
    float crossZ = x * other.y - y * other.x;

    return Vector3d(crossX, crossY, crossZ);
}