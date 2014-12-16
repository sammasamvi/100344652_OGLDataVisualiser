#ifndef TEXT_FILE_READER_H
#define TEXT_FILE_READER_H

#include <stdio.h>
#include "enums\eFileState.h"

class text_file_reader
{
private:
	char*      _current_line;
	long       _current_line_number;
	FILE*      _file;
	char*      _file_extension;
	char*      _file_path;
	eFileState _file_state;
	long       _line_count;

protected:
	void calc_line_count();
	void set_file_extension();

public:
	text_file_reader();
	~text_file_reader();

	virtual void     close_file();
	const char*      get_current_line();
	const long*      get_current_line_number();
	const FILE*      get_file();
	const char*      get_file_extension();
	const char*      get_file_path();
	const eFileState get_file_state();
	const long*      get_line_count();
	virtual void     open_file();
	const char*      read_first_line();
	const char*      read_last_line();
	const char*      read_line(long position);
	const char*      read_next_line();
	void             reset_lines_read();
	virtual void     set_file_path(char* file_path);
	virtual void     set_file_path(wchar_t* file_path);
};

#endif