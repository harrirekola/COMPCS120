#ifndef PVM_H
#define PVM_H

typedef struct Pvm {
    int pv;
    int kk;
    int vuosi;
    char vk_pv[3];
} Pvm;

Pvm * kasvataPvm(Pvm *pvm);
unsigned int pvmEro(const Pvm *a, const Pvm *b);
void tulostaPvm(Pvm *pvm);

#endif /* PVM_H */