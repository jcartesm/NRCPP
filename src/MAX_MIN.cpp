#include <Rcpp.h>
using namespace Rcpp;
using namespace std;

//'@title Comparacion entre maximos y minimos en Matrices cuadradas
//'@description Compara la primera fila de la primera matriz con la columna de la 
//'segunda matriz tomando los valores minimos entre ambos y generando un nuevo vector
//'luego dentro de ese vector ver cual es el maximo, lo que nos lleva al valor que queda
//'en esa posicion
//'@param NumericMatrix A : Matriz cuadrada de NxN
//'@param NumericMatrix B : Matriz cuadrada de NxN
//'@return Devuelve una matriz de NxN con los valores resultantes de dicha comparacion
//'realizada dentro de la funcion.
//'@example
//'
//'matrizPrueba1 <- matrix(round(runif(16, 1, 10)), nrow = 4, ncol = 4)
//'matrizPrueba2 <- matrix(round(runif(16, 10, 20)), nrow = 4, ncol = 4)
//'set.seed(123)
//'  
//'matrizPrueba1
//'matrizPrueba2
//'
//'MAX_MIN_rcpp(matrizPrueba1, matrizPrueba2)
//'´
//'

// [[Rcpp::export]]
NumericMatrix MAX_MIN_rcpp(NumericMatrix A, NumericMatrix B) {
  int n = A.nrow();
  NumericMatrix C(n);
  for(int f = 0; f < n; f++){
    for(int c = 0; c < n; c++){
      NumericVector aux(n);
      for(int m = 0; m < n; m++){
        if(A(f,m) < B(m,c)){
          aux.insert(m,A(f,m));
        }else{
          aux.insert(m,B(m,c));
        }
      }
      C(f,c) = max(aux);
    }
  }
  return C;
}
