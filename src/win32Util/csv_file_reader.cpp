#include "csv_file_reader.h"

csv_file_reader::csv_file_reader()
{
	_attribute_types = nullptr;
	_attribute_count = 0;
	_attrubute_names = nullptr;
	_sample_arrays   = nullptr;
	_sample_size     = get_line_count();
	_seperator       = nullptr;
}

csv_file_reader::~csv_file_reader()
{
	if (get_file_state() != Closed)
		close_file();

	_sample_size = nullptr;
}

void csv_file_reader::assign_attributes(const std::string& src_all_attributes, std::string* dest_array)
{
	short buffer_pos     = 0;
	long  dest_array_pos = 0;

	char buffer_array[64];
	memset(buffer_array, '\0', 64);

	for (size_t i = 0; i < src_all_attributes.length(); i++)
	{
		if (src_all_attributes[i] == *_seperator || i == (src_all_attributes.length() - 1))
		{
			dest_array[dest_array_pos] = std::string(buffer_array);

			dest_array_pos++;
			memset(buffer_array, '\0', 64);
			buffer_pos = 0;
		}
		else
		{
			buffer_array[buffer_pos] = src_all_attributes[i];
			buffer_pos++;
		}
	}
}

void csv_file_reader::close_file()
{
	clear_state();
	text_file_reader::close_file();
}

void csv_file_reader::clear_state()
{
	if (_attrubute_names)
	{
		delete[] _attrubute_names;
		_attrubute_names = nullptr;
	}

	if (_sample_arrays)
	{
		for (long i = 0; i < _attribute_count; i++)
		{
			if (_attribute_types[i] == 's')
			{
				delete[] (std::string*)_sample_arrays[i];
			}
			else
			{
				free(_sample_arrays[i]);
			}
		}
		
		free(_sample_arrays);
		_sample_arrays = nullptr;
	}

	if (_attribute_types)
	{
		free(_attribute_types);
		_attribute_types = nullptr;
	}

	if (_seperator)
	{
		free(_seperator);
		_seperator = nullptr;
	}

	_attribute_count = 0;
}

void csv_file_reader::create_typed_arrays()
{
	std::string  all_attrubues_from_sample = read_line(2);
	std::string* attribute_values          = new std::string[_attribute_count];

	assign_attributes(all_attrubues_from_sample, attribute_values);

	for (int i = 0; i < _attribute_count; i++)
	{
		_attribute_types[i] = get_type(attribute_values[i]);

		switch (_attribute_types[i])
		{
		case 's':
			_sample_arrays[i] = new std::string[*_sample_size];
			break;

		case 'i':
			_sample_arrays[i] = malloc((*_sample_size) * sizeof(int));
			break;

		case 'd':
			_sample_arrays[i] = malloc((*_sample_size) * sizeof(double));
			break;

		default:
			_sample_arrays[i] = nullptr;
			break;
		}
	}
}

const long csv_file_reader::get_attribute_count()
{
	return _attribute_count;
}

const std::string* csv_file_reader::get_attribute_names()
{
	return _attrubute_names;
}

const long csv_file_reader::get_sample_size()
{
	return *_sample_size;
}

bool csv_file_reader::init_arrays()
{
	set_attribute_count(',');

	if (!_seperator)
	{
		_attribute_count = 0;
		set_attribute_count(';');
	}

	if (_attribute_count > 0 && _seperator)
	{
		_attrubute_names = new std::string[_attribute_count];
		_sample_arrays   = (void**)malloc(_attribute_count * sizeof(void*));
		_attribute_types = (char*)malloc(_attribute_count * sizeof(char));

		assign_attributes(read_line(1), _attrubute_names);
	}
	else
	{
		return false;
	}

	create_typed_arrays();

	return true;
}

/*
	[MODIFED EXAMPLE]

	Taken form       : http://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int
	Viewed on        : 07/12/2014
	Submited by user : paercebal
*/
char csv_file_reader::get_type(const std::string& str)
{
	if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+')))
		return 's';

	char*       ptr   = nullptr;
	const char* c_str = str.c_str();
	
	strtol(c_str, &ptr, 10);
	if (*ptr == 0)
		return 'i';

	ptr = 0;
	strtod(c_str, &ptr);
	if ((*ptr == '\0') && (ptr != c_str))
		return 'd';

	return 's';
}

void csv_file_reader::open_file()
{
	clear_state();

	if (strcmp(get_file_extension(), R"(.csv)"))
		return;

	if (get_file_state() == Open)
	{
		reset_lines_read();
		calc_line_count();
	}
	else
	{
		text_file_reader::open_file();
	}
	
	if (*get_line_count() > 1)
	{
		populate_arrays();
	}
}

void csv_file_reader::populate_arrays()
{
	if (init_arrays())
	{
		std::string* sample_attribute_vals = new std::string[_attribute_count];

		for (int i = 1; i < *_sample_size; i++)
		{
			assign_attributes(read_line(i + 1), sample_attribute_vals);

			for (int x = 0; x < _attribute_count; x++)
			{
				switch (_attribute_types[x])
				{
				case 's':
					((std::string*)_sample_arrays[x])[i] = sample_attribute_vals[x];
					break;

				case 'i':
					((int*)_sample_arrays[x])[i] = strtol(sample_attribute_vals[x].c_str(), NULL, 10);
					break;

				case 'd':
					((double*)_sample_arrays[x])[i] = strtod(sample_attribute_vals[x].c_str(), NULL);
					break;
				}
			}
		}

		delete[] sample_attribute_vals;
	}
}

void csv_file_reader::prep_set_file_path()
{
	if (get_file())
	{
		clear_state();
		text_file_reader::close_file();
	}
}

void csv_file_reader::set_attribute_count(const char seperator)
{
	std::string all_attributes = read_line(1);
	long        string_length  = all_attributes.length();
	
	for (int i = 0; i < string_length; i++)
	{
		if (all_attributes[i] == seperator || i == (string_length - 1))
		{
			_attribute_count++;

			if (!(i == (string_length - 1)) && !_seperator)
			{
				_seperator  = (char*)malloc(sizeof(char));
				*_seperator = seperator;
			}
		}
	}
}

void csv_file_reader::set_file_path(char* file_path)
{
	prep_set_file_path();
	text_file_reader::set_file_path(file_path);
}

void csv_file_reader::set_file_path(wchar_t* file_path)
{
	prep_set_file_path();
	text_file_reader::set_file_path(file_path);
}