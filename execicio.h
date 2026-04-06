#ifndef PONTO_H
#define PONTO_H

typedef struct ponto Ponto;

Ponto* ponto_criar(float x, float y);
float ponto_distancia(const Ponto* p1, const Ponto* p2); 
void ponto_destruir(Ponto* p);

#endif 