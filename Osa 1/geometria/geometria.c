#include "geometria.h"

const long double PII = 3.1415926535897932385L;

double ympyranAla(double sade) {
    return (double)(PII * (long double)sade * (long double)sade);
}

double pallonTilavuus(double sade) {
    return (double)((4.0L/3.0L) * PII
                    * (long double)sade
                    * (long double)sade
                    * (long double)sade);
}
