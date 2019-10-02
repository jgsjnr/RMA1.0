#include <stdio.h>
#include "pp.h"
#include "../includes/tens.h"

float pp_aluno(int num_aluno){
    //variaveis referente as cotas
    float cota[11];
    //variavel especificas
    float num_aluno_pp, t, x;
    //recebendo valor em inteiro e transformando em valorees com pontos flutuantes
    num_aluno_pp = num_aluno;
    //variaveis dos elementos das peças
    double a1,p1,a2,h1,b1,p2;
    double bug_correcor;
    int continuar = 0;
    //variavel de continuação
    //tipo de elemento
    struct elemento{
        double romp;
        double cis;
        double esm;
    };

    //declaração da peça
    struct elemento parte[8];
    printf("Atencao: seguir as tensoes referentes ao aluno. \n");
    printf("Digite o valor em T: ");
    scanf("%f", &t);
    printf("Digite o valor de X: ");
    scanf("%f", &x);
    bug_correcor = ((40/x)+(num_aluno*t));
    a1 = ((40/x)+(num_aluno_pp*t));
    p1 = ((52/x)+(num_aluno_pp*t));
    a2 = ((60/x)+(num_aluno_pp*t));
    h1 = ((60/x)+(num_aluno_pp*t));
    b1 = ((60/x)+(num_aluno_pp*t));
    p2 = ((30/x)+(num_aluno_pp*t));
    printf("ATENCAO, EXISTEM DOIS P1 POREM IREI CHAMAR O SUPERIOR DE P1 E O INFERIOR DE P2\n");
    printf("ATENCAO, TODOS OS PONTOS DEVEM SER TROCADOS POR VIRGULAS\n");
    printf("Tensao peca A1 %.0f\n", a1);
    printf("Tensao peca P1 %.0f\n", p1);
    printf("Tensao peca A2 %.0f\n", a2);
    printf("Tensao peca H1 %.0f\n", h1);
    printf("Tensao peca B2 %.0f\n", b1);
    printf("Tensao peca P2 %.0f\n", p2);
    printf("Tensao peca B1 %.0f\n", bug_correcor);
    printf("Abaixo as cotas da pp de acordo com a ordem: \n");
    cota[0] = 8+(num_aluno_pp/4);
    cota[1] = 12+(num_aluno_pp/4);
    cota[2] = 8+(num_aluno_pp/4);
    cota[3] = 6+(num_aluno_pp/2);
    cota[4] = 15+(num_aluno_pp/3);
    cota[5] = 15+(num_aluno_pp/4);
    cota[6] = 18+(num_aluno_pp/4);
    cota[7] = 12+(num_aluno_pp/3);
    cota[8] = 14+(num_aluno_pp/3);
    cota[9] = 12+(num_aluno_pp/3);
    cota[10] = 10+num_aluno_pp;
    cota[11] = 10+(num_aluno_pp/(2*t));
    printf("Cota 1 referente A 8+(num aluno/4) %.2f\n", cota[0]);
    printf("\n-------------------------------------------------------------------------\n");
    printf("Cota 2 referente A 12+(num aluno/4) %.2f\n", cota[1]);
    printf("\n-------------------------------------------------------------------------\n");
    printf("Cota 3 referente A 8+(num aluno/4) %.2f\n", cota[2]);
    printf("\n-------------------------------------------------------------------------\n");
    printf("Cota 4 referente A 6+(num aluno/2) %.2f\n", cota[3]);
    printf("\n-------------------------------------------------------------------------\n");
    printf("Cota 5 referente A (15/x)+(num aluno/3) %.2f\n", cota[4]);
    printf("\n-------------------------------------------------------------------------\n");
    printf("Cota 6 referente A (15/x)+(num aluno/) %.2f\n", cota[5]);
    printf("\n-------------------------------------------------------------------------\n");
    printf("Cota 7 referente A (18/x)+(num aluno/4) %.2f\n", cota[6]);
    printf("\n-------------------------------------------------------------------------\n");
    printf("Cota 8 referente A 12+(num aluno/3) %.2f\n", cota[7]);
    printf("\n-------------------------------------------------------------------------\n");
    printf("Cota 9 referente A 14+(num aluno/3) %.2f\n", cota[8]);
    printf("\n-------------------------------------------------------------------------\n");
    printf("Cota 10 referente A 12+(num aluno/3) %.2f\n", cota[9]);
    printf("\n-------------------------------------------------------------------------\n");
    printf("Cota 11 referente A 10+(num aluno) %.2f\n", cota[10]);
    printf("\n-------------------------------------------------------------------------\n");
    printf("Cota da haste referente A 10+(num aluno/(2xt)) %.2f\n", cota[11]);
    printf("\n-------------------------------------------------------------------------\n");
    printf("Abaixo os calculos\n");
    printf("\ndigite 00: ");
    if(continuar == 00)
    {
        printf("\n-------------------------------------------------------------------------\n");
        printf("                                    PECA A1");
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca A1 do rompimento: \n");
        parte[0].romp = rompimento(a1,cota[0],cota[6]-(cota[5]/2),4);
        printf("\nA1 - Rompimento : %.2f\n",parte[0].romp);
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca A1 do cisalhamento: \n");
        parte[0].cis = cisalhamento(a1,cota[0], cota[8], 4);
        printf("\nA1 - Cisalhamento : %.2f\n",parte[0].cis);
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca A1 do esmagamento: \n");
        parte[0].esm = esmagamento(a1,cota[0], cota[5],2);
        printf("\nA1 - Esmagamento : %.2f\n",parte[0].esm);
        printf("\n-------------------------------------------------------------------------\n");
        printf("                                     PINO 1");
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca P1 em relacao a peca A1 quando ha cisalhamento: \n");
        parte[1].cis = cisalhamento_pino(p1, cota[5], 4);
        printf("\nP1 em relacao A1 - Cisalhamento : %.2f\n",parte[1].cis);
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca P1 em relacao a peca A2 do cisalhamento: \n");
        parte[1].cis = cisalhamento_pino(p1, cota[5], 2);
        printf("\nP1 em relacao A2 - Cisalhamento : %.2f\n",parte[1].cis);
        printf("\nResolucao peca A1 do escamagmento: \n");
        printf("\n-------------------------------------------------------------------------\n");
        parte[1].esm = esmagamento(p1,cota[5], cota[0],2);
        printf("\nP1 - Esmagamento em relacao A1 : %.2f\n",parte[1].esm);
        printf("\n-------------------------------------------------------------------------\n");
        parte[1].esm = esmagamento(p1,cota[5], cota[1],1);
        printf("\nP1 - Esmagamento em relacao A2 : %.2f\n",parte[1].esm);
        printf("\n-------------------------------------------------------------------------\n");
        printf("                                PECA A2");
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca A2 do rompimento: \n");
        parte[2].romp = rompimento(a2,cota[1],(cota[6]-(cota[5]/2)),2);
        printf("\nA2 - Rompimento : %.2f\n",parte[2].romp);
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca A2 do cisalhamento: \n");
        parte[2].cis = cisalhamento(a2,cota[1], cota[9], 2);
        printf("\nA2 - Cisalhamento : %.2f\n",parte[2].cis);
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca A2 do escamagmento: \n");
        parte[2].esm = esmagamento(a2,cota[1], cota[5],1);
        printf("\nA2 - Esmagamento : %.2f\n",parte[2].esm);
        printf("\n-------------------------------------------------------------------------\n");
        printf("                                 HASTE H1");
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca A2 do rompimento: \n");
        parte[3].romp = rompimento_haste(h1,cota[11]);
        printf("\nA2 - Rompimento : %.2f\n",parte[3].romp);
        printf("\n-------------------------------------------------------------------------\n");
        printf("                              PECA B2");
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca B2 do rompimento: \n");
        parte[4].romp = rompimento(b1,cota[2],(cota[6]-(cota[4]/2)),4);
        printf("\nB2 - Rompimento : %.2f\n",parte[4].romp);
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca B2 do cisalhamento: \n");
        parte[4].cis = cisalhamento(b1,cota[2], cota[10], 4);
        printf("\nB2 - Cisalhamento : %.2f\n",parte[4].cis);
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca B2 do escamagmento: \n");
        parte[4].esm = esmagamento(b1,cota[2], cota[4],2);
        printf("\nB2 - Esmagamento : %.2f\n",parte[4].esm);
        printf("\n-------------------------------------------------------------------------\n");
        printf("                                     PINO 2");
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca P2 em relacao a peca B2 do cisalhamento: \n");
        parte[5].cis = cisalhamento_pino(p2, cota[4], 4);
        printf("\nP1 B2 - Cisalhamento : %.2f\n",parte[5].cis);
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca P2 em relacao a peca B1 do cisalhamento: \n");
        parte[5].cis = cisalhamento_pino(p2, cota[4], 6);
        printf("\nP1 B1 - Cisalhamento : %.2f\n",parte[5].cis);
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca P2 em relacao a B2 do esmagamento: \n");
        parte[5].esm = esmagamento(p2,cota[4], cota[2],2);
        printf("\nP1 - Esmagamento : %.2f\n",parte[5].esm);
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca P2 em relacao a B2 do esmagamento: \n");
        parte[5].esm = esmagamento(p2,cota[4], cota[3],3);
        printf("\nP1 - Esmagamento : %.2f\n",parte[5].esm);
        printf("\n-------------------------------------------------------------------------\n");
        printf("                                PECA B1");
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca B1 do rompimento: \n");
        parte[7].romp = rompimento(bug_correcor,cota[3],(cota[6]-(cota[4]/2)),6);
        printf("\nB2 - Rompimento : %.2f\n",parte[7].romp);
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca B1 do cisalhamento: \n");
        parte[7].cis = cisalhamento(bug_correcor,cota[7], cota[3], 6);
        printf("\nB2 - Cisalhamento : %.2f\n",parte[7].cis);
        printf("\n-------------------------------------------------------------------------\n");
        printf("\nResolucao peca B1 do esmagamento: \n");
        parte[7].esm = esmagamento(bug_correcor,cota[3], cota[4],3);
        printf("\nB2 - Esmagamento : %.2f\n",parte[7].esm);
        printf("\n-------------------------------------------------------------------------\n");

    }
    printf("deseja ir para CG?");
    scanf("%d", &continuar);
    if(continuar == 11 )
    {

    }
    return 0;
}
