#include <opencv2/surface_matching/t_hash_int.hpp>
#include "t_hash_int-rb.hpp"

using namespace Rice;

extern "C"
void Init_THashInt()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvPpfMatch3d = define_module_under(rb_mCv, "PpfMatch3d");
  
  Class rb_cCvPpfMatch3dHashnodeI = define_class_under<cv::ppf_match_3d::hashnode_i>(rb_mCvPpfMatch3d, "HashnodeI").
    define_attr("key", &cv::ppf_match_3d::hashnode_i::key).
    define_attr("data", &cv::ppf_match_3d::hashnode_i::data).
    define_attr("next", &cv::ppf_match_3d::hashnode_i::next);
  
  Class rb_cCvPpfMatch3dHSHTBLI = define_class_under<cv::ppf_match_3d::HSHTBL_i>(rb_mCvPpfMatch3d, "HSHTBLI").
    define_attr("size", &cv::ppf_match_3d::HSHTBL_i::size).
    define_attr("nodes", &cv::ppf_match_3d::HSHTBL_i::nodes).
    define_attr("hashfunc", &cv::ppf_match_3d::HSHTBL_i::hashfunc);
  
  rb_mCvPpfMatch3d.define_module_function<cv::ppf_match_3d::HSHTBL_i*(*)(unsigned long long, size_t (int)*)>("hashtable_create", &cv::ppf_match_3d::hashtableCreate);
  
  rb_mCvPpfMatch3d.define_module_function<void(*)(cv::ppf_match_3d::HSHTBL_i*)>("hashtable_destroy", &cv::ppf_match_3d::hashtableDestroy);
  
  rb_mCvPpfMatch3d.define_module_function<int(*)(cv::ppf_match_3d::HSHTBL_i*, int, void*)>("hashtable_insert", &cv::ppf_match_3d::hashtableInsert);
  
  rb_mCvPpfMatch3d.define_module_function<int(*)(cv::ppf_match_3d::HSHTBL_i*, int, void*)>("hashtable_insert_hashed", &cv::ppf_match_3d::hashtableInsertHashed);
  
  rb_mCvPpfMatch3d.define_module_function<int(*)(cv::ppf_match_3d::HSHTBL_i*, int)>("hashtable_remove", &cv::ppf_match_3d::hashtableRemove);
  
  rb_mCvPpfMatch3d.define_module_function<void*(*)(cv::ppf_match_3d::HSHTBL_i*, int)>("hashtable_get", &cv::ppf_match_3d::hashtableGet);
  
  rb_mCvPpfMatch3d.define_module_function<cv::ppf_match_3d::hashnode_i*(*)(cv::ppf_match_3d::HSHTBL_i*, int)>("hashtable_get_bucket_hashed", &cv::ppf_match_3d::hashtableGetBucketHashed);
  
  rb_mCvPpfMatch3d.define_module_function<int(*)(cv::ppf_match_3d::HSHTBL_i*, unsigned long long)>("hashtable_resize", &cv::ppf_match_3d::hashtableResize);
  
  rb_mCvPpfMatch3d.define_module_function<cv::ppf_match_3d::HSHTBL_i*(*)(cv::ppf_match_3d::HSHTBL_i*)>("hashtable_int_clone", &cv::ppf_match_3d::hashtable_int_clone);
  
  rb_mCvPpfMatch3d.define_module_function<cv::ppf_match_3d::HSHTBL_i*(*)(_iobuf*)>("hashtable_read", &cv::ppf_match_3d::hashtableRead);
  
  rb_mCvPpfMatch3d.define_module_function<int(*)(const cv::ppf_match_3d::HSHTBL_i*, const unsigned long long, _iobuf*)>("hashtable_write", &cv::ppf_match_3d::hashtableWrite);
  
  rb_mCvPpfMatch3d.define_module_function<void(*)(cv::ppf_match_3d::HSHTBL_i*)>("hashtable_print", &cv::ppf_match_3d::hashtablePrint);
}