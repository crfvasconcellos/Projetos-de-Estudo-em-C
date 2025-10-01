#ifndef RECUPERASEQUENCIAS_H
#define RECUPERASEQUENCIAS_H



typedef struct _listadetriplas ListaDeTriplas;


ListaDeTriplas * ListaDeTriplas_criar();

void ListaDeTriplas_recebetriplas(ListaDeTriplas** L);
void ListaDeTriplas_inserir(ListaDeTriplas* L, int id, float val, int proximoid);
void ListaDeTriplas_destroir(ListaDeTriplas ** L);
void ListaDeTriplas_print(ListaDeTriplas * L );

#endif