#include <Rcpp.h>
using namespace Rcpp;
using namespace std;

//'@title Combinar Objetos R por Columnas
//'@description Funcion que realiza la union de un DataFrame o Matriz con un vector.
//'@param RObjeto A : Objeto que puede ser un DataFrame o Matriz.
//'@param NumericVector x : Objeto de tipo vector numerico que debe ser del mismo tamaño 
//'que las columnas del DataFrame o Matriz.
//'@return Devuelve una Matriz con el vector añadido como nueva columna en caso que se le pase una matriz como
//'parametro y un DataFrame con el vector como nueva columna en caso que se le pase un
//'DataFrame como parametro.
//'@example
//'matrizPrueba1 <- matrix(round(runif(16, 1, 10)), nrow = 4, ncol = 4)
//'set.seed(123)
//'matrizPrueba1
//'
//'mi_df <- data.frame(1:4, 5:8, 9:12, 13:16)
//'mi_df
//'
//'cBIND_rcpp(mi_df, x)
//'cBIND_rcpp(matrizPrueba1, x)


// [[Rcpp::export]]
RObject cBIND_rcpp(RObject A, NumericVector vect) {
  NumericVector vacio = {0,0};
  if(is<DataFrame>(A)){
    DataFrame dA = as<DataFrame>(A);
    if(vect.size() == dA.nrow()){
      dA.push_back(vect, "col added");
      return dA;
    }
    else{
      Rcout << "Vector length is invalid" << "\n";
    }
  }
  else if(is<NumericMatrix>(A)){
    NumericMatrix mA = as<NumericMatrix>(A);
    if(vect.size() == mA.nrow()){
      NumericMatrix Mresult(mA.nrow() , mA.ncol()+1);
      NumericVector Maux;
      for(int i = 0; i < vect.size();i++){
        Maux = mA.row(i);
        Maux.push_back(vect(i));
        Mresult.row(i) = Maux;
      }
      return Mresult;
    }
    else{
      Rcout << "Vector length is invalid" << "\n";
    }
  }
  return vacio;
}


