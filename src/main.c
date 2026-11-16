// Script principal

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "casas.h"
#include "campeoes.h"
#include "monstros.h"
#include "chefoes.h"

// Função para definir aleatoriamente o tipo de cada casa do tabuleiro.
// Cada 'run' terá uma configuração diferente, mas a última casa da região sempre será destinada ao Chefão da mesma.
int definir_tabuleiro(Casa tabuleiro[3][10]) {
    for (int i = 0; i < 3; i++) {
        TipoCasa baralho[9] = {CURA, ARMADILHA, ARMADILHA, VAZIA, TESOURO, COMBATE, COMBATE, COMBATE, COMBATE};

        // Embaralha
        for (int j = 0; j < 9; j++) {
            int r = rand() % 9;
            TipoCasa temp = baralho[j];
            baralho[j] = baralho[r];
            baralho[r] = temp;
        }

        for (int j = 0; j < 10; j++) {
            if (j == 9) {
                tabuleiro[i][j].tipo = CHEFAO;
                tabuleiro[i][j].qtd_monstros = 1;
    
                tabuleiro[i][j].monstros = malloc(1 * sizeof(Monstro));

                if (i == 0) {
                    tabuleiro[i][j].monstros[0] = criar_leblanc(0);
                } else if (i == 1) {
                    tabuleiro[i][j].monstros[0] = criar_mordekaiser();
                } else if (i == 2) {
                    tabuleiro[i][j].monstros[0] = criar_veigar();
                }
            } else {
                tabuleiro[i][j].tipo = baralho[j];

                // Casa de Cura
                if (tabuleiro[i][j].tipo == CURA) {
                    tabuleiro[i][j].cura = malloc(sizeof(Cura));
                    tabuleiro[i][j].cura->pontos_de_vida = 50;
                }

                // Casa de Armadilha
                if (tabuleiro[i][j].tipo == ARMADILHA) {
                    tabuleiro[i][j].armadilha = malloc(sizeof(Armadilha));
                    tabuleiro[i][j].armadilha->dano = 20;
                }

                if (tabuleiro[i][j].tipo == TESOURO) {
                    tabuleiro[i][j].tesouros = malloc(3 * sizeof(Tesouro));

                    // Item de Dano Físico
                    strcpy(tabuleiro[i][j].tesouros[0].nome, "Espada G.p.C.");
                    tabuleiro[i][j].tesouros[0].bonus_dano = 20;
                    tabuleiro[i][j].tesouros[0].bonus_ap = 0;
                    tabuleiro[i][j].tesouros[0].bonus_armadura = 0;
                    tabuleiro[i][j].tesouros[0].bonus_mr = 0;

                    // Item de Poder de Habilidade
                    strcpy(tabuleiro[i][j].tesouros[1].nome, "Bastão Desnecessariamente Grande");
                    tabuleiro[i][j].tesouros[1].bonus_dano = 0;
                    tabuleiro[i][j].tesouros[1].bonus_ap = 25;
                    tabuleiro[i][j].tesouros[1].bonus_armadura = 0;
                    tabuleiro[i][j].tesouros[1].bonus_mr = 0;

                    // Item de Resistência
                    strcpy(tabuleiro[i][j].tesouros[2].nome, "Passos de Mercúrio");
                    tabuleiro[i][j].tesouros[2].bonus_dano = 0;
                    tabuleiro[i][j].tesouros[2].bonus_ap = 0;
                    tabuleiro[i][j].tesouros[2].bonus_armadura = 12;
                    tabuleiro[i][j].tesouros[2].bonus_mr = 12;
                }

                // Casa de Combate
                if (tabuleiro[i][j].tipo == COMBATE) {
                    if (i == 0) {
                        // Região 1: Icathia (Espiã da Rosa Negra)
                        tabuleiro[i][j].qtd_monstros = 1;
                        tabuleiro[i][j].monstros = malloc(1 * sizeof(Monstro));
                        tabuleiro[i][j].monstros[0] = criar_espia_rosa_negra();
                    } 
                    else if (i == 1) {
                        // Região 2: Reino da Morte (Espectros Agrilhoados)
                        tabuleiro[i][j].qtd_monstros = 3;
                        tabuleiro[i][j].monstros = malloc(3 * sizeof(Monstro));
                        for (int k = 0; k < 3; k++) {
                            tabuleiro[i][j].monstros[k] = criar_espectro_agrilhoado();
                        }
                    } 
                    else if (i == 2) {
                        // Região 3: Confins de Bandópolis (Tenor do Terror)
                        tabuleiro[i][j].qtd_monstros = 1;
                        tabuleiro[i][j].monstros = malloc(1 * sizeof(Monstro));
                        tabuleiro[i][j].monstros[0] = criar_tenor_do_terror();
                    }
                }
            }
        }

    }
    return 0;
}

