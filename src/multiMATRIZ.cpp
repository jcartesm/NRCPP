#include <Rcpp.h>
using namespace Rcpp;
using namespace std;

//'@title Multiplicacion de Objetos R de tipo Matriz
//'@description La funcion realiza la multiplicacion de dos matrices 
//'mediante su formulacion matematica de multiplicacion de matrices, lo que 
//'quiere decir que es necesario que el numero de filas de la primera matriz
//'sea igual al numero de columnas de la segunda matriz
//'@param NumericMatrix A : Matriz de dimension NxM
//'@param NumericMatrix B : MAtriz de dimension MxN
//'@return Devuelve una matriz de resultado de dimension N filas de primera 
//'matriz y N columnas de segunda matriz.
//'@example
//'
//'matrizPrueba1 <- matrix(round(runif(16, 1, 10)), nrow = 4, ncol = 4)
//'matrizPrueba2 <- matrix(round(runif(16, 10, 20)), nrow = 4, ncol = 4)
//'set.seed(123)
//'
//'matrizPrueba1
//'matrizPrueba2
//'
//'multiMATRIZ_rcpp(matrizPrueba1, matrizPrueba2)
//'
//'

// [[Rcpp::export]]
NumericMatrix multiMATRIZ_rcpp(NumericMatrix A, NumericMatrix B) {
  int fil_A = A.nrow();
  int col_B = B.ncol();
  float n;
  NumericMatrix Result(fil_A);
  if(fil_A == col_B){
    for(int f = 0; f < fil_A; f++){
      for(int c = 0; c < col_B; c++){
        for(int i = 0; i <= fil_A; i++){
          n += (A(f,i) * B(i,c));
          Result(f,c) = n;
        }
        n = 0;
      }
    }
  }
  else{
    return 1;
  }
  return Result;
}



