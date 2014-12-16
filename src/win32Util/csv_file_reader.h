#ifndef CSV_FILE_READER_H
#define CSV_FILE_READER_H

#include "text_file_reader.h"
#include <string>

class csv_file_reader final : public text_file_reader
{
private:
	char*        _attribute_types;
	long         _attribute_count;
	std::string* _attrubute_names;
	void**       _sample_arrays;
	const long*  _sample_size;
	char*        _seperator;

	/*
	[TYPE]: void
	[USE]: extracts the individual values from the given line [src_all_attributes] within the csv file storing them in the [dest_array].
	[ERR]: memory access violation raised if dest array is not larg enough to store all values from line.
	*/
	void assign_attributes(const std::string& src_all_attributes, std::string* dest_array);

	/*
	[TYPE]: void
	[USE]: resets all values, frees all allocated memory.
	[ERR]: NULL
	*/
	void clear_state();

	/*
	[TYPE]: void
	[USE]: creates arrays of the propper type for the csv attribute it will store, allocates the memory for the arrays.
	[ERR]: NULL
	*/
	void create_typed_arrays();

	/*
	[TYPE]: void
	[USE]: allocates the memory for the [_attrubute_names] [_sample_arrays] [_attribute_types] arrays, sets the contents of the [_attrubute_names] array.
	[ERR]: NULL
	*/
	bool init_arrays();

	/*
	[TYPE]: char
	[USE]: returns i, d, or s, representing intager, double or string respectively depending on the contents of the input string.
	[ERR]: NULL
	*/
	char get_type(const std::string& str);

	/*
	[TYPE]: void
	[USE]: fills the arrays pointed to by [_sample_arrays] with the contents of the csv file.
	[ERR]:
	*/
	void populate_arrays();

	/*
	[TYPE]: void
	[USE]: perform re-set of class state information if needed before file path set.
	[ERR]:
	*/
	void prep_set_file_path();

	/*
	[TYPE]: void
	[USE]: takes in a sepperator (e.g. , or ;) reads the first line of the csv file and determines the number of attributes.
	[ERR]: NULL
	*/
	void set_attribute_count(const char seperator);

public:
	csv_file_reader();
	~csv_file_reader();

	/*
	[TYPE]: void
	[USE]: closes the currently attached file, resets all get_* values, releases any allocated memory.
	[ERR]: NULL
	*/
	void close_file();

	/*
	[TYPE]: long
	[USE]: returns the number of attributes (a.k.a collum headers) in the csv file.
	[ERR]: NULL
	*/
	const long get_attribute_count();

	/*
	[TYPE]: string[]
	[USE]: returns an array of the attribute (a.k.a collum headers) names.
	[ERR]: NULL
	*/
	const std::string* get_attribute_names();

	/*
	[TYPE]: long
	[USE]: returns the number of samples contained in the csv file.
	[ERR]: NULL
	*/
	const long get_sample_size();

	/*
	[TYPE]: void
	[USE]: opens and loads the contents of the csv file set by the set_file_path(char* file_path) method.
	[ERR]: NULL
	*/
	void open_file();

	/*
	[TYPE]: void
	[USE]: sets the file path variable
	[ERR]: NULL
	*/
	void set_file_path(char* file_path);


	/*
	[TYPE]: void
	[USE]: sets the file path variable
	[ERR]: NULL
	*/
	void set_file_path(wchar_t* file_path);
};

#endif