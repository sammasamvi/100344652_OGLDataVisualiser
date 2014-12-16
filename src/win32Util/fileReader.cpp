#define _CRT_SECURE_NO_WARNINGS // ENABLE USE OF POTENTIALLY DANGEROUS BUFFERS FUNCTIONS

#include "fileReader.h"
#include <stdlib.h>

#define arraySize 8192

fileReader::fileReader()
{
	_current_line        = new char[arraySize];
	_file                = nullptr;
	_file_path           = nullptr;
	_line_count          = 0;
	_current_line_number = 0;
}

fileReader::~fileReader()
{
	if (_file)
		close_file();

	delete _current_line;

	_current_line = nullptr;
	_file_path    = nullptr;
	
}

void fileReader::close_file()
{
	if (_file)
		close_file();

    _file                = nullptr;
    _line_count          = 0;
	_current_line_number = 0;
}

const FILE* fileReader::get_file()
{
	return _file;
}

const char* fileReader::get_file_path()
{
	return _file_path;
}

const long* fileReader::get_line_count()
{
	return &_line_count;
}

const char* fileReader::get_current_line()
{
	return _current_line;
}

const long* fileReader::get_current_line_number()
{
	return &_current_line_number;
}

void fileReader::open_file()
{
	_line_count = 0;

	if (_file)
		close_file();

	if (_file_path)
	{
		if ((_file = fopen(_file_path, "r")))
			calc_line_count();
	}
}

const char* fileReader::read_first_line()
{
	return read_line(1);
}

const char* fileReader::read_last_line()
{
	return read_line(_line_count);
}

const char* fileReader::read_line(long position)
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

const char* fileReader::read_next_line()
{
	_current_line_number++;

	return fgets(_current_line, arraySize, _file);
}

void fileReader::reset_lines_read()
{
	rewind(_file);

	_current_line_number = 0;
}

void fileReader::set_file_path(char* file_path)
{
	_file_path = file_path;
}

void fileReader::calc_line_count()
{
	while (fgets(_current_line, arraySize, _file))
	{
		_line_count++;
	}

	rewind(_file);
}
