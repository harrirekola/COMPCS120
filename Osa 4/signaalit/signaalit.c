#include <signal.h>
#include <setjmp.h>
#include "signaalit.h"

jmp_buf paluuTila;

void hoidaSIGFPE(int s) {
    signal(SIGFPE, hoidaSIGFPE);
    longjmp(paluuTila, SIGFPE);
}

void hoidaSIGSEGV(int s) {
    signal(SIGSEGV, hoidaSIGSEGV);
    longjmp(paluuTila, SIGSEGV);
}