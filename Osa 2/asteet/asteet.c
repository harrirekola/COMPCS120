#include "asteet.h"

float muunna(Lampotila a, Asteikko b)
{
    float tulos = 0.0;
    
    switch (a.asteikko)
    {
        case Celsius:
            if (b == Celsius) {
                tulos = a.lampotila;
            } else if (b == Fahrenheit) {
                tulos = a.lampotila * 9.0 / 5.0 + 32.0;
            } else if (b == Kelvin) {
                tulos = a.lampotila + 273.15;
            }
            break;
            
        case Fahrenheit:
            if (b == Fahrenheit) {
                tulos = a.lampotila;
            } else if (b == Celsius) {
                tulos = (a.lampotila - 32.0) * 5.0 / 9.0;
            } else if (b == Kelvin) {
                tulos = (a.lampotila - 32.0) * 5.0 / 9.0 + 273.15;
            }
            break;
            
        case Kelvin:
            if (b == Kelvin) {
                tulos = a.lampotila;
            } else if (b == Celsius) {
                tulos = a.lampotila - 273.15;
            } else if (b == Fahrenheit) {
                tulos = (a.lampotila - 273.15) * 9.0 / 5.0 + 32.0;
            }
            break;
            
        default:
            tulos = a.lampotila;
            break;
    }
    
    return tulos;
}

float erotus(Lampotila a, Lampotila b, Asteikko c)
{
    float a_converted = muunna(a, c);
    float b_converted = muunna(b, c);
    
    return a_converted - b_converted;
}