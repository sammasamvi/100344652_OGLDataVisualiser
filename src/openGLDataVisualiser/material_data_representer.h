#ifndef MATERIAL_DATA_REPRESENTER_H
#define MATERIAL_DATA_REPRESENTER_H

#include "..\openGLCore\material_renderable.h"
#include <string>

class material_data_representer final
{
    private:
		material_renderable* _key;
		const std::string*   _name;
		material_renderable* _representer;
    
    public:
		material_data_representer(material_renderable* key, const std::string& name, material_renderable* representer);
		~material_data_representer();

		material_renderable* get_key()         const;
		std::string          get_name()        const;
		material_renderable* get_representer() const;
};

#endif