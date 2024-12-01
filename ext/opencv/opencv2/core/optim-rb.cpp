#include <opencv2/core/optim.hpp>
#include "optim-rb.hpp"

using namespace Rice;

extern "C"
void Init_Optim()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvMinProblemSolver = define_class_under<cv::MinProblemSolver, cv::Algorithm>(rb_mCv, "MinProblemSolver").
    define_method<cv::Ptr<cv::MinProblemSolver::Function>(cv::MinProblemSolver::*)() const>("get_function", &cv::MinProblemSolver::getFunction).
    define_method<void(cv::MinProblemSolver::*)(const cv::Ptr<cv::MinProblemSolver::Function>&)>("set_function", &cv::MinProblemSolver::setFunction).
    define_method<cv::TermCriteria(cv::MinProblemSolver::*)() const>("get_term_criteria", &cv::MinProblemSolver::getTermCriteria).
    define_method<void(cv::MinProblemSolver::*)(const cv::TermCriteria&)>("set_term_criteria", &cv::MinProblemSolver::setTermCriteria).
    define_method<double(cv::MinProblemSolver::*)(const cv::_InputOutputArray &)>("minimize", &cv::MinProblemSolver::minimize);
  
  Class rb_cCvMinProblemSolverFunction = define_class_under<cv::MinProblemSolver::Function>(rb_cCvMinProblemSolver, "Function").
    define_method<int(cv::MinProblemSolver::Function::*)() const>("get_dims", &cv::MinProblemSolver::Function::getDims).
    define_method<double(cv::MinProblemSolver::Function::*)() const>("get_gradient_eps", &cv::MinProblemSolver::Function::getGradientEps).
    define_method<double(cv::MinProblemSolver::Function::*)(const double*) const>("calc", &cv::MinProblemSolver::Function::calc).
    define_method<void(cv::MinProblemSolver::Function::*)(const double*, double*)>("get_gradient", &cv::MinProblemSolver::Function::getGradient);
  
  Class rb_cCvDownhillSolver = define_class_under<cv::DownhillSolver, cv::MinProblemSolver>(rb_mCv, "DownhillSolver").
    define_method<void(cv::DownhillSolver::*)(const cv::_OutputArray &) const>("get_init_step", &cv::DownhillSolver::getInitStep).
    define_method<void(cv::DownhillSolver::*)(const cv::_InputArray &)>("set_init_step", &cv::DownhillSolver::setInitStep).
    define_singleton_function<cv::Ptr<cv::DownhillSolver>(*)(const cv::Ptr<cv::MinProblemSolver::Function>&, const cv::_InputArray &, cv::TermCriteria)>("create", &cv::DownhillSolver::create);
  
  Class rb_cCvConjGradSolver = define_class_under<cv::ConjGradSolver, cv::MinProblemSolver>(rb_mCv, "ConjGradSolver").
    define_singleton_function<cv::Ptr<cv::ConjGradSolver>(*)(const cv::Ptr<cv::MinProblemSolver::Function>&, cv::TermCriteria)>("create", &cv::ConjGradSolver::create);
  
  Enum<cv::SolveLPResult> rb_cCvSolveLPResult = define_enum<cv::SolveLPResult>("SolveLPResult", rb_mCv).
    define_value("SOLVELP_LOST", cv::SolveLPResult::SOLVELP_LOST).
    define_value("SOLVELP_UNBOUNDED", cv::SolveLPResult::SOLVELP_UNBOUNDED).
    define_value("SOLVELP_UNFEASIBLE", cv::SolveLPResult::SOLVELP_UNFEASIBLE).
    define_value("SOLVELP_SINGLE", cv::SolveLPResult::SOLVELP_SINGLE).
    define_value("SOLVELP_MULTI", cv::SolveLPResult::SOLVELP_MULTI);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, double)>("solve_lp", &cv::solveLP);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("solve_lp", &cv::solveLP);
}