void exibir_narrativa(int regiao_atual, int fase_atual) {
    int teve_narrativa = 0;

    if (regiao_atual == 0 && fase_atual == 0) {
        // Início de Icathia
        printf("\n[NARRATIVA] Você adentra as terras corrompidas de Icathia...\n");
        printf("\nRyze estava certo sobre o seu pressentimento. Você vê algumas servas da LeBlanc ao longe. Elas parecem estar procurando algo entre escombros do Vazio\n");
        teve_narrativa = 1;
    } 
    else if (regiao_atual == 0 && fase_atual == 9) {
        // Chefão de Icathia
        printf("\n[NARRATIVA] Uma ilusão distorce o ar à sua frente. LeBlanc aguarda.\n");
        teve_narrativa = 1;
    } 
    else if (regiao_atual == 1 && fase_atual == 0) {
        // Início do Reino da Morte
        printf("\n[NARRATIVA] As névoas cinzentas do Reino da Morte cercam você...\n");
        printf("\nLeBlanc é derrotada, mas desaparece. Você ouve apenas uma risada maléfica e percebem que ela deixou cair algo.\n");
        printf("\nAs suas suspeitas se confirmam: era uma chave de portal para o reino de Mordekaiser\n");
        teve_narrativa = 1;
    } 
    else if (regiao_atual == 1 && fase_atual == 9) {
        // Chefão do Reino da Morte
        printf("\n[NARRATIVA] Depois de tanto tempo no reino de Mordekaiser, você parece encontrar uma saída, mas o se aproximar... \n");
        printf("\nO metal range nas sombras. Mordekaiser ergue sua maça.\n");
        teve_narrativa = 1;
    } 
    else if (regiao_atual == 2 && fase_atual == 0) {
        // Início dos Confins de Bandópolis
        printf("\n[NARRATIVA] Quando Mordekaiser está prestes a ser derrotado, ele é atingindo por uma enorme onda de energia.\n");
        printf("\nVeigar surge e leva todos para um lugar inicialmente misterioso. Parece que você está em Bandópolis...\n");
        printf("\nA magia caótica pulsa nos Confins de Bandópolis...\n");
        teve_narrativa = 1;
    } 
    else if (regiao_atual == 2 && fase_atual == 9) {
        // Chefão Final
        printf("\n[NARRATIVA] Uma risada aguda ecoa. Veigar conta o seu plano, finalmente.\n");
        printf("\nDepois de anos sendo escravizado por Mordekaiser, Veigar finalmente será o ser mais poderoso e meléfico do mundo! MUAHAHAHHAHA!\n");
        printf("\nEle descobriu um jeito de adentrar os domínios de Urf e sequestrá-lo. Para isso, teve a ajuda de LeBlanc. O Mordekaiser e sua dimensão mortal eram só uma distração.\n");
        printf("\nDepois de corromper a Espátula Dourada com energia do Vazio, ela finalmente está pronta para ser usada por Veigar!\n");
        teve_narrativa = 1;
    }

    if (teve_narrativa == 1) {
        printf("\nPressione ENTER para continuar...");
        getchar();
    }
}


void exibir_detalhes_campeao(Campeao *campeao) {
    char *nomes_classes[] = {"Mago", "Atirador de Dano Físico", "Tanque"}; // Para exibir o nome da classe ao invés do enum

    printf("[%s]\n", campeao->nome);
    printf("+=======================================================+\n");
    printf("|                                                       |\n");
    printf(" - CLASSE: %-43s \n", nomes_classes[campeao->classe]);
    printf(" - VIDA ATUAL: %-39d \n", campeao->vida);
    printf(" - DANO DE ATAQUE: %-35d \n", campeao->danoDeAtaque);
    printf(" - PODER DE HABILIDADE: %-30d \n", campeao->poderDeHabilidade);
    printf(" - HABILIDADE ESPECIAL: %-30s \n", campeao->habilidadeEspecial);
    printf(" - DANO DE HABILIDADE ESPECIAL: %-22d \n", campeao->danoHabilidadeEspecial);
    printf(" - ARMADURA: %-36d \n", campeao->armadura);
    printf(" - RESISTÊNCIA MÁGICA: %-26d \n", campeao->resistenciaMagica);
    printf("|                                                       |\n");
    printf("+=======================================================+\n");

}

