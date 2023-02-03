#include "config.h"
#include "../utilities.h"

void configSystem::Save()
{
	std::ofstream fout(configName.c_str(), std::ios::binary);
	const auto sz = sizeof(config);
	const auto var_sz = sizeof(Var<bool>);
	const auto cnt = sz / var_sz;

	for (auto i = 0; i < cnt; i++) 
	{
		const auto el = &(*(Var<int>*)(&cfg)) + i;
		auto name = el->name;
		auto val = el->value;
		auto sizeof_val = el->size;
		fout << name << "\t" << utils::BytesToString((unsigned char*)*(int*)&val, sizeof_val) << std::endl;
	}

	fout.close();
}

void configSystem::Load()
{
	std::ifstream fin(configName.c_str(), std::ios::binary);
	std::stringstream ss;
	ss << fin.rdbuf();

	auto lines = utils::Split(ss.str(), "\n");

	for (auto line : lines) 
	{
		auto data = utils::Split(line, "\t");
		const auto sz = sizeof(config);
		const auto var_sz = sizeof(Var<bool>);
		const auto cnt = sz / var_sz;

		for (auto i = 0; i < cnt; i++)
		{
			const auto& el = &(*(Var<bool>*)(&cfg)) + i;

			if (data[0] == el->name) 
			{
				auto bytes = utils::HexToBytes(data[1]);
				memcpy(*(void**)&el->value, bytes.data(), el->size);
			}
		}
	}

	fin.close();
}
