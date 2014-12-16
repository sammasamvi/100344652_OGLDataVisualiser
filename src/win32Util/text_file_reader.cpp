#define _CRT_SECURE_NO_WARNINGS // ENABLE USE OF POTENTIALLY DANGEROUS BUFFERS FUNCTIONS

#include "text_file_reader.h"
#include <clocale>
#include <cstdlib>
#include <cstring>

#define _CURRENT_LINE_MAX_LENGTH 2048
#define _FILE_PATH_MAX_LENGTH    (_MAX_PATH + 1)

text_file_reader::text_file_reader()
{
	_current_line        = new char[_CURRENT_LINE_MAX_LENGTH]();
	_file                = nullptr;
	_file_extension      = nullptr;
	_file_path           = new char[_FILE_PATH_MAX_LENGTH]();
	_file_state          = Invalid;
	_line_count          = 0;
	_current_line_number = 0;
}

text_file_reader::~text_file_reader()
{
	if (_file)
		close_file();

	delete[] _current_line;
	
	if (_file_extension)
		delete[] _file_extension;
	
	delete[] _file_path;
	

	_current_line = nullptr;
	_file_path    = nullptr;
	_file_state   = Invalid;
}

void text_file_reader::calc_line_count()
{
	while (fgets(_current_line, _CURRENT_LINE_MAX_LENGTH, _file))
	{
		_line_count++;
	}

	rewind(_file);
}

void text_file_reader::close_file()
{
    fclose(_file);
	memset(_current_line,   '\0', _CURRENT_LINE_MAX_LENGTH);

	_current_line_number = 0;
	_line_count          = 0;
	_file                = nullptr;
	_file_state          = Closed;
}

const char* text_file_reader::get_current_line()
{
	return _current_line;
}

const long* text_file_reader::get_current_line_number()
{
	return &_current_line_number;
}

const FILE* text_file_reader::get_file()
{
	return _file;
}

const char* text_file_reader::get_file_path()
{
	return _file_path;
}

const char* text_file_reader::get_file_extension()
{
	return _file_extension;
}

const eFileState text_file_reader::get_file_state()
{
	return _file_state;
}

const long* text_file_reader::get_line_count()
{
	return &_line_count;
}

void text_file_reader::open_file()
{
	if (_file_state == Closed)
	{
		if ((_file = fopen(_file_path, "r")))
			calc_line_count();
	    
	    _file_state = Open;
	}
}

const char* text_file_reader::read_first_line()
{
	return read_line(1);
}

const char* text_file_reader::read_last_line()
{
	return read_line(_line_count);
}

const char* text_file_reader::read_line(long position)
{
	if (position <= 0 || position > _line_count)
	{
		return nullptr;
	}

	long start_point = 0;
	
	if (position == _current_line_number)
	{
		return _current_line;
	}
	
	if (position < _current_line_number)
	{
		reset_lines_read();
	}

	while (_current_line_number != position)
	{
		read_next_line();
	}

	return _current_line;
}

const char* text_file_reader::read_next_line()
{
	_current_line_number++;

	return fgets(_current_line, _CURRENT_LINE_MAX_LENGTH, _file);
}

void text_file_reader::reset_lines_read()
{
	rewind(_file);

	_current_line_number = 0;
}

void text_file_reader::set_file_extension()
{
	for (int i = 0; i < _MAX_PATH; i++)
	{
		if (_file_path[i] == '.')
		{
			_file_extension = new char[_MAX_PATH - i];
			
			int _file_extension_index = 0;
			for (int x = i; x < _MAX_PATH; x++)
			{
				_file_extension[_file_extension_index] = _file_path[x];
				_file_extension_index++;
			}
		}
	}
}

void text_file_reader::set_file_path(char* file_path)
{
	if (!strcmp(_file_path, file_path))
	{
		memset(_file_path, '\0', _FILE_PATH_MAX_LENGTH);
		_file_path = file_path;
		set_file_extension();

		_file_state = Closed;
	}
}

void text_file_reader::set_file_path(wchar_t* file_path)
{
	// consider fetching locale from system
	setlocale(LC_ALL, "en_US.utf8");
	memset(_file_path, '\0', _FILE_PATH_MAX_LENGTH);
	wcstombs(_file_path, file_path, _FILE_PATH_MAX_LENGTH);
	set_file_extension();

	_file_state = Closed;
}