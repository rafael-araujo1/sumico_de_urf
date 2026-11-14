// Definição do tipo de casa, utilizando ENUM

#ifndef CASAS_H
#define CASAS_H

typedef enum { VAZIA, COMBATE, TESOURO, CURA, CHEFAO, } TipoCasa;


typedef struct {
    TipoCasa tipo;
    Monstro *monstro;
    Tesouro *tesouro;
    Chefao *chefao;
    Cura *cura;
    int visitada;
} Casa;

#endif