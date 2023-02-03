#pragma once
#include <Windows.h>
#include <sstream>
#include <fstream>
#include <string>
#include <memory>
#include <unordered_map>
#include <vector>

#define A( s ) #s
#define OPTION(type, var, val) Var<type> var = {A(var), val}

template <typename T = bool>
class Var 
{
public:
	Var(std::string name, T v) : name(name) 
	{
		value = std::make_shared<T>(v);
		size = sizeof(T);
	}

	operator T() { return *value; }
	operator T* () { return &*value; }
	operator T() const { return *value; }
	//operator T*() const { return value; }

	std::string name;
	std::shared_ptr<T> value;
	int32_t size;
};

class config
{
public:
	OPTION(bool, bunnyHop, false);
	OPTION(bool, watermark, true);
	OPTION(bool, removeScope, false);

	OPTION(bool, disableKeyboardInputWhenMenuIsOn, false);
};
inline config cfg;

namespace configSystem
{
	void Save();
	void Load();

	inline std::string configName;
}