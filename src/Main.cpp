
// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>

#include <string>

#include "DenseGRM.hpp"
#include "Plink.hpp"
#include "SubFunc.hpp"
#include "POLMM.hpp"

using namespace Rcpp;
using namespace std;
using namespace Plink;
using namespace DenseGRM;
using namespace POLMM;

Rcpp::List getKinMatList(Rcpp::List KinMatListR)
{
  int nKin = KinMatListR.size();
  Rcpp::CharacterVector NameKin = KinMatListR.names();
  Rcpp::List KinMatList_sp;
  for(int i = 0; i < nKin; i ++){
    string excludeChr = string(NameKin[i]);
    Rcpp::List KinMatTemp = KinMatListR[excludeChr];
    arma::umat locations = KinMatTemp["locations"];
    arma::vec values = KinMatTemp["values"];
    int n = KinMatTemp["nSubj"];
    // make a sparse matrix
    arma::sp_mat KinMat(locations, values, n, n);
    KinMatList_sp[excludeChr] = KinMat;
  }
  return KinMatList_sp;
}


// [[Rcpp::export]]
Rcpp::List fitPOLMMcpp(bool t_flagSparseGRM,       // if 1, then use SparseGRM, otherwise, use DenseGRM
                       bool t_flagGMatRatio,       // if 1, then use GMatRatio, otherwise, extract from Plink files
                       std::string t_bimfile,
                       std::string t_famfile,
                       std::string t_bedfile, 
                       arma::ivec t_posSampleInPlink,
                       arma::mat t_Cova,
                       arma::Col<int> t_yVec,     // should be from 1 to J
                       arma::vec t_beta,
                       arma::vec t_bVec,
                       arma::vec t_eps,           // 
                       double t_tau,
                       arma::mat t_GMatRatio,     // only used if m_LOCO = FALSE
                       Rcpp::List t_SparseGRM,
                       Rcpp::List t_controlList)
{
  // Plink and DenseGRM class object
  PlinkClass PlinkObj;
  DenseGRMClass DenseGRMObj;
  
  Rcpp::List KinMatList;
  if(!t_flagGMatRatio || !t_flagSparseGRM){
    PlinkObj.setPlinkObj(t_bimfile, t_famfile, t_bedfile, t_posSampleInPlink);
  }
  
  if(!t_flagSparseGRM){
    double memoryChunk = t_controlList["memoryChunk"];
    double minMafGRM = t_controlList["minMafGRM"];
    double maxMissingGRM = t_controlList["maxMissingGRM"];
    DenseGRMObj.setDenseGRMObj(&PlinkObj, memoryChunk, minMafGRM, maxMissingGRM);
  }else{
    KinMatList = getKinMatList(t_SparseGRM);
  }
  
  // POLMM class object
  POLMMClass POLMMObj;
  POLMMObj.setPOLMMObj(t_flagSparseGRM,       // if 1, then use SparseGRM, otherwise, use DenseGRM
                       t_flagGMatRatio,       // if 1, then use GMatRatio, otherwise, extract from Plink files
                       &PlinkObj,
                       &DenseGRMObj,
                       t_Cova,
                       t_yVec,     // should be from 1 to J
                       t_beta,
                       t_bVec,
                       t_eps,           // 
                       t_tau,
                       t_GMatRatio,     // only used if m_LOCO = FALSE
                       KinMatList,
                       t_controlList);
  
  // Null model fitting
  if(!t_controlList["onlyCheckTime"])
    POLMMObj.fitPOLMM();
  
  Rcpp::List outList = POLMMObj.getPOLMM();
  
  POLMMObj.closeGenoObj();
  
  return(outList);
}


