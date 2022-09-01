#include <Rcpp.h>
using namespace Rcpp;
using namespace std;

//'@title Combinar Objetos R por filas 
//'@description Funcion que realiza la union de un DataFrame o Matriz con un vector.
//'@param RObjeto A : Objeto que puede ser un DataFrame o Matriz.
//'@param NumericVector x : Objeto de tipo vector numerico que debe ser del mismo tamaño 
//'que las columnas del DataFrame o Matriz.
//'@return Devuelve una Matriz con el vector añadido como nueva Fila en caso que se le pase una matriz como
//'parametro y un DataFrame con el vector como nueva Fila en caso que se le pase un
//'DataFrame como parametro.
//'@example
//'matrizPrueba1 <- matrix(round(runif(16, 1, 10)), nrow = 4, ncol = 4)
//'set.seed(123)
//'matrizPrueba1
//'
//'mi_df <- data.frame(1:4, 5:8, 9:12, 13:16)
//'mi_df
//'
//'rBIND_rcpp(mi_df, x)
//'rBIND_rcpp(matrizPrueba1, x)
//'

// [[Rcpp::export]]
RObject rBIND_rcpp(RObject A, NumericVector vect) {
  NumericVector vacio = {0};
  if(is<DataFrame>(A)){
    DataFrame dA = as<DataFrame>(A);
    DataFrame Dresult;
    if(vect.size() == dA.ncol()){
      for(int c = 0; c < dA.ncol(); c++){
        NumericVector colum = dA[c];
        colum.push_back(vect(c));
        Dresult.push_back(colum, "col");
      }
      return Dresult;
    }else{
      Rcout << "Vector length is invalid" << "\n";
    }
    
  }else if(is<NumericMatrix>(A)){
    NumericMatrix mA = as<NumericMatrix>(A);
    if(vect.size() == mA.ncol()){
      NumericMatrix Mresult(mA.nrow()+1 , mA.ncol());
      NumericVector Maux;
      for(int i = 0; i < vect.size();i++){
        Maux = mA.column(i);
        Maux.push_back(vect(i));
        Mresult.column(i) = Maux;
      }
      return Mresult;
    }else{
      Rcout << "Vector length is invalid" << "\n";
    }
  }
  return vacio;
}