// Função para escolher o campeão
Campeao escolher_campeao(void) {
    int opc, sucesso;
    char confirmacao;
    Campeao campeao_selecionado;

    do {
        do {
            system("clear || cls");
            printf("[ESCOLHA UM CAMPEÃO]\n\n");
            printf("[1] - Ryze    |    [2] - Kai'sa    |    [3] - Volibear    |    [4] - Sair do Jogo\n\n");
            printf("Insira o número correspondente ao Campeão escolhido: ");
            sucesso = scanf("%d", &opc);
            
        if (sucesso == 0) { // Verifica se foi digitado um número realmente
            printf("Opção inválida! Por favor, insira apenas números.\n");
            while (getchar() != '\n');
            opc = 0;
        } else {
            if (opc < 1 || opc > 4) { // Verifica se a opção escolhida está dentro do intervalo
                printf("Opção inválida! Por favor, escolha uma opção válida.\n");
            }
        }
        } while (opc < 1 || opc >4);

        // Exibição das informações do campeão
        switch (opc) {
            case 1:
                campeao_selecionado = criar_ryze();
                break;
            case 2:
                campeao_selecionado = criar_kaisa();
                break;
            case 3:
                campeao_selecionado = criar_volibear();
                break;
            case 4:
                campeao_selecionado.vida = -999;
                return campeao_selecionado;

        }

        printf("Campeão selecionado\n");
        exibir_detalhes_campeao(&campeao_selecionado);

        // Confirmação de campeão
        printf("Realmente deseja escolher este campeão? [S/N]: ");
        scanf(" %c", &confirmacao); // Ignora Enter's ou espaços em branco
        while (getchar() != '\n');

    } while (confirmacao != 'S' && confirmacao != 's');
    

    return campeao_selecionado;
}


// Função para exibir o status atual da jogatina
void exibir_status(int regiao_atual, int fase_atual, char *nome_regiao, Campeao *campeao) {
    char *nomes_classes[] = {"Mago", "Atirador de Dano Físico", "Tanque"}; // Para exibir o nome da classe ao invés do enum

    printf("Região %d (%s): Fase %d\n", regiao_atual+1, nome_regiao, fase_atual+1);
    printf("[%s]\n", campeao->nome);
    printf("+=======================================================+\n");
    printf("|                                                       |\n");
    printf(" - CLASSE: %-42s \n", nomes_classes[campeao->classe]);
    printf(" - VIDA ATUAL: %-39d \n", campeao->vida);
    printf(" - DANO DE ATAQUE: %-35d \n", campeao->danoDeAtaque);
    printf(" - PODER DE HABILIDADE: %-30d \n", campeao->poderDeHabilidade);
    printf(" - HABILIDADE ESPECIAL: %-30s \n", campeao->habilidadeEspecial);
    printf(" - DANO DE HABILIDADE ESPECIAL: %-22d \n", campeao->danoHabilidadeEspecial);
    printf(" - ARMADURA: %-36d \n", campeao->armadura);
    printf(" - RESISTÊNCIA MÁGICA: %-26d \n", campeao->resistenciaMagica);
    printf("|                                                       |\n");
    printf("+=======================================================+\n");

}

// Função para se movimentar pelo tabuleiro
void mover_campeao(int *regiao_atual, int *fase_atual) {
    int d6 = rand() % 6 + 1;

    printf("\nPressione ENTER para avançar...");
    getchar();

    *fase_atual += d6;

    if (*fase_atual > 9) {
        *fase_atual = 9;
    }

    printf("D6 foi rolado! O resultado foi %d. Fase atual: %d.%d\n", d6, *regiao_atual + 1, *fase_atual + 1);

    printf("\nPressione ENTER para avançar...");
    getchar();


}

