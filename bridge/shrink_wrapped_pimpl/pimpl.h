// pimpl.h

#include <memory>

// library classes start with simple letter
template <typename T> 
class pimpl
{
private:
  std::unique_ptr<T> impl;
public:
  pimpl();
  ~pimpl();

  template <typename ...Args> pimpl
    (Args&& ...args);

  T* operator->();
  T& operator*();
};

template<typename T>
pimpl<T>::pimpl() : impl{new T{}}
{}

template<typename T>
pimpl<T>::~pimpl()
{}

template<typename T>
template<typename... Args>
pimpl<T>::pimpl(Args &&... args)
  :impl{ new T{std::forward<Args>(args)... }}
{
}

template<typename T>
T *pimpl<T>::operator->()
{
  return impl.get();
}

template<typename T>
T &pimpl<T>::operator*()
{
  return *impl.get();
}



