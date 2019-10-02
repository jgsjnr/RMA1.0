#include <stdio.h>
#include <stdlib.h>
#include "includes/tens.h"
#include "aluno/pp.h"

int main()
{
    float romp, cis, esm;
    int i_tipo, i_tipo_r, pp_gaucho;
    int closed = 0;
    float tensao, larg_a, larg_b, faces, elementos;
    while(closed != 99){
        printf("Digite um dos codigos abaixo para realizar um tipo de operacao. \n");
        printf("Para rompimento digite:   1\n");
        printf("Para cisalhamento digite: 2\n");
        printf("Para esmagamento digite:  3\n");
        printf("PP do Gaucho: 4\n");
        printf("Sair: 99\n");
        printf("Codigo: ");
        scanf("%d", &i_tipo);
        switch(i_tipo){
            case 1:
                printf("Voce escolheu rompimento. \n");
                i_tipo_r = 1;
            break;
            case 2:
                printf("Voce escolheu cisalhamento. \n");
                i_tipo_r = 2;
            break;
            case 3:
                printf("Voce escolheu esmagamento. \n");
                i_tipo_r = 3;
            break;
            case 4:
                printf("Vooce escolheu PP do guacho: \n");
                i_tipo_r = 4;
                break;
            case 99:
                printf("Voce escolheu sair\n");
                i_tipo_r = 5;
                break;
            default:
                printf("nenhum valor correspondente foi digitado. \n\n");
                i_tipo_r = 0;
        }
        switch(i_tipo_r){
        case 1:
            printf("Digite a tensao: ");
            scanf("%f", &tensao);
            printf("Area a: ");
            scanf("%f", &larg_a);
            printf("Area b: ");
            scanf("%f", &larg_b);
            printf("Digite a quantidade de faces: ");
            scanf("%f", &faces);
            romp = rompimento(tensao,larg_a,larg_b,faces);
            printf("O valor do rompimento e de AREA X TENSAO: %f\n", romp);
            printf("para sair digite 99: ");
            scanf("%d", &closed);
            if(closed != 99){
                closed = 0;
            }
            break;
        case 2:
            printf("Digite a tensao: ");
            scanf("%f", &tensao);
            printf("Area a: ");
            scanf("%f", &larg_a);
            printf("area b: ");
            scanf("%f", &larg_b);
            printf("Digite a quantidade de faces a serem cisalhadas: ");
            scanf("%f", &faces);
            cis = cisalhamento(tensao,larg_a,larg_b,faces);
            printf("O valor do cisalhamento e de AREA X TENSAO: %f\n", cis);
            printf("para sair digite 99: ");
            scanf("%d", &closed);
            if(closed != 99){
                closed = 0;
            }
            break;
        case 3:
            printf("Digite a tensao: ");
            scanf("%f", &tensao);
            printf("Area a: ");
            scanf("%f", &larg_a);
            printf("Area b: ");
            scanf("%f", &larg_b);
            printf("Digite a quantidade de pontos a serem esmagados: ");
            scanf("%f", &elementos);
            esm = esmagamento(tensao,larg_a,larg_b,elementos);
            printf("O valor do esmagamento e de AREA X TENSAI: %f\n", esm);
            printf("para sair digite 99 para usar novamento digite outro numero: ");
            scanf("%d", &closed);
            if(closed != 99){
                closed = 0;
            }
            break;
        case 4:
            printf("Digite aqui o numero do aluno recebido: ");
            scanf("%d", &pp_gaucho);
            pp_aluno(pp_gaucho);
            break;
        default:
            closed = 0;
            printf("Digite um valor correspondente a tabela\n\n");
            break;
        case 5:
            closed = 99;
            break;
        }
    }
    return 0;
}
