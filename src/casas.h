// Definição do tipo de casa, utilizando ENUM
#include "monstros.h"

#ifndef CASAS_H
#define CASAS_H

typedef enum { VAZIA, COMBATE, TESOURO, CURA, ARMADILHA, CHEFAO } TipoCasa;

typedef struct Chefao Chefao;

typedef struct {
    int pontos_de_vida;
} Cura;

typedef struct {
    int dano;
} Armadilha;

typedef struct {
    char nome[50];
    int bonus_dano;
    int bonus_ap;
    int bonus_armadura;
    int bonus_mr;
} Tesouro;


typedef struct {
    TipoCasa tipo;
    Monstro *monstros; // Há batalhas contra Monstros solos ou em bandos
    int qtd_monstros;    
    Tesouro *tesouros;
    Chefao *chefao;
    Cura *cura;
    Armadilha *armadilha;
    int visitada;
} Casa;

#endif