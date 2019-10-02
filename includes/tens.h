#ifndef TENS_H_INCLUDED
#define TENS_H_INCLUDED
#define _PI 3.14159

float rompimento(float tensao, float larg_a, float larg_b, int faces);
float cisalhamento(float tensao, float larg_a, float larg_b, int faces);
float esmagamento(float tensao, float larga, float larb, int faces);
float cisalhamento_pino(float tensao, float larga, int faces);
float rompimento_haste(float tensao, float larga);
#endif // TENS_H_INCLUDED
