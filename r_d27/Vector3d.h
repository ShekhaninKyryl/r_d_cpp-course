#pragma once

class Vector3d {

public:
    Vector3d(float x_val, float y_val, float z_val);

    Vector3d crossProduct(const Vector3d& other) const;

private:
    float x, y, z;
};