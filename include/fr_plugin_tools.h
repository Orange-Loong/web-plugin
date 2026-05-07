#ifndef _FR_PLUGIN_SDK_TOOLS_H_
#define _FR_PLUGIN_SDK_TOOLS_H_
namespace callback {
template <class C, class Type, class T,  class... Args>
void Execute(const C &vec, Type T::* f, Args &&... args) {
  for (size_t i = 0; i < vec.size(); i++) {
    auto &&elem = vec[i];
	if (elem.*f) {
		(elem.*f)(elem.clientData, std::forward<Args>(args)...);
	}
  }
}

template <class C, class Type, class T, class... Args>
bool Dispatch(const C &vec, Type T::* f, Args &&... args) {
  for (size_t i = 0; i < vec.size(); i++) {
    auto &&elem = vec[i];
	if (elem.*f) {
	  if((elem.*f)(elem.clientData, std::forward<Args>(args)...))
		return true;
	}
  }
  return false;
} // namespace callback

template <class C, class Type, class T, class... Args>
bool Check(const C &vec, Type T::* f, Args &&... args) {
  for (size_t i = 0; i < vec.size(); i++) {
    auto &&elem = vec[i];
	if (elem.*f) {
	  if (!(elem.*f)(elem.clientData, std::forward<Args>(args)...))
	    return false;
	}
  }
  return true;
}

template <class T>
void copy(T& dst, const T&src) {
	memcpy(&dst, &src, src.lStructSize);
	if (src.lStructSize < sizeof(T)) {
		char *pAddress = (char *)&dst;
		memset(pAddress + src.lStructSize, 0,
			sizeof(T) - src.lStructSize);
	}
}

template <class T> class Manager : public std::vector<T> {
public:
  using _MyBase = std::vector<T>;
  Manager() = default;
  ~Manager() = default;
  Manager(const Manager &) = delete;
  Manager &operator=(const Manager &) = delete;
  Manager(Manager &&) = default;
  Manager &operator=(Manager &&) = default;

  bool Register(const T *pCallbacks) {
    if (!pCallbacks)
      return false;
	_MyBase::emplace_back();
	copy<T>(_MyBase::back(), *pCallbacks);
    return true;
  }

  const T *GetAt(int index) const { return &_MyBase::at(index); }

  void RemoveAt(int index) { _MyBase::erase(_MyBase::begin() + index); }

  int GetSize() const { return _MyBase::size(); }

  template <class Type, class... Args> void Execute(Type f, Args &&... args) {
    return callback::Execute(*this, f, std::forward<Args>(args)...);
  }

  template <class Type, class... Args> bool Dispatch(Type f, Args &&... args) {
    return callback::Dispatch(*this, f, std::forward<Args>(args)...);
  }

  template <class Type, class... Args> bool Check(Type f, Args &&... args) {
    return callback::Check(*this, f, std::forward<Args>(args)...);
  }

  template <class Finder,
            std::enable_if_t<!std::is_convertible_v<Finder, T>, int> = 0>
  void Unregister(const Finder &finder, bool just_unregister_first = true) {
    for (auto it = _MyBase::begin(); it != _MyBase::end();) {
      if (finder(*it)) {
        it = _MyBase::erase(it);
        if (just_unregister_first)
          return;
      } else {
        it++;
      }
    }
  }
};
} // namespace callback

#endif