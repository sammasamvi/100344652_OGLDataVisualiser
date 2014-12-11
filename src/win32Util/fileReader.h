#ifndef FILE_READER_H
#define FILE_READER_H

#include <stdio.h>

class fileReader
{
    private:
        char* _current_line;
        FILE* _file;
        char* _file_path;
        long  _line_count;
		long  _current_line_number;
        
    protected:
		void calc_line_count();

    public:
        fileReader();
        ~fileReader();
        
        virtual void close_file();
        const FILE*  get_file();
        const char*  get_file_path();
        const long*  get_line_count();
		const char*  get_current_line();
        const long*  get_current_line_number();
        virtual void open_file();
		const char*  read_first_line();
		const char*  read_last_line();
		const char*  read_line(long position);
		const char*  read_next_line();
        void         reset_lines_read();
		virtual void set_file_path(char* file_path);
};

#endif