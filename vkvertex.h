#ifndef VKVERTEX_H
#define VKVERTEX_H

#include "iostream"

class VKVertex
{
public:
    VKVertex() : x(0.f), y(0.f), z(0.f), r(0.f), g(0.f), b(0.f), u(0.f), v(0.f) {}
    VKVertex(float setX, float setY, float setZ, float setR, float setG, float setB, float setU = 0.f, float setV = 0.f);

    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
    float u;
    float v;

    VKVertex operator+(VKVertex other);
    VKVertex operator-(VKVertex other);
    VKVertex operator*(float f);

    float GetDistanceTo(VKVertex other);

    friend std::ostream& operator<< (std::ostream&, const VKVertex&);

    friend std::istream& operator>> (std::istream&, VKVertex&);
};

#endif // VKVERTEX_H
