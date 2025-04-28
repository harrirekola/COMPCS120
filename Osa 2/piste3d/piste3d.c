#include <stdio.h>
#include <math.h>
#include "piste3d.h"

void tulosta(Piste3D p, int tarkkuus)
{   
    double x = p.x;
    double y = p.y;
    double z = p.z;

    printf("(%.*f, %.*f, %.*f)", tarkkuus, x, tarkkuus, y, tarkkuus, z);
}

double etaisyys(Piste3D point_1, Piste3D point_2)
{
    double x_1 = point_1.x;
    double y_1 = point_1.y;
    double z_1 = point_1.z;

    double x_2 = point_2.x;
    double y_2 = point_2.y;
    double z_2 = point_2.z;

    double inside = pow((x_1-x_2),2) + pow((y_1-y_2),2) + pow((z_1-z_2),2);
    return sqrt(inside);
}