// Escolher itens
void escolher_item(Tesouro *itens, Campeao *campeao, char *titulo) {
    int opc, sucesso;
    char confirmacao;

    do {
        do {
            printf("\n[%s]\n\n", titulo);
            printf("[1] - %s\n", itens[0].nome);
            printf("[2] - %s\n", itens[1].nome);
            printf("[3] - %s\n", itens[2].nome);
            printf("[4] - Ignorar itens\n\n");
            printf("Escolha uma opção: ");
            sucesso = scanf("%d", &opc);

            if (sucesso == 0) {
                printf("Opção inválida! Por favor, insira apenas números.\n");
                while (getchar() != '\n');
                opc = 0;
            } else if (opc < 1 || opc > 4) {
                printf("Opção inválida! Por favor, escolha uma opção válida.\n");
            }
        } while (opc < 1 || opc > 4);

        while (getchar() != '\n');

        if (opc == 4) {
            printf("Você não escolheu nenhum item.\n");
            return;
        }

        // Mostra os detalhes do item escolhido (índice opc - 1)
        Tesouro item_escolhido = itens[opc - 1];
        printf("\nItem selecionado: [%s]\n", item_escolhido.nome);
        if (item_escolhido.bonus_dano > 0) printf("> Buff de Dano de Ataque: +%d\n", item_escolhido.bonus_dano);
        if (item_escolhido.bonus_ap > 0) printf("> Buff de Poder de Habilidade: +%d\n", item_escolhido.bonus_ap);
        if (item_escolhido.bonus_armadura > 0) printf("> Buff de Armadura: +%d\n", item_escolhido.bonus_armadura);
        if (item_escolhido.bonus_mr > 0) printf("> Buff de Resistência Mágica: +%d\n", item_escolhido.bonus_mr);

        printf("\nRealmente deseja pegar este item? [S/N]: ");
        scanf(" %c", &confirmacao);
        while (getchar() != '\n');

    } while (confirmacao != 'S' && confirmacao != 's');

    // Aplica os buffs ao campeão
    Tesouro final = itens[opc - 1];
    campeao->danoDeAtaque += final.bonus_dano;
    campeao->poderDeHabilidade += final.bonus_ap;
    campeao->armadura += final.bonus_armadura;
    campeao->resistenciaMagica += final.bonus_mr;

    printf("\nVocê equipou %s! Seus atributos foram atualizados.\n", final.nome);
}

// Combate
int contar_monstros_vivos(Casa *casa_atual) {
    int vivos = 0;
    for (int i = 0; i < casa_atual->qtd_monstros; i++) {
        if (casa_atual->monstros[i].vida > 0) {
            vivos++;
        }
    }
    return vivos;
}

int escolher_alvo(Casa *casa_atual) { // Para os casos de combates com mais de um inimigo
    if (casa_atual->qtd_monstros == 1) {
        return 0;
    }

    int alvo, sucesso;
    do {
        printf("\n[ESCOLHA O ALVO]\n");
        for (int i = 0; i < casa_atual->qtd_monstros; i++) {
            if (casa_atual->monstros[i].vida > 0) {
                printf("[%d] - %s (Vida: %d)\n", i + 1, casa_atual->monstros[i].nome, casa_atual->monstros[i].vida);
            } else {
                printf("[%d] - %s [ELIMINADO]\n", i + 1, casa_atual->monstros[i].nome);
            }
        }
        printf("Escolha o número do inimigo: ");
        sucesso = scanf("%d", &alvo);

        if (sucesso == 0) {
            while (getchar() != '\n');
            alvo = 0;
        } else if (alvo < 1 || alvo > casa_atual->qtd_monstros || casa_atual->monstros[alvo - 1].vida <= 0) {
            printf("Alvo inválido ou já eliminado! Escolha outro.\n");
            alvo = 0;
        }
    } while (alvo == 0);

    while (getchar() != '\n');
    return alvo - 1;
}

