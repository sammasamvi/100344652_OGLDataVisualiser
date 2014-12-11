#include "material_data_representer.h"

material_data_representer::material_data_representer(material_renderable* key, const std::string& name, material_renderable* representer)
{
	_key         = key;
	_name        = &name;
	_representer = representer;
}

material_data_representer::~material_data_representer()
{
	if (_key)
		delete _key;

	if (_name)
		delete _name;

	if (_representer)
		delete _representer;
}

material_renderable* material_data_representer::get_key() const
{
	return _key;
}

std::string material_data_representer::get_name() const
{
	return *_name;
}

material_renderable* material_data_representer::get_representer() const
{
	return _representer;
}