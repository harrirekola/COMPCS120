#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Solmu * s_luo(const void * data, size_t dataKoko, Solmu *seur)
{
  Solmu *s = malloc(sizeof(Solmu));
  s->data = malloc(dataKoko);
  memcpy(s->data, data, dataKoko);
  s->seur = seur;
  return s;
}

Lista * ll_luo(size_t dataKoko, void (*tulostaArvo)(FILE *virta, const void *arvo)) {
  Lista *ll = malloc(sizeof(Lista));
  ll->dataKoko = dataKoko;
  ll->n = 0;
  ll->paa = NULL;
  ll->tulostaArvo = tulostaArvo;
  return ll;
}

void ll_tuhoa(Lista *ll)
{
  while(ll->n > 0)
  {
    ll_poistaEdesta(ll);
  }
  free(ll);
}

Solmu * ll_lisaaEteen(Lista *ll, const void *arvo)
{
  ll->paa = s_luo(arvo, ll->dataKoko, ll->paa);
  ll->n += 1;
  return ll->paa;
}

void ll_poistaEdesta(Lista *ll)
{
  if(ll->n > 0)
  {
    Solmu *vanhaPaa = ll->paa;
    ll->paa = ll->paa->seur;
    free(vanhaPaa->data);
    free(vanhaPaa);
    ll->n -= 1;
  }
}

void ll_tulosta(const Lista *lista, FILE *virta)
{
  Solmu *s;
  if(lista->tulostaArvo == NULL) {
    return;
  }
  printf("Lista:");
  for(s = lista->paa; s != NULL; s = s->seur)
  {
    printf(" ");
    lista->tulostaArvo(virta, s->data);
  }
  printf("\n");
}