// Para a ação do inimigo. Ela pode ser, em ordem decrescente de chance: Habilidade Especial, Ataque Básico, Defender e Fugir
void executar_turno_monstro(Monstro *monstro, Campeao *campeao, int jogador_defendendo, int *monstro_defendendo, int *monstro_fugiu, int *leblanc_usos, int *morde_usou_ult, int *morde_dano_continuo) {
    int sorteio = rand() % 100 + 1;
    int d20 = rand() % 20 + 1;

    // Habilidade Especial
    if (sorteio <= 40) {
        printf(" -> %s usou [%s]!\n", monstro->nome, monstro->habilidadeEspecial);

        if (strcmp(monstro->nome, "Espiã da Rosa Negra") == 0) {
            printf("    A habilidade não tem efeito imediato, mas fortalece a Rosa Negra nas sombras...\n");
        } 
        else if (strcmp(monstro->nome, "Espectro Agrilhoado") == 0) {
            int dano = 100;
            if (jogador_defendendo) dano /= 2;
            monstro->vida -= 100;
            campeao->vida -= dano;
            printf("    O espectro sacrificou 100 de vida e causou %d de dano em você!\n", dano);
            if (monstro->vida <= 0) {
                monstro->vida = 0;
                printf("    %s sucumbiu ao próprio sacrifício!\n", monstro->nome);
            }
        } 
        else if (strcmp(monstro->nome, "Tenor do Terror") == 0) {
            int dano = ((d20 + monstro->poderDeHabilidade) * 2) - campeao->resistenciaMagica;
            if (dano < 1) dano = 1;
            if (jogador_defendendo) dano /= 2;
            campeao->vida -= dano;
            printf("    Rolou %d no D20 e causou %d de dano mágico em você!\n", d20, dano);
        }
        // Para os Chefões
        else if (strcmp(monstro->nome, "LeBlanc, A Farsante") == 0) {
            float multiplicador = 1.0 + (0.25 * (*leblanc_usos));
            int dano = (((d20 + monstro->poderDeHabilidade) * multiplicador) - campeao->resistenciaMagica);
            if (dano < 1) dano = 1;
            if (jogador_defendendo) dano /= 2;
            campeao->vida -= dano;
            printf("    Distorção implacável! Causou %d de dano mágico (Multiplicador: %.2fx)!\n", dano, multiplicador);
            (*leblanc_usos)++;
        }
        else if (strcmp(monstro->nome, "Mordekaiser, O Ravenã de Ferro") == 0) {
            if (*morde_usou_ult == 0) {
                monstro->vida += campeao->vida * 0.10;
                monstro->danoDeAtaque += campeao->danoDeAtaque * 0.10;
                monstro->poderDeHabilidade += campeao->poderDeHabilidade * 0.10;
                monstro->armadura += campeao->armadura * 0.10;
                monstro->resistenciaMagica += campeao->resistenciaMagica * 0.10;
                
                *morde_dano_continuo = 15;
                *morde_usou_ult = 1;
                printf("    Mordekaiser absorveu 10%% dos seus atributos e ativou uma aura de %d de dano contínuo!\n", *morde_dano_continuo);
            } else {
                printf("    Mordekaiser já está no Reino da Morte! Ele desfere um ataque básico avassalador em vez disso!\n");
                int dano = (d20 + monstro->danoDeAtaque) - campeao->armadura;
                if (dano < 1) dano = 1;
                if (jogador_defendendo) dano /= 2;
                campeao->vida -= dano;
                printf("    Causou %d de dano físico!\n", dano);
            }
        }
        else if (strcmp(monstro->nome, "Veigar, O Pequeno Mestre do Mal") == 0) {
            int dano = ((d20 + monstro->poderDeHabilidade) * 3) - campeao->resistenciaMagica;
            if (dano < 1) dano = 1;
            if (jogador_defendendo) dano /= 2;
            campeao->vida -= dano;
            printf("    Rolou %d no D20 e o dano foi TRIPLICADO! Causou %d de dano mágico em você!\n", d20, dano);
        }
    }

    // Ataque Básico
    else if (sorteio <= 70) { 
        int dano = (d20 + monstro->danoDeAtaque) - campeao->armadura;
        if (dano < 1) dano = 1;
        if (jogador_defendendo) dano /= 2;
        campeao->vida -= dano;
        printf(" -> %s atacou (D20: %d) e causou %d de dano físico!\n", monstro->nome, d20, dano);
    } 
    else if (sorteio <= 90) { // DEFENDER (20%)
        *monstro_defendendo = 1;
        printf(" -> %s assumiu postura defensiva e receberá metade do dano no próximo turno!\n", monstro->nome);
    } 
    
    // Fugir
    else {
        printf(" -> %s tentou fugir (D20: %d, necessário 16+)...\n", monstro->nome, d20);
        if (d20 >= 16) {
            printf("    %s conseguiu escapar da batalha!\n", monstro->nome);
            monstro->vida = 0;
            *monstro_fugiu = 1;
        } else {
            printf("    A fuga falhou!\n");
        }
    }
}


