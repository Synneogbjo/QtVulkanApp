#include "vktrianglesurface.h"

#include <fstream>
VkTriangleSurface::VkTriangleSurface() : VisualObject()
{

}

VkTriangleSurface::VkTriangleSurface(const std::string &filename)
{
    std::ifstream inn(filename);
    if (!inn.is_open())
        return;
    // read input from math part of compulsory
    int n;
    VKVertex v;
    inn >> n;
    for (auto i=0; i<n; i++)
    {
        inn >> v;
        mVertices.push_back(v);
        //qDebug() << v.x << v.y << v.z;
    }
    inn.close();
}
