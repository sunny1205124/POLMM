// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// fitPOLMMcpp
Rcpp::List fitPOLMMcpp(bool t_flagSparseGRM, bool t_flagGMatRatio, std::string t_bimfile, std::string t_famfile, std::string t_bedfile, arma::ivec t_posSampleInPlink, arma::mat t_Cova, arma::Col<int> t_yVec, arma::vec t_beta, arma::vec t_bVec, arma::vec t_eps, double t_tau, arma::mat t_GMatRatio, Rcpp::List t_SparseGRM, Rcpp::List t_controlList);
RcppExport SEXP _POLMM_fitPOLMMcpp(SEXP t_flagSparseGRMSEXP, SEXP t_flagGMatRatioSEXP, SEXP t_bimfileSEXP, SEXP t_famfileSEXP, SEXP t_bedfileSEXP, SEXP t_posSampleInPlinkSEXP, SEXP t_CovaSEXP, SEXP t_yVecSEXP, SEXP t_betaSEXP, SEXP t_bVecSEXP, SEXP t_epsSEXP, SEXP t_tauSEXP, SEXP t_GMatRatioSEXP, SEXP t_SparseGRMSEXP, SEXP t_controlListSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< bool >::type t_flagSparseGRM(t_flagSparseGRMSEXP);
    Rcpp::traits::input_parameter< bool >::type t_flagGMatRatio(t_flagGMatRatioSEXP);
    Rcpp::traits::input_parameter< std::string >::type t_bimfile(t_bimfileSEXP);
    Rcpp::traits::input_parameter< std::string >::type t_famfile(t_famfileSEXP);
    Rcpp::traits::input_parameter< std::string >::type t_bedfile(t_bedfileSEXP);
    Rcpp::traits::input_parameter< arma::ivec >::type t_posSampleInPlink(t_posSampleInPlinkSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type t_Cova(t_CovaSEXP);
    Rcpp::traits::input_parameter< arma::Col<int> >::type t_yVec(t_yVecSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type t_beta(t_betaSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type t_bVec(t_bVecSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type t_eps(t_epsSEXP);
    Rcpp::traits::input_parameter< double >::type t_tau(t_tauSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type t_GMatRatio(t_GMatRatioSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type t_SparseGRM(t_SparseGRMSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type t_controlList(t_controlListSEXP);
    rcpp_result_gen = Rcpp::wrap(fitPOLMMcpp(t_flagSparseGRM, t_flagGMatRatio, t_bimfile, t_famfile, t_bedfile, t_posSampleInPlink, t_Cova, t_yVec, t_beta, t_bVec, t_eps, t_tau, t_GMatRatio, t_SparseGRM, t_controlList));
    return rcpp_result_gen;
END_RCPP
}
// getobjP
Rcpp::List getobjP(arma::mat t_Cova, arma::mat t_yMat, arma::mat t_muMat, arma::mat t_iRMat);
RcppExport SEXP _POLMM_getobjP(SEXP t_CovaSEXP, SEXP t_yMatSEXP, SEXP t_muMatSEXP, SEXP t_iRMatSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type t_Cova(t_CovaSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type t_yMat(t_yMatSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type t_muMat(t_muMatSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type t_iRMat(t_iRMatSEXP);
    rcpp_result_gen = Rcpp::wrap(getobjP(t_Cova, t_yMat, t_muMat, t_iRMat));
    return rcpp_result_gen;
END_RCPP
}
// outputadjGFast
Rcpp::List outputadjGFast(arma::vec GVec, Rcpp::List objP);
RcppExport SEXP _POLMM_outputadjGFast(SEXP GVecSEXP, SEXP objPSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type GVec(GVecSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type objP(objPSEXP);
    rcpp_result_gen = Rcpp::wrap(outputadjGFast(GVec, objP));
    return rcpp_result_gen;
END_RCPP
}
// getyMatR
arma::mat getyMatR(arma::mat yVec, int n, int J);
RcppExport SEXP _POLMM_getyMatR(SEXP yVecSEXP, SEXP nSEXP, SEXP JSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type yVec(yVecSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type J(JSEXP);
    rcpp_result_gen = Rcpp::wrap(getyMatR(yVec, n, J));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_POLMM_fitPOLMMcpp", (DL_FUNC) &_POLMM_fitPOLMMcpp, 15},
    {"_POLMM_getobjP", (DL_FUNC) &_POLMM_getobjP, 4},
    {"_POLMM_outputadjGFast", (DL_FUNC) &_POLMM_outputadjGFast, 2},
    {"_POLMM_getyMatR", (DL_FUNC) &_POLMM_getyMatR, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_POLMM(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
