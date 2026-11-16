#ifndef MONSTROS_H
#define MONSTROS_H

#include <string.h>
#include "campeoes.h" // Para reaproveitar o enum de Classes

typedef struct {
    char nome[50];
    ClasseCampeao classe;
    char habilidadeEspecial[50];
    int vida;
    int danoDeAtaque;
    int poderDeHabilidade;
    int armadura;
    int resistenciaMagica;
} Monstro;

// Região 1: Icathia
Monstro criar_espia_rosa_negra(void) {
    Monstro m;
    strcpy(m.nome, "Espiã da Rosa Negra");
    m.classe = MAGO;
    strcpy(m.habilidadeEspecial, "Reputação");
    m.vida = 420;
    m.danoDeAtaque = 35;
    m.poderDeHabilidade = 1000;
    m.armadura = 22;
    m.resistenciaMagica = 32;
    return m;
}

// Região 2: Reino da Morte (aparece em trio!)
Monstro criar_espectro_agrilhoado(void) {
    Monstro m;
    strcpy(m.nome, "Espectro Agrilhoado");
    m.classe = MAGO;
    strcpy(m.habilidadeEspecial, "Último Suspiro");
    m.vida = 400;
    m.danoDeAtaque = 55;
    m.poderDeHabilidade = 100;
    m.armadura = 10;
    m.resistenciaMagica = 5;
    return m;
}

// Região 3: Confins de Bandópolis
Monstro criar_tenor_do_terror(void) {
    Monstro m;
    strcpy(m.nome, "Tenor do Terror");
    m.classe = MAGO;
    strcpy(m.habilidadeEspecial, "Magia Impactante");
    m.vida = 500;
    m.danoDeAtaque = 55;
    m.poderDeHabilidade = 120;
    m.armadura = 20;
    m.resistenciaMagica = 20;
    return m;
}

#endif