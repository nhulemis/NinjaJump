#pragma once

template <typename T>
class Singleton
{
public:
	static T*		GetInstance();
	void			Destroy();
private:
	static T*		s_instance;
};

template <class T>
T * Singleton<T>::s_instance = 0;

template<typename T>
T * Singleton<T>::GetInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new T();
	}
	return s_instance;
}

template<typename T>
inline void Singleton<T>::Destroy()
{
	delete s_instance;
}