void iniciar_combate(Casa *casa_atual, Campeao *campeao, int *espias_derrotadas, int *inimigos_derrotados) {
    int opc, sucesso, fugiu = 0;
    int turnos_buff_voli = 0;
    int monstro_defendendo[3] = {0}; // Controle de quais monstros estão defendendo
    int algum_monstro_fugiu = 0;
    int leblanc_usos = 0;
    int morde_usou_ult = 0;
    int morde_dano_continuo = 0;

    printf("\n[COMBATE INICIADO!]\n");
    for (int i = 0; i < casa_atual->qtd_monstros; i++) {
        printf(" -> %s apareceu! (Vida: %d)\n", casa_atual->monstros[i].nome, casa_atual->monstros[i].vida);
    }

    while (campeao->vida > 0 && contar_monstros_vivos(casa_atual) > 0 && !fugiu) {
        system("clear || cls");

        int defendendo = 0;

        // Exibindo status do inimigo
        printf("\n[INIMIGOS EM COMBATE]\n");
        for (int i = 0; i < casa_atual->qtd_monstros; i++) {
            if (casa_atual->monstros[i].vida > 0) {
                printf(" -> %s | Vida: %d\n", casa_atual->monstros[i].nome, casa_atual->monstros[i].vida);
            } else {
                printf(" -> %s | [ELIMINADO]\n", casa_atual->monstros[i].nome);
            }
        }

        if (turnos_buff_voli > 0) {
            turnos_buff_voli--;
            if (turnos_buff_voli == 0) {
                campeao->armadura -= 20;
                campeao->resistenciaMagica -= 20;
                printf("\n[O efeito de Emissário da Tempestade acabou! Armadura e Resistência Mágica voltaram ao normal.]\n");
            }
        }

        // Ação do Campeão
        do {
            printf("\n--- SEU TURNO (Vida: %d) ---\n", campeao->vida);
            printf("[1] - Atacar | [2] - Defender | [3] - Habilidade Especial (%s) | [4] - Fugir\n", campeao->habilidadeEspecial);
            printf("Escolha sua ação: ");
            sucesso = scanf("%d", &opc);

            if (sucesso == 0) {
                while (getchar() != '\n');
                opc = 0;
            } else if (opc < 1 || opc > 4) {
                printf("Opção inválida!\n");
            }
        } while (opc < 1 || opc > 4);
        while (getchar() != '\n');

        int d20 = rand() % 20 + 1;

        // Ataque Básico
        if (opc == 1) {
            int alvo = escolher_alvo(casa_atual);
            int dano = (d20 + campeao->danoDeAtaque) - casa_atual->monstros[alvo].armadura;
            if (dano < 1) dano = 1;
            if (monstro_defendendo[alvo]) dano /= 2; // Reduz dano se o alvo defendeu

            casa_atual->monstros[alvo].vida -= dano;
            printf("\nVocê rolou %d no D20 e causou %d de dano físico em %s!\n", d20, dano, casa_atual->monstros[alvo].nome);
            if (casa_atual->monstros[alvo].vida <= 0) {
                casa_atual->monstros[alvo].vida = 0;
                printf("%s foi eliminado!\n", casa_atual->monstros[alvo].nome);
            }
        } 

        // Defender
        else if (opc == 2) {
            defendendo = 1;
            printf("\nVocê assumiu postura defensiva e receberá metade do dano neste turno!\n");
        } 

        // Habilidade Especial
        else if (opc == 3) {
            printf("\nVocê usou [%s] e rolou %d no D20!\n", campeao->habilidadeEspecial, d20);

            if (campeao->classe == MAGO) { // Ryze [Dano em área]
                for (int i = 0; i < casa_atual->qtd_monstros; i++) {
                    if (casa_atual->monstros[i].vida > 0) {
                        int dano = (d20 + campeao->danoHabilidadeEspecial + campeao->poderDeHabilidade) - casa_atual->monstros[i].resistenciaMagica;
                        if (dano < 1) dano = 1;
                        if (monstro_defendendo[i]) dano /= 2;

                        casa_atual->monstros[i].vida -= dano;
                        printf(" -> %s sofreu %d de dano mágico!\n", casa_atual->monstros[i].nome, dano);
                        if (casa_atual->monstros[i].vida <= 0) {
                            casa_atual->monstros[i].vida = 0;
                            printf(" -> %s foi eliminado!\n", casa_atual->monstros[i].nome);
                        }
                    }
                }
            } 
            else if (campeao->classe == ATIRADOR_DE_DANO_FISICO) { // Kai'sa [Dano a alvo específico]
                int alvo = escolher_alvo(casa_atual);
                int dano = (d20 + campeao->danoHabilidadeEspecial + campeao->poderDeHabilidade) - casa_atual->monstros[alvo].resistenciaMagica;
                if (dano < 1) dano = 1;
                if (monstro_defendendo[alvo]) dano /= 2;

                casa_atual->monstros[alvo].vida -= dano;
                printf(" -> %s sofreu %d de dano mágico!\n", casa_atual->monstros[alvo].nome, dano);
                if (casa_atual->monstros[alvo].vida <= 0) {
                    casa_atual->monstros[alvo].vida = 0;
                    printf(" -> %s foi eliminado!\n", casa_atual->monstros[alvo].nome);
                }
            } 
            else if (campeao->classe == TANQUE) { // Volibear [Leve dano em área e aumento das resistências]
                for (int i = 0; i < casa_atual->qtd_monstros; i++) {
                    if (casa_atual->monstros[i].vida > 0) {
                        int dano = (d20 + (campeao->poderDeHabilidade / 2)) - casa_atual->monstros[i].resistenciaMagica;
                        if (dano < 1) dano = 1;
                        if (monstro_defendendo[i]) dano /= 2;

                        casa_atual->monstros[i].vida -= dano;
                        printf(" -> %s sofreu %d de dano elétrico!\n", casa_atual->monstros[i].nome, dano);
                        if (casa_atual->monstros[i].vida <= 0) {
                            casa_atual->monstros[i].vida = 0;
                            printf(" -> %s foi eliminado!\n", casa_atual->monstros[i].nome);
                        }
                    }
                }
                if (turnos_buff_voli == 0) {
                    campeao->vida += 50;
                    campeao->armadura += 20;
                    campeao->resistenciaMagica += 20;
                    printf(" -> Volibear ganhou +50 de Vida, +20 de Armadura e +20 de Resistência Mágica por 2 turnos!\n");
                }
                turnos_buff_voli = 2;
            }
        } 

        // Fugir
        else if (opc == 4) {
            printf("\nVocê tentou fugir e rolou %d no D20 (necessário 16+)...\n", d20);
            if (d20 >= 16) {
                printf("Fuga bem-sucedida! Você escapou do combate.\n");
                fugiu = 1;
                break;
            } else {
                printf("Falha na fuga! Os inimigos bloquearam seu caminho.\n");
            }
        }

        // Ação do Monstro
        if (contar_monstros_vivos(casa_atual) > 0 && !fugiu) {
            // Zera a postura defensiva do turno anterior antes de sortearem novas ações
            for (int i = 0; i < 3; i++) {
                monstro_defendendo[i] = 0;
            }

            printf("\n--- TURNO DOS INIMIGOS ---\n");
            for (int i = 0; i < casa_atual->qtd_monstros; i++) {
                if (casa_atual->monstros[i].vida > 0) {
                    executar_turno_monstro(&casa_atual->monstros[i], campeao, defendendo, &monstro_defendendo[i], &algum_monstro_fugiu, &leblanc_usos, &morde_usou_ult, &morde_dano_continuo);
                    
                    if (campeao->vida <= 0) {
                        if (campeao->tem_anjo_guardiao == 1) {
                            campeao->vida = campeao->vida_base; // Restaura a vida para o valor base
                            campeao->tem_anjo_guardiao = 0;     // Remove o item para não usar de novo
                            
                            printf("\n=================================================================\n");
                            printf(" [MILAGRE!] A luz do Anjo Guardião envolve o seu corpo!\n");
                            printf(" Você foi revivido e seus pontos de vida foram restaurados!\n");
                            printf("=================================================================\n");
                        } else {
                            campeao->vida = 0; // Confirma a morte
                            break;             // Sai do laço de combate
                        }
                    }
                    }
                }
            }

            if (morde_dano_continuo > 0) {
                campeao->vida -= morde_dano_continuo;
                printf("Você sofreu %d de dano contínuo do Reino da Morte!\n", morde_dano_continuo);
            }

            if (campeao->vida > 0 && contar_monstros_vivos(casa_atual) > 0 && !fugiu) {
            printf("\nPressione ENTER para ir para o próximo turno...");
            getchar(); 
        }
        }
    

    if (turnos_buff_voli > 0) {
        campeao->armadura -= 20;
        campeao->resistenciaMagica -= 20;
    }

    // --- FIM DO COMBATE ---
    if (campeao->vida > 0 && !fugiu) {
        printf("\n[VITÓRIA!] Todos os inimigos foram derrotados!\n");
        (*inimigos_derrotados)++;

        printf("Recompensa: +5 em todos os atributos e +20 de Vida!\n");
        campeao->vida += 20;
        campeao->danoDeAtaque += 5;
        campeao->poderDeHabilidade += 5;
        campeao->armadura += 5;
        campeao->resistenciaMagica += 5;
        casa_atual->visitada = 1;
        

        // Contagem de Espiãs da Rosa Negra derrotadas e que não fugiram
        if (strcmp(casa_atual->monstros[0].nome, "Espiã da Rosa Negra") == 0 && !algum_monstro_fugiu) {
            (*espias_derrotadas)++;
            printf(" -> Espiãs da Rosa Negra derrotadas até agora: %d\n", *espias_derrotadas);
        }

        // Verficação de chefão final
        if (strcmp(casa_atual->monstros[0].nome, "Veigar, O Pequeno Mestre do Mal") == 0) {
            printf(" PARABÉNS! VOCÊ DERROTOU O VEIGAR E SALVOU O URF! \n");
            printf(" A paz e a ordem voltaram a reinar em Runeterra! \n");
            exit(0); 
        }
    }
}


