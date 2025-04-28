#ifndef ASTEET_H
#define ASTEET_H

typedef enum {
    Celsius,
    Fahrenheit,
    Kelvin
} Asteikko;

typedef struct asteet {
    float lampotila;
    Asteikko asteikko;
} Lampotila;

float muunna(Lampotila a, Asteikko b);
float erotus(Lampotila a, Lampotila b, Asteikko c);

#endif /* ASTEET_H */