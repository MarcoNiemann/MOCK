#include <Rcpp.h>
#include <math.h>
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::NumericVector mutateCR(Rcpp::NumericVector sol, Rcpp::NumericMatrix nn,int L, Rcpp::NumericMatrix neighborhood, Rcpp::NumericVector randomVectorMutation, NumericVector randomVectorSelection) {
  Rcpp::NumericVector newsol = sol;
  for(int i = 0; i<sol.size(); i++)
  {
    if(randomVectorMutation[i] < neighborhood(i,sol[i]-1))
    {
      newsol[i]=nn(i,randomVectorSelection[i]-1);
    }  
  }
  return(newsol);
}
  