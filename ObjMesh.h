#ifndef OBJMESH_H
#define OBJMESH_H

#include "VisualObject.h"
#include <string>

class ObjMesh : public VisualObject
{
public:
    ObjMesh(const std::string& filename, const std::string& texturefilename = "");

private:
    std::string mTexture;

	bool readObjFile(const std::string& filename);
    inline std::string getTexture() { return mTexture; }
    void setTexture(const std::string& texturefilename);
};

#endif // OBJMESH_H