void configurar_casa(Casa *casa_atual, Campeao *campeao, int *regiao_atual, int *fase_atual, int *espias_derrotadas, int *inimigos_derrotados) {
    switch (casa_atual->tipo) {
        case VAZIA:
            printf("As coisas parecem estar muito tranquilas ao seu redor...\n");
            break;
        
        case COMBATE:
        if (casa_atual->visitada == 0) {
            iniciar_combate(casa_atual, campeao, espias_derrotadas, inimigos_derrotados);
        } else {
            printf("Os inimigos desta área já foram derrotados.\n");
        }
        break;
        
        case TESOURO:
            if (casa_atual->visitada == 0) {
                escolher_item(casa_atual->tesouros, campeao, "BAÚ DE TESOURO ENCONTRADO");
                casa_atual->visitada = 1;
            } else {
                printf("Você encontra um baú mas ele já foi aberto.\n");
            }
            break;

        case CURA:
            if (casa_atual->visitada == 0) {
                printf("Você encontrou uma Poção de Vida! Sua vida foi restaurada em %d pontos.\n", casa_atual->cura->pontos_de_vida);
                campeao->vida += casa_atual->cura->pontos_de_vida;
                
                casa_atual->visitada = 1;
                
            } else {
                printf("Você vê um frasco vazio no chão. A poção já foi consumida.\n");
            }
            break;

        case ARMADILHA:
            if (casa_atual->visitada == 0) {
                printf("Você foi atingido por uma Muda do Maokai! Perdeu %d pontos de vida.\n", casa_atual->armadilha->dano);
                campeao->vida -= casa_atual->armadilha->dano; // Inverso da cura
                
                casa_atual->visitada = 1;
            } else {
                printf("Sem Mudas do Maokai por aqui.\n");
            }
            break;
        
        case CHEFAO:
            if (casa_atual->visitada == 0) {
                printf("AMEAÇA MÁXIMA DETECTADA! VOCÊ ENCONTROU O CHEFÃO!\n");
        
                if (strcmp(casa_atual->monstros[0].nome, "LeBlanc, A Farsante") == 0) { 
                    casa_atual->monstros[0] = criar_leblanc(*espias_derrotadas);
                }
            
                iniciar_combate(casa_atual, campeao, espias_derrotadas, inimigos_derrotados);
                
                casa_atual->visitada = 1; 
                
                // Avança o jogo!
                (*regiao_atual)++; 
                *fase_atual = 0;
            } else {
                printf("O local está silencioso. O chefão já foi derrotado.\n");
            }
            break;
    }
}


