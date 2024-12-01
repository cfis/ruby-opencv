#include <opencv2/core/persistence.hpp>
#include "persistence-rb.hpp"

using namespace Rice;

extern "C"
void Init_Persistence()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvFileStorage = define_class_under<cv::FileStorage>(rb_mCv, "FileStorage").
    define_constructor(Constructor<cv::FileStorage>()).
    define_constructor(Constructor<cv::FileStorage, const std::basic_string<char>&, int, const std::basic_string<char>&>()).
    define_method<bool(cv::FileStorage::*)(const std::basic_string<char>&, int, const std::basic_string<char>&)>("open", &cv::FileStorage::open).
    define_method<bool(cv::FileStorage::*)() const>("is_opened", &cv::FileStorage::isOpened).
    define_method<void(cv::FileStorage::*)()>("release", &cv::FileStorage::release).
    define_method<std::basic_string<char>(cv::FileStorage::*)()>("release_and_get_string", &cv::FileStorage::releaseAndGetString).
    define_method<cv::FileNode(cv::FileStorage::*)() const>("get_first_top_level_node", &cv::FileStorage::getFirstTopLevelNode).
    define_method<cv::FileNode(cv::FileStorage::*)(int) const>("root", &cv::FileStorage::root).
    define_method<cv::FileNode(cv::FileStorage::*)(const std::basic_string<char>&) const>("operator[]", &cv::FileStorage::operator[]).
    define_method<cv::FileNode(cv::FileStorage::*)(const char*) const>("operator[]", &cv::FileStorage::operator[]).
    define_method<void(cv::FileStorage::*)(const std::basic_string<char>&, int)>("write", &cv::FileStorage::write).
    define_method<void(cv::FileStorage::*)(const std::basic_string<char>&, double)>("write", &cv::FileStorage::write).
    define_method<void(cv::FileStorage::*)(const std::basic_string<char>&, const std::basic_string<char>&)>("write", &cv::FileStorage::write).
    define_method<void(cv::FileStorage::*)(const std::basic_string<char>&, const cv::Mat&)>("write", &cv::FileStorage::write).
    define_method<void(cv::FileStorage::*)(const std::basic_string<char>&, const std::vector<std::basic_string<char>>&)>("write", &cv::FileStorage::write).
    define_method<void(cv::FileStorage::*)(const std::basic_string<char>&, const void*, unsigned long long)>("write_raw", &cv::FileStorage::writeRaw).
    define_method<void(cv::FileStorage::*)(const std::basic_string<char>&, bool)>("write_comment", &cv::FileStorage::writeComment).
    define_method<void(cv::FileStorage::*)(const std::basic_string<char>&, int, const std::basic_string<char>&)>("start_write_struct", &cv::FileStorage::startWriteStruct).
    define_method<void(cv::FileStorage::*)()>("end_write_struct", &cv::FileStorage::endWriteStruct).
    define_singleton_function<std::basic_string<char>(*)(const std::basic_string<char>&)>("get_default_object_name", &cv::FileStorage::getDefaultObjectName).
    define_method<int(cv::FileStorage::*)() const>("get_format", &cv::FileStorage::getFormat).
    define_attr("state", &cv::FileStorage::state).
    define_attr("elname", &cv::FileStorage::elname).
    define_attr("p", &cv::FileStorage::p);
  
  
  Enum<cv::FileStorage::Mode> rb_cCvFileStorageMode = define_enum<cv::FileStorage::Mode>("Mode", rb_cCvFileStorage).
    define_value("READ", cv::FileStorage::Mode::READ).
    define_value("WRITE", cv::FileStorage::Mode::WRITE).
    define_value("APPEND", cv::FileStorage::Mode::APPEND).
    define_value("MEMORY", cv::FileStorage::Mode::MEMORY).
    define_value("FORMAT_MASK", cv::FileStorage::Mode::FORMAT_MASK).
    define_value("FORMAT_AUTO", cv::FileStorage::Mode::FORMAT_AUTO).
    define_value("FORMAT_XML", cv::FileStorage::Mode::FORMAT_XML).
    define_value("FORMAT_YAML", cv::FileStorage::Mode::FORMAT_YAML).
    define_value("FORMAT_JSON", cv::FileStorage::Mode::FORMAT_JSON).
    define_value("BASE64", cv::FileStorage::Mode::BASE64).
    define_value("WRITE_BASE64", cv::FileStorage::Mode::WRITE_BASE64);
  
  Enum<cv::FileStorage::State> rb_cCvFileStorageState = define_enum<cv::FileStorage::State>("State", rb_cCvFileStorage).
    define_value("UNDEFINED", cv::FileStorage::State::UNDEFINED).
    define_value("VALUE_EXPECTED", cv::FileStorage::State::VALUE_EXPECTED).
    define_value("NAME_EXPECTED", cv::FileStorage::State::NAME_EXPECTED).
    define_value("INSIDE_MAP", cv::FileStorage::State::INSIDE_MAP);
  
  Class rb_cCvFileNode = define_class_under<cv::FileNode>(rb_mCv, "FileNode").
    define_constructor(Constructor<cv::FileNode>()).
    define_constructor(Constructor<cv::FileNode, const cv::FileStorage*, unsigned long long, unsigned long long>()).
    define_constructor(Constructor<cv::FileNode, const cv::FileNode&>()).
    define_method<cv::FileNode&(cv::FileNode::*)(const cv::FileNode&)>("operator=", &cv::FileNode::operator=).
    define_method<cv::FileNode(cv::FileNode::*)(const std::basic_string<char>&) const>("operator[]", &cv::FileNode::operator[]).
    define_method<cv::FileNode(cv::FileNode::*)(const char*) const>("operator[]", &cv::FileNode::operator[]).
    define_method<cv::FileNode(cv::FileNode::*)(int) const>("operator[]", &cv::FileNode::operator[]).
    define_method<std::vector<std::basic_string<char>>(cv::FileNode::*)() const>("keys", &cv::FileNode::keys).
    define_method<int(cv::FileNode::*)() const>("type", &cv::FileNode::type).
    define_method<bool(cv::FileNode::*)() const>("empty", &cv::FileNode::empty).
    define_method<bool(cv::FileNode::*)() const>("is_none", &cv::FileNode::isNone).
    define_method<bool(cv::FileNode::*)() const>("is_seq", &cv::FileNode::isSeq).
    define_method<bool(cv::FileNode::*)() const>("is_map", &cv::FileNode::isMap).
    define_method<bool(cv::FileNode::*)() const>("is_int", &cv::FileNode::isInt).
    define_method<bool(cv::FileNode::*)() const>("is_real", &cv::FileNode::isReal).
    define_method<bool(cv::FileNode::*)() const>("is_string", &cv::FileNode::isString).
    define_method<bool(cv::FileNode::*)() const>("is_named", &cv::FileNode::isNamed).
    define_method<std::basic_string<char>(cv::FileNode::*)() const>("name", &cv::FileNode::name).
    define_method<unsigned long long(cv::FileNode::*)() const>("size", &cv::FileNode::size).
    define_method<unsigned long long(cv::FileNode::*)() const>("raw_size", &cv::FileNode::rawSize).
    define_singleton_function<bool(*)(int)>("is_map", &cv::FileNode::isMap).
    define_singleton_function<bool(*)(int)>("is_seq", &cv::FileNode::isSeq).
    define_singleton_function<bool(*)(int)>("is_collection", &cv::FileNode::isCollection).
    define_singleton_function<bool(*)(int)>("is_empty_collection", &cv::FileNode::isEmptyCollection).
    define_singleton_function<bool(*)(int)>("is_flow", &cv::FileNode::isFlow).
    define_method<unsigned char*(cv::FileNode::*)()>("ptr", &cv::FileNode::ptr).
    define_method<const unsigned char*(cv::FileNode::*)() const>("ptr", &cv::FileNode::ptr).
    define_method<cv::FileNodeIterator(cv::FileNode::*)() const>("begin", &cv::FileNode::begin).
    define_method<cv::FileNodeIterator(cv::FileNode::*)() const>("end", &cv::FileNode::end).
    define_method<void(cv::FileNode::*)(const std::basic_string<char>&, void*, unsigned long long) const>("read_raw", &cv::FileNode::readRaw).
    define_method<void(cv::FileNode::*)(int, const void*, int)>("set_value", &cv::FileNode::setValue).
    define_method<double(cv::FileNode::*)() const>("real", &cv::FileNode::real).
    define_method<std::basic_string<char>(cv::FileNode::*)() const>("string", &cv::FileNode::string).
    define_method<cv::Mat(cv::FileNode::*)() const>("mat", &cv::FileNode::mat).
    define_constructor(Constructor<cv::FileNode, cv::FileStorage::Impl*, unsigned long long, unsigned long long>()).
    define_attr("fs", &cv::FileNode::fs).
    define_attr("block_idx", &cv::FileNode::blockIdx).
    define_attr("ofs", &cv::FileNode::ofs);
  
  
  Class rb_cCvFileNodeIterator = define_class_under<cv::FileNodeIterator>(rb_mCv, "FileNodeIterator").
    define_constructor(Constructor<cv::FileNodeIterator>()).
    define_constructor(Constructor<cv::FileNodeIterator, const cv::FileNode&, bool>()).
    define_constructor(Constructor<cv::FileNodeIterator, const cv::FileNodeIterator&>()).
    define_method<cv::FileNodeIterator&(cv::FileNodeIterator::*)(const cv::FileNodeIterator&)>("operator=", &cv::FileNodeIterator::operator=).
    define_method<cv::FileNode(cv::FileNodeIterator::*)() const>("operator*", &cv::FileNodeIterator::operator*).
    define_method<cv::FileNodeIterator&(cv::FileNodeIterator::*)()>("operator++", &cv::FileNodeIterator::operator++).
    define_method<cv::FileNodeIterator(cv::FileNodeIterator::*)(int)>("operator++", &cv::FileNodeIterator::operator++).
    define_method<cv::FileNodeIterator&(cv::FileNodeIterator::*)(int)>("operator+=", &cv::FileNodeIterator::operator+=).
    define_method<cv::FileNodeIterator&(cv::FileNodeIterator::*)(const std::basic_string<char>&, void*, unsigned long long)>("read_raw", &cv::FileNodeIterator::readRaw).
    define_method<unsigned long long(cv::FileNodeIterator::*)() const>("remaining", &cv::FileNodeIterator::remaining).
    define_method<bool(cv::FileNodeIterator::*)(const cv::FileNodeIterator&) const>("equal_to", &cv::FileNodeIterator::equalTo);
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const std::basic_string<char>&, int)>("write", &cv::write);
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const std::basic_string<char>&, float)>("write", &cv::write);
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const std::basic_string<char>&, double)>("write", &cv::write);
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const std::basic_string<char>&, const std::basic_string<char>&)>("write", &cv::write);
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const std::basic_string<char>&, const cv::Mat&)>("write", &cv::write);
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const std::basic_string<char>&, const cv::SparseMat&)>("write", &cv::write);
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const std::basic_string<char>&, const std::vector<cv::KeyPoint>&)>("write", &cv::write);
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const std::basic_string<char>&, const std::vector<cv::DMatch>&)>("write", &cv::write);
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, int)>("write_scalar", &cv::writeScalar);
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, float)>("write_scalar", &cv::writeScalar);
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, double)>("write_scalar", &cv::writeScalar);
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const std::basic_string<char>&)>("write_scalar", &cv::writeScalar);
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, int&, int)>("read", &cv::read);
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, float&, float)>("read", &cv::read);
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, double&, double)>("read", &cv::read);
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, std::basic_string<char>&, const std::basic_string<char>&)>("read", &cv::read);
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, cv::Mat&, const cv::Mat&)>("read", &cv::read);
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, cv::SparseMat&, const cv::SparseMat&)>("read", &cv::read);
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, std::vector<cv::KeyPoint>&)>("read", &cv::read);
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, std::vector<cv::DMatch>&)>("read", &cv::read);
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, cv::KeyPoint&, const cv::KeyPoint&)>("read", &cv::read);
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, cv::DMatch&, const cv::DMatch&)>("read", &cv::read);
  
  rb_mCv.define_module_function<cv::FileStorage&(*)(cv::FileStorage&, const std::basic_string<char>&)>("operator<<", &cv::operator<<);
  
  Module rb_mCvInternal = define_module_under(rb_mCv, "Internal");
  
  Class rb_cCvInternalWriteStructContext = define_class_under<cv::internal::WriteStructContext>(rb_mCvInternal, "WriteStructContext").
    define_constructor(Constructor<cv::internal::WriteStructContext, cv::FileStorage&, const std::basic_string<char>&, int, const std::basic_string<char>&>());
  
  rb_mCv.define_module_function<bool(*)(const cv::FileNodeIterator&, const cv::FileNodeIterator&)>("operator==", &cv::operator==);
  
  rb_mCv.define_module_function<bool(*)(const cv::FileNodeIterator&, const cv::FileNodeIterator&)>("operator!=", &cv::operator!=);
}