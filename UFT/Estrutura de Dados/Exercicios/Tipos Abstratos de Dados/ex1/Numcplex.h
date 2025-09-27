
#define COMPLEXO_H



typedef struct _complexo Complexo;

Complexo * criarComplexo(float x, float y);
void destroi(Complexo * num);
Complexo* somaComplexos(Complexo* num1, Complexo* num2);
Complexo * subtraiComplexos(Complexo* num1, Complexo* num2);
void imprimirComplexo(const Complexo* c);