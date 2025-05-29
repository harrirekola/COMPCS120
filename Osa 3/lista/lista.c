#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

DblSolmu * ds_luo(double data, DblSolmu *seur)
{
  DblSolmu *ds = malloc(sizeof(DblSolmu));
  ds->data = data;
  ds->seur = seur;
  return ds;
}

DblLista * dl_luo(void)
{
  DblLista *dl = malloc(sizeof(DblLista));
  dl->n = 0;
  dl->paa = NULL;
  return dl;
}

void dl_tuhoa(DblLista *dl)
{
  while(dl->n > 0)
  {
    dl_poistaEdesta(dl);
  }
  free(dl);
}

DblSolmu * dl_lisaaEteen(DblLista *dl, double arvo)
{
  dl->paa = ds_luo(arvo, dl->paa);
  dl->n += 1;
  return dl->paa;
}

double dl_poistaEdesta(DblLista *dl)
{
  double arvo = 0;
  if(dl->n > 0)
  {
    DblSolmu *vanhaPaa = dl->paa;
    arvo = dl->paa->data;
    dl->paa = dl->paa->seur;
    free(vanhaPaa);
    dl->n -= 1;
  }
  return arvo;
}

void dl_tulosta(const DblLista *lista)
{
  DblSolmu *s;
  printf("Lista:");
  for(s = lista->paa; s != NULL; s = s->seur)
  {
    printf(" %.1f", s->data);
  }
  printf("\n");
}

double dl_alkio(const DblLista *lista, size_t i)
{   
    DblSolmu *current = lista->paa;
    size_t count = 0;

    if (lista->paa == NULL || i >= lista->n) {
        return 0;
    }

    while (count < i && current != NULL) {
        current = current->seur;
        count++;
    }
    
    return current->data;
}

DblSolmu * dl_lisaa(DblLista *lista, size_t i, double arvo)
{
    DblSolmu *u = malloc(sizeof(DblSolmu));
    if (u == NULL) {
        return NULL;
    }
    u->data = arvo;

    if (i == 0) {
        u->seur = lista->paa;
        lista->paa = u;
    }
    else {
        DblSolmu *current = lista->paa;
        size_t count = 0;
        
        while (current != NULL && count < i-1) {
            current = current->seur;
            count++;
        }
        
        if (current != NULL) {
            u->seur = current->seur;
            current->seur = u;
        }
        else {
            current = lista->paa;
            if (current != NULL) {
                while (current->seur != NULL) {
                    current = current->seur;
                }
                current->seur = u;
                u->seur = NULL;
            } else {
                lista->paa = u;
                u->seur = NULL;
            }
        }
    }
    
    lista->n++;
    return u;
}

double dl_poista(DblLista *lista, size_t i)
{
    double arvo = 0.0;
    DblSolmu *poistettava;
    
    if (lista->paa == NULL || i >= lista->n) {
        return arvo;
    }
    
    if (i == 0) {
        poistettava = lista->paa;
        arvo = poistettava->data;
        lista->paa = poistettava->seur;
        free(poistettava);
    }
    else {
        DblSolmu *edellinen = lista->paa;
        size_t count = 0;
        
        while (count < i-1 && edellinen != NULL) {
            edellinen = edellinen->seur;
            count++;
        }
        
        if (edellinen != NULL && edellinen->seur != NULL) {
            poistettava = edellinen->seur;
            arvo = poistettava->data;
            edellinen->seur = poistettava->seur;
            free(poistettava);
        }
    }

    lista->n--;
    return arvo;
}