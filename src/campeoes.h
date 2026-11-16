// Definição do tipo de Campeão
#ifndef CAMPEOES_H
#define CAMPEOES_H

typedef enum { MAGO, ATIRADOR_DE_DANO_FISICO, TANQUE, SIPER_MAGO_DO_MAL } ClasseCampeao;

typedef struct {
    char nome[20];
    ClasseCampeao classe;
    char habilidadeEspecial[40];
    int vida, vida_base;
    int tem_anjo_guardiao;
    int danoDeAtaque, poderDeHabilidade, danoHabilidadeEspecial, armadura, resistenciaMagica;
} Campeao;


Campeao criar_ryze() {
    Campeao campeao_escolhido;

    strcpy(campeao_escolhido.nome, "Ryze");
    campeao_escolhido.classe = MAGO;
    strcpy(campeao_escolhido.habilidadeEspecial, "Fluxo de Feitiço");
    campeao_escolhido.vida = 620;
    campeao_escolhido.vida_base = campeao_escolhido.vida;
    campeao_escolhido.tem_anjo_guardiao = 0;
    campeao_escolhido.danoDeAtaque = 55;
    campeao_escolhido.poderDeHabilidade = 110;
    campeao_escolhido.danoHabilidadeEspecial = 30;
    campeao_escolhido.armadura = 22;
    campeao_escolhido.resistenciaMagica = 32;

    return campeao_escolhido;
}


Campeao criar_kaisa() {
    Campeao campeao_escolhido;

    strcpy(campeao_escolhido.nome, "Kai'sa");
    campeao_escolhido.classe = ATIRADOR_DE_DANO_FISICO;
    strcpy(campeao_escolhido.habilidadeEspecial, "Exploradora do Vazio");
    campeao_escolhido.vida = 640;
    campeao_escolhido.vida_base = campeao_escolhido.vida;
    campeao_escolhido.tem_anjo_guardiao = 0;
    campeao_escolhido.danoDeAtaque = 59;
    campeao_escolhido.poderDeHabilidade = 100;
    campeao_escolhido.danoHabilidadeEspecial = 15;
    campeao_escolhido.armadura = 25;
    campeao_escolhido.resistenciaMagica = 33;

    return campeao_escolhido;
}


Campeao criar_volibear() {
    Campeao campeao_escolhido;

    strcpy(campeao_escolhido.nome, "Volibear");
    campeao_escolhido.classe = TANQUE;
    strcpy(campeao_escolhido.habilidadeEspecial, "Emissário da Tempestadade");
    campeao_escolhido.vida = 650;
    campeao_escolhido.vida_base = campeao_escolhido.vida;
    campeao_escolhido.tem_anjo_guardiao = 0;
    campeao_escolhido.danoDeAtaque = 65;
    campeao_escolhido.poderDeHabilidade = 90;
    campeao_escolhido.danoHabilidadeEspecial = 20;
    campeao_escolhido.armadura = 35;
    campeao_escolhido.resistenciaMagica = 32;

    return campeao_escolhido;
}

#endif