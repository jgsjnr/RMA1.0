#include <stdio.h>
#include <stdlib.h>
#include "tens.h"

float rompimento(float tensao, float larga, float largb, int faces){
    float f, area, arear;
    area = larga * largb;
    printf("A tensao dada e de %.0f\n", tensao);
    printf("medidas utilizadas utilizdas sao cota %.2f e cota %.2f (ATENCAO A COTA 7 - RAIO DO PINO CONDIZ COM A COTA AO LADO)\n", larga, largb);
    printf("A area e de: %.2f e a quantidade de faces %d\n", area, faces);
    arear = area * faces;
    printf("A area x quantidade de faces e de: %.2f\n", arear);
    f = tensao*arear;
    printf("equacacao:\n f = T x A \n f = %.0f x (%.2f x %.2f)x%i \n f = %.0f x %.2f \n f = %.2f",tensao, larga, largb, faces, tensao, arear, f);
    return f;
}
float cisalhamento(float tensao, float larga, float largb, int faces){
    float tensao_c;
    float f, area, arear;
    tensao_c = tensao*0.7;
    printf("A tensao e de %.0f\n", tensao);
    printf("tensao de cisalhamento e que e (%.2f x 0,7) e de: %.2f \n", tensao, tensao_c);
    printf("medidas utilizadas utilizdas cota %.2f e cota %.2f\n", larga, largb);
    area = larga * largb;
    printf("A area em (%.2f x %.2f) e de %f com a quantidade de faces %d\n",larga, largb, area, faces);
    arear = area * faces;
    printf("A area x quantidade de faces e de: %.2f\n", arear);
    f = tensao_c*arear;
    printf("equacacao:\n f = T x A \n f = (%.0f x 0,7) x (%.2f x %.2f)x%i \n f = %.2f x (%.0f)x%i \n f = %.2f x %.2f \n f = %.2f",tensao, larga, largb, faces, tensao_c, area, faces, tensao_c, arear, f);
    return f;
}
float cisalhamento_pino(float tensao, float larga, int faces){
    float tensao_c;
    float f, area, arear, pino_pi, auxa, auxb;
    auxa = larga/2;
    auxb = auxa*auxa;
    pino_pi = auxb*_PI;
    tensao_c = tensao*0.7;
    printf("A tensao e de %.0f\n", tensao);
    printf("tensao de cisalhamento e que e (%.2f x 0,7) e de: %.2f \n", tensao, tensao_c);
    printf("medidas utilizadas utilizdas cota (%.2f/2) que e igual a %.2f\n", larga, auxa);
    area = pino_pi;
    printf("a area (%.2f x pi) fica = %.2f\n",auxb, area);
    printf("A area fica em %.2f com a quantidade de faces a serem cisalhadas %d\n",area, faces);
    arear = area * faces;
    printf("A area x quantidade de faces e de: %.2f\n", arear);
    f = tensao_c*arear;
    printf("equacacao:\n f = T x A \n f = (%.0f x 0,7) x (%.2f^2 x PI)x%i \n f = %.2f x (%.2f)x%i \n f = %.2f x %.2f \n f = %.2f",tensao, auxa, faces, tensao_c, area, faces, tensao_c, arear, f);
    return f;
}
float esmagamento(float tensao, float larga, float largb, int faces){
    float area, arear;
    double f, f_a;
    area = larga * largb;
    printf("A tensao e de %.0f\n", tensao);
    printf("medidas utilizadas utilizdas cota %.2f e cota %.2f\n", larga, largb);
    printf("A area de (%.2f x %.2f) e de: %.2f quantidade de pontos e de %d\n",larga, largb, area, faces);
    arear = area * faces;
    printf("A area %.2f x quantidade de pontos %i e de: %.2f\n",area, faces, arear);
    f_a = tensao*arear;
    printf("Tensao antes de ser divida por 2,4 %.2f \n", f_a);
    f = f_a/2.4;
    printf("Tensao apos ser divida por 2,4 %.2f \n", f);
    printf("equacao: \n f = T x A/2.4\n");
    printf("f = %.0f x (%.2f x %.2f)x%i/2.4\n",tensao, larga, largb, faces);
    printf("f = %.0f x (%f)%i/2.4\n", tensao, area, faces);
    printf("f= %.0f x %.2f/2.4\n",tensao, arear);
    printf("f= %.2f/2.4\n",f_a);
    printf("f = %.2f\n", f);
    return f;
}
float rompimento_haste(float tensao, float larga){
    float f, area, raio;
    raio = larga/2;
    area = (raio*raio)*_PI;
    printf("A tensao dada e de (%.0f)\n", tensao);
    printf("medidas utilizadas sao cota (%.2f/2) que resulta em %.2f\n", larga, raio);
    printf("sendo (%f^2 x pi) a area resultante e de %.2f \n",raio, area);
    f = tensao*area;
    printf("equacacao:\n f = T x A \n f = %0.f x (%.2f^2 x pi) \n f = %.0f x %.2f \n f = %.2f",tensao, raio, tensao, area, f);
    return f;
}
