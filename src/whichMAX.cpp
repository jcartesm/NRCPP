#include <Rcpp.h>
using namespace Rcpp;
using namespace std;

//'@title Buscardor de indices de maximos en Objetos de R
//'@description Funcion que realiza la busqueda de el o los maximos dentro de 
//'un objeto de R.
//'@param RObjeto A : Objeto R para la realizacion de la busqueda de indice de maximo.
//'@return Devuelve un DataFrame conteniendo en sus columnas las posiciones en las que
//'se encuentran el o los valores maximos dentro del objeto. 
//'@example
//'matrizPrueba1 <- matrix(round(runif(16, 1, 10)), nrow = 4, ncol = 4)
//'set.seed(123)
//'matrizPrueba1
//'
//'whichMAX_rcpp(matrizPrueba1)
//'

// [[Rcpp::export]]
DataFrame whichMAX_rcpp(RObject x) {
  DataFrame result;
  // if(is<NumericVector>(x)){
  //   NumericVector v = as<NumericVector>(x);
  //   int large = v.size();
  //   int piv = 1;
  //   for(int i = 0; i < large; i++){
  //     if(v(i) > piv){
  //       piv = v(i);
  //     }
  //   }
  //   
  //   for (int j = 0; j < large; j++) {
  //     int Buscando = v(j);
  //     if (Buscando == piv) {
  //       result.push_back(j+1);
  //     }
  //   }
  //   return result;
  // }
  if(is<NumericMatrix>(x)){
    NumericMatrix mv = as<NumericMatrix>(x);
    int large = mv.nrow();
    int anchor = mv.ncol();
    int piv = mv(0,0);
    NumericVector filas;
    for(int i = 0; i < large; i++){
      for(int k = 0; k < anchor; k++){
        if(mv(i,k) == piv){
          filas = NumericVector::create(i+1,k+1);
          result.push_back(filas, "pos");
        }else if(mv(i,k) > piv){
          piv = mv(i,k);
          filas = NumericVector::create(i+1,k+1);
          result.erase(0,result.size());
          result.push_front(filas, "pos");
        }
      }
    }
    return result;

  }
  // else if(is<DataFrame>(x)){
  //   DataFrame dv = as<DataFrame>(x);
  //   DataFrame Dresult;
  //   int large = dv.nrow();
  //   int anchor = dv.ncol();
  //   int piv = dv(0,0);
  //   NumericVector filas;
  //   NumericVector col;
  //   for(int i = 0; i < anchor; i++){
  //     col = dv[i];
  //     for(int k = 0; k < large; k++){
  //       if(col(k) == piv){
  //         filas = NumericVector::create(i+1,k+1);
  //         Dresult.push_back(filas);
  //       }else if(col(k) > piv){
  //         piv = dv(i,k);
  //         filas = NumericVector::create(i+1,k+1);
  //         Dresult.erase(0,Dresult.size());
  //         Dresult.push_front(filas);
  //       }
  //     }
  //   }
  //   return Dresult;
  //   
  // }
  return result;
}




