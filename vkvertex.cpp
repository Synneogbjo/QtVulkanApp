#include "vkvertex.h"

VKVertex::VKVertex() {}

VKVertex::VKVertex(float newX, float newY, float newZ, float newR, float newG, float newB, float newU, float newV)
{
    x = newX;
    y = newY;
    z = newZ;
    r = newR;
    g = newG;
    b = newB;
    u = newU;
    v = newV;
}

VKVertex VKVertex::operator+(VKVertex other)
{
    return {x + other.x, y + other.y, z + other.z, r + other.r, g + other.g, b + other.b, u, v};
}

VKVertex VKVertex::operator-(VKVertex other)
{
    return {x - other.x, y - other.y, z - other.z, r - other.r, g - other.g, b - other.b, u, v};
}

VKVertex VKVertex::operator*(float f)
{
    return {x * f, y * f, z * f, r, g, b, u, v};
}

float VKVertex::GetDistanceTo(VKVertex other)
{
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
}

std::ostream& operator<< (std::ostream& os, const VKVertex& v) {
    os << std::fixed;
    os << "(" << v.x << ", " << v.y << ", " << v.z << ") ";
    os << "(" << v.r << ", " << v.g << ", " << v.b << ") ";
    os << "(" << v.u << ", " << v.v << ") ";
    return os;
}
std::istream& operator>> (std::istream& is, VKVertex& v) {
    // Trenger fire temporære variabler som kun skal lese inn parenteser og komma
    char dum, dum2, dum3, dum4;
    is >> dum >> v.x >> dum2 >> v.y >> dum3 >> v.z >> dum4;
    is >> dum >> v.r >> dum2 >> v.g >> dum3 >> v.b >> dum4;
    is >> dum >> v.u >> dum2 >> v.v >> dum3;
    return is;
}
