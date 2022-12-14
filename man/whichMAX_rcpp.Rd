% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{whichMAX_rcpp}
\alias{whichMAX_rcpp}
\title{Buscardor de indices de maximos en Objetos de R}
\usage{
whichMAX_rcpp(x)
}
\arguments{
\item{RObjeto}{A : Objeto R para la realizacion de la busqueda de indice de maximo.}
}
\value{
Devuelve un DataFrame conteniendo en sus columnas las posiciones en las que
se encuentran el o los valores maximos dentro del objeto.
}
\description{
Funcion que realiza la busqueda de el o los maximos dentro de
un objeto de R.
}
\examples{
matrizPrueba1 <- matrix(round(runif(16, 1, 10)), nrow = 4, ncol = 4);
set.seed(123);
matrizPrueba1;
whichMAX_rcpp(matrizPrueba1);
}
