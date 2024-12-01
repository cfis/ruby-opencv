#include <rice/rice.hpp>
#include <rice/stl.hpp>

#include <opencv2/core/cvstd_wrapper.hpp>

void Init_CvstdWrapper();

namespace Rice::detail
{
  template <typename T>
  class To_Ruby<cv::Ptr<T>>
  {
  public:
    VALUE convert(cv::Ptr<T>& data)
    {
      using Wrapper_T = WrapperSmartPointer<cv::Ptr, T>;
      std::pair<VALUE, rb_data_type_t*> rubyTypeInfo = detail::Registries::instance.types.figureType<T>(*data);
      return detail::wrap<cv::Ptr<T>, Wrapper_T>(rubyTypeInfo.first, rubyTypeInfo.second, data, true);
    }

    VALUE convert(const cv::Ptr<T>& data)
    {
      using Wrapper_T = WrapperSmartPointer<const cv::Ptr, T>;
      std::pair<VALUE, rb_data_type_t*> rubyTypeInfo = detail::Registries::instance.types.figureType<T>(*data);
      return detail::wrap<const cv::Ptr<T>, Wrapper_T>(rubyTypeInfo.first, rubyTypeInfo.second, data, true);
    }
  };

  template <>
  class To_Ruby<cv::Ptr<void>>
  {
  public:
    using Wrapper_T = WrapperSmartPointer<cv::Ptr, void>;

    VALUE convert(cv::Ptr<void>& data)
    {
      std::pair<VALUE, rb_data_type_t*> rubyTypeInfo = detail::Registries::instance.types.figureType(data.get());
      return detail::wrap<cv::Ptr<void>, Wrapper_T>(rubyTypeInfo.first, rubyTypeInfo.second, data, true);
    }
  };

  template <typename T>
  class From_Ruby<cv::Ptr<T>>
  {
  public:
    using Wrapper_T = WrapperSmartPointer<cv::Ptr, T>;

    From_Ruby() = default;

    explicit From_Ruby(Arg* arg) : arg_(arg)
    {
    }

    Wrapper_T* is_same_smart_ptr(VALUE value)
    {
      Wrapper* wrapper = detail::getWrapper(value, Data_Type<T>::ruby_data_type());
      return dynamic_cast<Wrapper_T*>(wrapper);
    }

    Convertible is_convertible(VALUE value)
    {
      if (!is_same_smart_ptr(value))
        return Convertible::None;

      switch (rb_type(value))
      {
        case RUBY_T_DATA:
          return Convertible::Exact;
          break;
        default:
          return Convertible::None;
      }
    }

    cv::Ptr<T> convert(VALUE value)
    {
      if (value == Qnil && this->arg_ && this->arg_->hasDefaultValue()) {
        return this->arg_->template defaultValue<cv::Ptr<T>>();
      }

      Wrapper_T* smartWrapper = is_same_smart_ptr(value);
      if (!smartWrapper)
      {
        std::string message = "Invalid smart pointer wrapper";
        throw std::runtime_error(message.c_str());
      }
      return smartWrapper->data();
    }
  private:
    Arg* arg_ = nullptr;
  };

  template <typename T>
  class To_Ruby<cv::Ptr<T>&>
  {
  public:
    using Wrapper_T = WrapperSmartPointer<cv::Ptr, T>;

    VALUE convert(cv::Ptr<T>& data)
    {
      std::pair<VALUE, rb_data_type_t*> rubyTypeInfo = detail::Registries::instance.types.figureType<T>(*data);
      return detail::wrap<cv::Ptr<T>, Wrapper_T>(rubyTypeInfo.first, rubyTypeInfo.second, data, true);
    }

    VALUE convert(const cv::Ptr<T>& data)
    {
      std::pair<VALUE, rb_data_type_t*> rubyTypeInfo = detail::Registries::instance.types.figureType<T>(*data);
      return detail::wrap<cv::Ptr<T>, Wrapper_T>(rubyTypeInfo.first, rubyTypeInfo.second, data, true);
    }
  };

  template <typename T>
  class From_Ruby<cv::Ptr<T>&>
  {
  public:
    using Wrapper_T = WrapperSmartPointer<cv::Ptr, T>;

    From_Ruby() = default;

    explicit From_Ruby(Arg* arg) : arg_(arg)
    {
    }

    Wrapper_T* is_same_smart_ptr(VALUE value)
    {
      Wrapper* wrapper = detail::getWrapper(value, Data_Type<T>::ruby_data_type());
      return dynamic_cast<Wrapper_T*>(wrapper);
    }

    Convertible is_convertible(VALUE value)
    {
      if (!is_same_smart_ptr(value))
        return Convertible::None;

      switch (rb_type(value))
      {
        case RUBY_T_DATA:
          return Convertible::Exact;
          break;
        default:
          return Convertible::None;
      }
    }

    cv::Ptr<T>& convert(VALUE value)
    {
      if (value == Qnil && this->arg_ && this->arg_->hasDefaultValue()) {
        return this->arg_->template defaultValue<cv::Ptr<T>>();
      }

      Wrapper_T* smartWrapper = is_same_smart_ptr(value);
      if (!smartWrapper)
      {
        std::string message = "Invalid smart pointer wrapper";
        throw std::runtime_error(message.c_str());
      }
      return smartWrapper->data();
    }

  private:
    Arg* arg_ = nullptr;
  };

  template<typename T>
  struct Type<cv::Ptr<T>>
  {
    static bool verify()
    {
      return Type<T>::verify();
    }
  };
}
