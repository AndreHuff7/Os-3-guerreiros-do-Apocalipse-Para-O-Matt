#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto {
    float x;
    float y;
};

Ponto* ponto_criar(float x, float y) {

    Ponto* p = malloc(sizeof(Ponto));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

float ponto_distancia(const Ponto* p1, const Ponto* p2) {
    if (p1 == NULL || p2 == NULL) return NAN; 
    
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrtf(dx * dx + dy * dy); 
}

void ponto_destruir(Ponto* p) {
    if (p != NULL) {
        free(p);
    }
}