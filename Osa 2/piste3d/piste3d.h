#ifndef PISTE3D_H
#define PISTE3D_H

typedef struct {
    double x;
    double y;
    double z;
} Piste3D;

double etaisyys(Piste3D point_1, Piste3D point_2);
void tulosta(Piste3D p, int tarkkuus);

#endif /* PISTE3D_H */