int main(void) {
    srand(time(NULL));
    // Declarações iniciais
    Casa tabuleiro[3][10] = {0};
    int regiao_atual = 0, fase_atual = 0;
    char regioes[3][50] = {"Icathia", "Reino da Morte", "Confins de Bandópolis"};
    Campeao campeao;
    int espias_derrotadas = 0;
    int inimigos_derrotados = 0;

    definir_tabuleiro(tabuleiro); // Definindo o tabuleiro

    campeao = escolher_campeao(); // Escolha de Campeão

    if (campeao.vida > 0) {
        system("clear || cls");
        
        // Itens iniciais
        Tesouro itens_iniciais[3] = {
            {"Lâmina de Doran", 8, 0, 0, 0},
            {"Anel de Doran", 0, 12, 0, 0},
            {"Escudo de Doran", 0, 0, 5, 5}
        };

        escolher_item(itens_iniciais, &campeao, "ESCOLHA SEU ITEM INICIAL");
        
        printf("\nPressione ENTER para iniciar a jornada...");
        getchar();
    }

    while (campeao.vida > 0 && regiao_atual < 3) {
        // Limpando terminal
        system("clear || cls");

        // Exibição dos status atuais
        exibir_status(regiao_atual, fase_atual, regioes[regiao_atual], &campeao);

        // Definindo o tipo da casa atual
        TipoCasa tipo_atual = tabuleiro[regiao_atual][fase_atual].tipo;

        // Mensagem da narrativa
        exibir_narrativa(regiao_atual, fase_atual);

        // Configurar casa
        configurar_casa(&tabuleiro[regiao_atual][fase_atual], &campeao, &regiao_atual, &fase_atual, &espias_derrotadas, &inimigos_derrotados);// Espiãs derrotadas está aí pela mecânica com a LeBlanc
        if (tipo_atual != CHEFAO && campeao.vida>0) {
            // Movimentar o campeão pelo tabuleiro
            mover_campeao(&regiao_atual, &fase_atual);
        }
    
    }

    if (campeao.vida > 0) {
        printf("\nVeigar foi derrotado! Urf consegue restaurar a ordem com a sua Espátuala Dourada\n");
    } else if (campeao.vida == -999) {
        printf("\nVocê abandonou a partida e saiu do jogo.\n");
    } else {
        printf("\nVocê foi eliminado.\n");
    }



    return 0;
}