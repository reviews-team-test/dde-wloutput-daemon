cmake_minimum_required(VERSION 3.7)

set(CMAKE_AUTOMOC ON)

FOREACH (this_dir 
			src
			test
	)
	ADD_SUBDIRECTORY (${this_dir})
ENDFOREACH (this_dir)
