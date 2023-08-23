# Data Structures and Algorithms

Expounding on Data Structures and algorithms


## Working with CMakeLists.txt
The basic structure of Cmake project Looks as follows:

```
Project_directory/
---- CMakeLists.txt
---- src/
-------- CMakeLists.txt
-------- source_file_1.cpp
-------- source_file_2.cpp
-------- ...
---- include/
-------- header_file_1.h
-------- header_file_2.h
-------- ...
---- build/
-------- CMakeCache.txt
-------- MakeFile
-------- ...
```

The high-level structure of a CMakeLists.txt file would be as follows:
```
cmake_minimum_required(VERSION <minimum_required_version>)
project(<project_name>)

# Add source files to the project
add_executable(<executable_name> <source_file_1> <source_file_2> ...)

# Set any additional compiler flags or options
# For example:
# target_compile_options(<executable_name> PRIVATE -Wall -Wextra)

# Link any necessary libraries
# For example:
# target_link_libraries(<executable_name> <library_name>)
```

Let's say fo example that we have the folowing folder structure
```
Parent_Folder
---- Child_1_Folder
-------- Child_1.cpp
-------- Child_1.hpp
-------- CMakeLists.txt
---- Child_2_Folder
-------- Child_2.cpp
-------- Child_2.hpp
-------- CMakeLists.txt
---- CMakeLists.txt
```

To configure the CMakeLists.txt files in the parent and child folders, you can use the `add_subdirectory` command in the parent CMakeLists.txt file.

Here's an example of how you can set it up:

```cmake
cmake_minimum_required(VERSION <minimum_required_version>)
project(<project_name>)

# Add child directories
add_subdirectory(Child_1_Folder)
add_subdirectory(Child_2_Folder)

# Add any other configurations or targets
```

In the Child_1_Folder/CMakeLists.txt:
```cmake
# Add source files to the child project
add_library(Child_1_lib <Child_1.cpp> <Child_1.hpp>)

# Add any other configurations or targets specific to Child_1_Folder
```

In the Child_2_Folder/CMakeLists.txt:
```cmake
# Add source files to the child project
add_library(Child_2_lib <Child_2.cpp> <Child_2.hpp>)

# Add any other configurations or targets specific to Child_2_Folder
```
## Working with Header Files
The good practice to work with the header files is to start with your own header files, the external libraries header files, then after that you use the standard library header files e.g.

```
#include "folder_1/your_file_1.h"
#include "folder_2/your_file_2.h"

#include <external/lib_file.h>
#include <external/other_file.h>

#include <string>
#include <vector>
```