#ifndef CHEFOES_H
#define CHEFOES_H

#include <string.h>

Monstro criar_leblanc(int espias_derrotadas) {
    Monstro leblanc;
    strcpy(leblanc.nome, "LeBlanc, A Farsante");
    strcpy(leblanc.habilidadeEspecial, "Distorção");
    leblanc.vida = 620;
    leblanc.danoDeAtaque = 55;
    leblanc.poderDeHabilidade = 110 + (25 * espias_derrotadas); // Bônus pelas espiãs!
    leblanc.armadura = 22;
    leblanc.resistenciaMagica = 32;
    return leblanc;
}

Monstro criar_mordekaiser() {
    Monstro morde;
    strcpy(morde.nome, "Mordekaiser, O Ravenã de Ferro");
    strcpy(morde.habilidadeEspecial, "Reino da Morte");
    morde.vida = 1100;
    morde.danoDeAtaque = 60;
    morde.poderDeHabilidade = 100;
    morde.armadura = 35;
    morde.resistenciaMagica = 30;
    return morde;
}

Monstro criar_veigar() {
    Monstro veigar;
    strcpy(veigar.nome, "Veigar, O Pequeno Mestre do Mal");
    strcpy(veigar.habilidadeEspecial, "Explosão Primordial");
    veigar.vida = 630;
    veigar.danoDeAtaque = 50;
    veigar.poderDeHabilidade = 100;
    veigar.armadura = 40;
    veigar.resistenciaMagica = 40;
    return veigar;
}

#endif