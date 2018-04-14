//
// Created by charles on 4/14/18.
//

#ifndef PROJECT3_DISCO_H
#define PROJECT3_DISCO_H

#include "Material.h"

class Disco : public Material
{
public:
    Disco();
    Disco(int);

private:
    int duracion;
};


#endif //PROJECT3_DISCO_H
