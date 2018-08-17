# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`define `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)            | If defined, funstions will be marked as inline.
`namespace `[`ai`](#de/d58/namespaceai) | Main namespace.

## Members

#### `define `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116) 

If defined, funstions will be marked as inline.

If defined, funstions will be marked as inline. Delete the line, if you want to omit this behavior.

# namespace `ai` 

Main namespace.

Main namespace containing all the functions of AiLibrary

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`getVersion`](#d5/dd6/group___library_info_1gae81b57260fe20a158b0226ca9b51610e)`()`            | Gets version of the lib.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`string`](#d4/d65/group___string_functions_1gac77e5243b1f905e34f4e34214ebc0d47)`(const T value)`            | Converts input into a string.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`hasPrefix`](#d4/d65/group___string_functions_1gae7d7fb0e302e9de48a24b1134149f2eb)`(const std::string & text,const std::string & prefix)`            | Checks if a string begins with a substring.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`hasSuffix`](#d4/d65/group___string_functions_1ga5ffb87ef7304cf15de933db0ef8dbb5a)`(const std::string & text,const std::string & suffix)`            | Checks if a string ends with a substring.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`contains`](#d4/d65/group___string_functions_1ga1a7fafa4ef8edd8b49b461840ca42dd6)`(const std::string & text,const std::string & substring)`            | Checks if a string contains a substring.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`replace`](#d4/d65/group___string_functions_1gaa3ee3ad75450b355f177173739343c01)`(std::string text,const std::string & substring,const std::string & replacement)`            | Replaces all occurrences of a substring in a copy of the initial string with your text.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`applyReplace`](#d4/d65/group___string_functions_1ga716112bcf505ef4c86f65619afe573a5)`(std::string & text,const std::string & substring,const std::string & replacement)`            | Modifies your string by replacing all occurrences of a substring string with your text.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`equal`](#d4/d65/group___string_functions_1gab125482b04497d2b9d7880cdfd51ccff)`(const char * charString,const std::string string1)`            | Checks if a char string is equal to a std::string.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::size_t `[`counter`](#d3/ddf/group___debug_functions_1gae14b2a823a0d4558fd7c3213ff4d3509)`(std::size_t value)`            | Returns ID starting from zero or the specified value.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`marker`](#d3/ddf/group___debug_functions_1ga96824e55a873b5474316326942066d7c)`(std::size_t value)`            | Returns a string containing the word "Marker" and its ID.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printMarker`](#d3/ddf/group___debug_functions_1ga4f74ef7895220dc9aba06fb6eab6073b)`(std::size_t value)`            | Calls [marker()](#d3/ddf/group___debug_functions_1ga96824e55a873b5474316326942066d7c) and prints result to stdout.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`sign`](#d5/d12/group___math_functions_1ga59e445549490377e66c6c2719b65cc0e)`(const T value)`            | Returns signum of the value.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`min`](#d5/d12/group___math_functions_1ga4ff9e753d095c1ca70b0ec517b0c919e)`(const T a,const T b)`            | Returns minimum of two values.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`max`](#d5/d12/group___math_functions_1gab4363f54de7131a1530189fdfb614334)`(const T a,const T b)`            | Returns maximum of two values.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`min`](#d5/d12/group___math_functions_1gab855a677ddeab67056d5316bc95ef683)`(const std::vector< T > & input)`            | Returns minimum of vector values.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`max`](#d5/d12/group___math_functions_1ga38d9271ac8875ee2e73f7393e791ad55)`(const std::vector< T > & input)`            | Returns maximum of vector values.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`min`](#d5/d12/group___math_functions_1gad56ff7c2618a4cb19a5b451663b42394)`(const std::vector< std::vector< T > > & input)`            | Returns minimum of matrix values.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`max`](#d5/d12/group___math_functions_1gac41228d2f55e89ea0cbf721d8ee076ff)`(const std::vector< std::vector< T > > & input)`            | Returns maximum of matrix values.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`isSquare`](#d5/d12/group___math_functions_1gac521d17c2aff565fbc375f2f9c611dcd)`(const T value)`            | Checks if number is square.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`isSquare`](#d5/d12/group___math_functions_1gaba5e6609f9c8fd769ce6d66d46159b2b)`(const std::vector< std::vector< T > > matrix)`            | Checks if matrix is square.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`generateRandomVector`](#d5/d12/group___math_functions_1ga2cf03512823864f49bb5255c97d40ed7)`(std::vector< T > & vector,const std::size_t length,const T min,const T max)`            | > Todo: Add description. Add tests. Check for real or int
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`generateRandomMatrix`](#d5/d12/group___math_functions_1gad7c9b6127798888b827519f713380b65)`(std::vector< std::vector< T > > & matrix,const std::size_t xSize,const std::size_t ySize,const T min,const T max)`            | > Todo: Add description. Add tests
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`generateRandomMatrix`](#d5/d12/group___math_functions_1gaf32c64e29eaa5688f7d84800d780ff2e)`(std::vector< T > & vector,const std::size_t size,const T min,const T max)`            | > Todo: Add description. Add tests
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`translateMatrixIntoVector`](#d5/d12/group___math_functions_1ga277c02074c8e0dc2c4ef67b8bc2371ce)`(std::vector< std::vector< T > > & matrix,std::vector< T > & vector)`            | Elongates matrix into a vector.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`translateVectorIntoSquareMatrix`](#d5/d12/group___math_functions_1ga43c134aa8eab9d5edb498016ee891646)`(std::vector< T > & vector,std::vector< std::vector< T > > & matrix)`            | Transform vector in a square matrix (if possible)
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::chrono::high_resolution_clock::time_point `[`time`](#dd/dd0/group___time_functions_1ga54195a75b5598d4078f9f4cc57628f2b)`()`            | Returns current time point.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` double `[`duration`](#dd/dd0/group___time_functions_1ga912fcdb43dab89156260759a2fc128d6)`(const std::chrono::high_resolution_clock::time_point start,const std::chrono::high_resolution_clock::time_point finish,const std::string scale)`            | Returns the difference between two time points.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`parseParameter`](#df/dab/group___parameter_functions_1ga2d54d56130ff4b251fd09a33c307d924)`(const char * input,const std::string name)`            | > Todo: Add description. Add tests
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`assignFromVectorByIntervalCondition`](#df/dab/group___parameter_functions_1ga4de411233451db390ce475f2f3916962)`(T & value,const T parameter,const std::vector< std::vector< T > > intervals)`            | > Todo: Add description. Add tests
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`assignFromVectorByIntervalCondition`](#df/dab/group___parameter_functions_1ga59fc20819b5d0024c784c62bb75bb6b4)`(T & firstValue,T & secondValue,const T parameter,const std::vector< std::vector< T > > intervals)`            | > Todo: Add description. Add tests
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignBooleanParameter`](#df/dab/group___parameter_functions_1gaf22400542606a991705af80aacd216e7)`(const char * input,const std::string name,bool & value)`            | > Todo: Add description. Add tests
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignCharParameter`](#df/dab/group___parameter_functions_1ga02eb74222c6c05c9ef731358f3afcc70)`(const char * input,const std::string name,char & value)`            | > Todo: Add description. Add tests
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignStringParameter`](#df/dab/group___parameter_functions_1ga66fb81eb3a9d18a05eebf2188ebfa7d1)`(const char * input,const std::string name,std::string & value)`            | > Todo: Add description. Add tests
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignParameter`](#df/dab/group___parameter_functions_1ga39965300f2ee700f23af9cfb984a4dab)`(const char * input,const std::string name,T & value)`            | > Todo: Add description. Add tests
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignAbsDoubleParameter`](#df/dab/group___parameter_functions_1ga4034a69ed57b29d70857115c16e36074)`(const char * input,const std::string name,double & value)`            | > Todo: Add description. Add tests
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignByCheckingParameter`](#df/dab/group___parameter_functions_1gaca17fe10d6c287a14c243e674df8b87f)`(const char * input,const std::string parameter,T & value,const T supposed)`            | > Todo: Add description. Add tests
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`showProgressBar`](#d2/dbc/group___interface_functions_1gabb30a31da7b0671b01ffbb94206b4a03)`(double progress,const std::size_t screenWidth)`            | Prints a simple progress-bar to stdout.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printLine`](#d2/dbc/group___interface_functions_1ga6f11920ba7b795a79ada930be98f6214)`(const std::string line,const std::size_t screenWidth)`            | Prints a line with specified width.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`parseFileInMatrix`](#df/d73/group___read_functions_1gae9d45625612ddcd2581e26843f141213)`(const std::string filename,const char separator,std::vector< std::vector< T > > & matrix)`            | > Todo: Add description. Add tests
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`parseFileInVector`](#df/d73/group___read_functions_1ga90ae1cfa3d587cdd7d5cb1db70f2621f)`(const std::string filename,const char separator,std::vector< T > & vector)`            | > Todo: Add description. Add tests
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`parseFileIntoString`](#df/d73/group___read_functions_1gac8b3d3c1db1973ae2d57265e435d2066)`(const std::string filename,std::string & content)`            | > Todo: Add description. Add tests
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`accumulateFileInMatrix`](#df/d73/group___read_functions_1ga9ad08eb45ba0cb425d25e8644bc33a69)`(const std::string filename,const char separator,std::vector< std::vector< T > > & matrix)`            | > Todo: Add description. Add tests
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`accumulateFileInVector`](#df/d73/group___read_functions_1ga6dc3993c11c7e8af3c3847b1efbe7a4b)`(const std::string filename,const char separator,std::vector< T > & vector,const bool checkForNaN)`            | > Todo: Add description. Add tests
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printMatrix`](#dc/d09/group___print_functions_1gacfdc757b2fffba082e869a7f757b98c1)`(const std::vector< std::vector< T > > matrix,const int precision)`            | > Todo: Add description. Add tests
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printVector`](#dc/d09/group___print_functions_1gad94bd2a44c60fbbbf17dfa5fa0a61f4e)`(const std::vector< T > vector,const int precision)`            | > Todo: Add description. Add tests
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveMatrix`](#d3/d61/group___save_functions_1ga5449f1c55c95e463304de13863fcebb1)`(const std::string filename,const std::vector< std::vector< T > > matrix,std::string comment,std::string type,std::string delimiter,const std::size_t tokenWidth)`            | > Todo: Add description. Add tests
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveVector`](#d3/d61/group___save_functions_1gadfa0dcf506d109993e759e87c833f836)`(const std::string filename,const std::vector< T > vector,std::string comment,std::string type,std::string delimiter)`            | > Todo: Add description. Add tests
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveLine`](#d3/d61/group___save_functions_1gaa2e0414f205aea2097386fb41d146a61)`(const std::string filename,const std::string line,std::string comment)`            | > Todo: Add description. Add tests
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`saveA3R`](#d3/d61/group___save_functions_1gac5228a4f8019bb3deceb503e0e03a678)`(const std::string filename,std::vector< std::vector< T > > positions,const double radius)`            | > Todo: Add description. Add tests
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`folderExists`](#df/dae/group___file_functions_1ga53c41d1ee4cccd4e3b69243362c82129)`(const std::string name)`            | > Todo: Add description. Add tests
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::size_t `[`countLinesInFile`](#df/dae/group___file_functions_1gadf09232474a3c9e0da8ca89f9a792abe)`(const std::string filename,const std::string token)`            | > Todo: Add description. Add tests
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::vector< std::string > `[`listFilesWithExtension`](#df/dae/group___file_functions_1ga46c6f8665ce9034fa718b3958dcfe123)`(const std::string path,const std::string extension,const std::string prefix)`            | > Todo: Add description. Add tests
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`execute`](#d9/d59/group___shell_functions_1ga92245db9096637e0aae3d8dcd77a4d3f)`(const std::string command)`            | > Todo: Add description. Add tests. Add more options to bufferSize

## Members

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`getVersion`](#d5/dd6/group___library_info_1gae81b57260fe20a158b0226ca9b51610e)`()` 

Gets version of the lib.

This function returns version of the AiLibrary (we use SemVer) 
#### Returns
Version as a string

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`string`](#d4/d65/group___string_functions_1gac77e5243b1f905e34f4e34214ebc0d47)`(const T value)` 

Converts input into a string.

This function converts your variable into std::string using std::ostringstream 
#### Parameters
* `value` Your variable to convert 

#### Returns
std::string copy of your input

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`hasPrefix`](#d4/d65/group___string_functions_1gae7d7fb0e302e9de48a24b1134149f2eb)`(const std::string & text,const std::string & prefix)` 

Checks if a string begins with a substring.

This function checks if a string begins with a substring 
#### Parameters
* `text` Your string to test 

* `prefix` Your substring 

#### Returns
True if string begins with a substring, false otherwise

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`hasSuffix`](#d4/d65/group___string_functions_1ga5ffb87ef7304cf15de933db0ef8dbb5a)`(const std::string & text,const std::string & suffix)` 

Checks if a string ends with a substring.

This function checks if a string ends with a substring 
#### Parameters
* `text` Your string to test 

* `suffix` Your substring 

#### Returns
True if string ends with a substring, false otherwise

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`contains`](#d4/d65/group___string_functions_1ga1a7fafa4ef8edd8b49b461840ca42dd6)`(const std::string & text,const std::string & substring)` 

Checks if a string contains a substring.

This function checks if a string contains a substring 
#### Parameters
* `text` Your string to test 

* `substring` Your substring 

#### Returns
True if string contains a substring, false otherwise

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`replace`](#d4/d65/group___string_functions_1gaa3ee3ad75450b355f177173739343c01)`(std::string text,const std::string & substring,const std::string & replacement)` 

Replaces all occurrences of a substring in a copy of the initial string with your text.

This function replaces all occurrences of a substring in a string with your text and return the result. Initial string stays the same 
#### Parameters
* `text` Your string to modify 

* `substring` Your substring to find in the string 

* `replacement` Replacement for all the substring occurrences 

#### Returns
Modified copy of the initial string

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`applyReplace`](#d4/d65/group___string_functions_1ga716112bcf505ef4c86f65619afe573a5)`(std::string & text,const std::string & substring,const std::string & replacement)` 

Modifies your string by replacing all occurrences of a substring string with your text.

This function replaces all occurrences of a substring in a string with your text (modifies the initial string) 
#### Parameters
* `text` Your string to modify 

* `substring` Your substring to find in the string 

* `replacement` Replacement for all the substring occurrences

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`equal`](#d4/d65/group___string_functions_1gab125482b04497d2b9d7880cdfd51ccff)`(const char * charString,const std::string string1)` 

Checks if a char string is equal to a std::string.

This function compares a char string with a std::string 
#### Parameters
* `charString` Your char string to compare 

* `string1` Your std::string to compare 

#### Returns
True if strings are equal, false otherwise

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::size_t `[`counter`](#d3/ddf/group___debug_functions_1gae14b2a823a0d4558fd7c3213ff4d3509)`(std::size_t value)` 

Returns ID starting from zero or the specified value.

This function returns ID (increases it at each call) starting from zero or the specified non-negative value 
#### Parameters
* `value` The non-negative value to which the counter should be reset (optional) 

#### Returns
Counter value

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`marker`](#d3/ddf/group___debug_functions_1ga96824e55a873b5474316326942066d7c)`(std::size_t value)` 

Returns a string containing the word "Marker" and its ID.

This function returns a string containing the word "marker" and its ID (increases it at each call). ID specified in the same way as in the function [counter()](#d3/ddf/group___debug_functions_1gae14b2a823a0d4558fd7c3213ff4d3509)
#### Parameters
* `value` The non-negative value to which the counter should be reset (optional) 

#### Returns
Marker string

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printMarker`](#d3/ddf/group___debug_functions_1ga4f74ef7895220dc9aba06fb6eab6073b)`(std::size_t value)` 

Calls [marker()](#d3/ddf/group___debug_functions_1ga96824e55a873b5474316326942066d7c) and prints result to stdout.

This function calls [marker()](#d3/ddf/group___debug_functions_1ga96824e55a873b5474316326942066d7c) and prints result to stdout 
#### Parameters
* `value` The non-negative value to which the counter should be reset (optional)

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`sign`](#d5/d12/group___math_functions_1ga59e445549490377e66c6c2719b65cc0e)`(const T value)` 

Returns signum of the value.

This function returns signum of the value (usign copysign()) 
#### Parameters
* `value` The number to which signum is applied 

#### Returns
-1 for negative values, +1 for positive, 0 for zero 

#### Parameters
* `T` A number type 

> Todo: Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`min`](#d5/d12/group___math_functions_1ga4ff9e753d095c1ca70b0ec517b0c919e)`(const T a,const T b)` 

Returns minimum of two values.

This function compares two values and returns a minimum 
#### Parameters
* `a` First number 

* `b` Second number 

#### Returns
Minimum of two values 

#### Parameters
* `T` A number type 

> Todo: Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`max`](#d5/d12/group___math_functions_1gab4363f54de7131a1530189fdfb614334)`(const T a,const T b)` 

Returns maximum of two values.

This function compares two values and returns a maximum 
#### Parameters
* `a` First number 

* `b` Second number 

#### Returns
Maximum of two values 

#### Parameters
* `T` A number type 

> Todo: Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`min`](#d5/d12/group___math_functions_1gab855a677ddeab67056d5316bc95ef683)`(const std::vector< T > & input)` 

Returns minimum of vector values.

This function compares vector values using [min()](#d5/d12/group___math_functions_1ga4ff9e753d095c1ca70b0ec517b0c919e) and returns a minimum 
#### Parameters
* `input` Vector to search for a minimum value 

#### Returns
Minimum of vector values 

#### Parameters
* `T` A number type 

> Todo: Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`max`](#d5/d12/group___math_functions_1ga38d9271ac8875ee2e73f7393e791ad55)`(const std::vector< T > & input)` 

Returns maximum of vector values.

This function compares vector values using [max()](#d5/d12/group___math_functions_1gab4363f54de7131a1530189fdfb614334) and returns a maximum 
#### Parameters
* `input` Vector to search for a maximum value 

#### Returns
Maximum of vector values 

#### Parameters
* `T` A number type 

> Todo: Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`min`](#d5/d12/group___math_functions_1gad56ff7c2618a4cb19a5b451663b42394)`(const std::vector< std::vector< T > > & input)` 

Returns minimum of matrix values.

This function compares matrix values using [min()](#d5/d12/group___math_functions_1ga4ff9e753d095c1ca70b0ec517b0c919e) and returns a minimum 
#### Parameters
* `input` Matrix to search for a minimum value 

#### Returns
Minimum of matrix values 

#### Parameters
* `T` A number type 

> Todo: Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`max`](#d5/d12/group___math_functions_1gac41228d2f55e89ea0cbf721d8ee076ff)`(const std::vector< std::vector< T > > & input)` 

Returns maximum of matrix values.

This function compares matrix values using [max()](#d5/d12/group___math_functions_1gab4363f54de7131a1530189fdfb614334) and returns a maximum 
#### Parameters
* `input` Matrix to search for a maximum value 

#### Returns
Maximum of matrix values 

#### Parameters
* `T` A number type 

> Todo: Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`isSquare`](#d5/d12/group___math_functions_1gac521d17c2aff565fbc375f2f9c611dcd)`(const T value)` 

Checks if number is square.

This function checks if number is square 
#### Parameters
* `value` Number to test 

#### Returns
True if number is a square, false otherwise 

#### Parameters
* `T` A number type 

> Todo: Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`isSquare`](#d5/d12/group___math_functions_1gaba5e6609f9c8fd769ce6d66d46159b2b)`(const std::vector< std::vector< T > > matrix)` 

Checks if matrix is square.

This function checks if matrix is square 
#### Parameters
* `matrix` Matrix to test 

#### Returns
True if matrix is square, false otherwise 

> Todo: Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`generateRandomVector`](#d5/d12/group___math_functions_1ga2cf03512823864f49bb5255c97d40ed7)`(std::vector< T > & vector,const std::size_t length,const T min,const T max)` 

> Todo: Add description. Add tests. Check for real or int

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`generateRandomMatrix`](#d5/d12/group___math_functions_1gad7c9b6127798888b827519f713380b65)`(std::vector< std::vector< T > > & matrix,const std::size_t xSize,const std::size_t ySize,const T min,const T max)` 

> Todo: Add description. Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`generateRandomMatrix`](#d5/d12/group___math_functions_1gaf32c64e29eaa5688f7d84800d780ff2e)`(std::vector< T > & vector,const std::size_t size,const T min,const T max)` 

> Todo: Add description. Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`translateMatrixIntoVector`](#d5/d12/group___math_functions_1ga277c02074c8e0dc2c4ef67b8bc2371ce)`(std::vector< std::vector< T > > & matrix,std::vector< T > & vector)` 

Elongates matrix into a vector.

This function converts the matrix into a vector, writing each row one after another in a line 
#### Parameters
* `matrix` Matrix to tranform 

* `vector` Vector to store the result 

> Todo: Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`translateVectorIntoSquareMatrix`](#d5/d12/group___math_functions_1ga43c134aa8eab9d5edb498016ee891646)`(std::vector< T > & vector,std::vector< std::vector< T > > & matrix)` 

Transform vector in a square matrix (if possible)

This function converts the vector into a matrix, if possible. Otherwise, an exception will be thrown at runtime 
#### Parameters
* `vector` Vector to tranform 

* `matrix` Matrix to store the result 

#### Exceptions
* `std::runtime_error` If `matrix` is not square 

> Todo: Add tests

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::chrono::high_resolution_clock::time_point `[`time`](#dd/dd0/group___time_functions_1ga54195a75b5598d4078f9f4cc57628f2b)`()` 

Returns current time point.

This function returns current time point using std::chrono 
#### Returns
std::chrono::high_resolution_clock entity 

> Todo: Add tests

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` double `[`duration`](#dd/dd0/group___time_functions_1ga912fcdb43dab89156260759a2fc128d6)`(const std::chrono::high_resolution_clock::time_point start,const std::chrono::high_resolution_clock::time_point finish,const std::string scale)` 

Returns the difference between two time points.

This function returns the difference between two time points in seconds, milliseconds or microseconds using std::chrono (handy to measure functions and code blocks) 
#### Parameters
* `start` Time point 

* `finish` Time point 

* `scale` Optional. If `scale` equals to "s", function will return difference in seconds. If `scale` equals to "us" – in microseconds. Otherwise – in microseconds. 

#### Returns
Difference between points 

> Todo: Add tests

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`parseParameter`](#df/dab/group___parameter_functions_1ga2d54d56130ff4b251fd09a33c307d924)`(const char * input,const std::string name)` 

> Todo: Add description. Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`assignFromVectorByIntervalCondition`](#df/dab/group___parameter_functions_1ga4de411233451db390ce475f2f3916962)`(T & value,const T parameter,const std::vector< std::vector< T > > intervals)` 

> Todo: Add description. Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`assignFromVectorByIntervalCondition`](#df/dab/group___parameter_functions_1ga59fc20819b5d0024c784c62bb75bb6b4)`(T & firstValue,T & secondValue,const T parameter,const std::vector< std::vector< T > > intervals)` 

> Todo: Add description. Add tests

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignBooleanParameter`](#df/dab/group___parameter_functions_1gaf22400542606a991705af80aacd216e7)`(const char * input,const std::string name,bool & value)` 

> Todo: Add description. Add tests

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignCharParameter`](#df/dab/group___parameter_functions_1ga02eb74222c6c05c9ef731358f3afcc70)`(const char * input,const std::string name,char & value)` 

> Todo: Add description. Add tests

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignStringParameter`](#df/dab/group___parameter_functions_1ga66fb81eb3a9d18a05eebf2188ebfa7d1)`(const char * input,const std::string name,std::string & value)` 

> Todo: Add description. Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignParameter`](#df/dab/group___parameter_functions_1ga39965300f2ee700f23af9cfb984a4dab)`(const char * input,const std::string name,T & value)` 

> Todo: Add description. Add tests

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignAbsDoubleParameter`](#df/dab/group___parameter_functions_1ga4034a69ed57b29d70857115c16e36074)`(const char * input,const std::string name,double & value)` 

> Todo: Add description. Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignByCheckingParameter`](#df/dab/group___parameter_functions_1gaca17fe10d6c287a14c243e674df8b87f)`(const char * input,const std::string parameter,T & value,const T supposed)` 

> Todo: Add description. Add tests

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`showProgressBar`](#d2/dbc/group___interface_functions_1gabb30a31da7b0671b01ffbb94206b4a03)`(double progress,const std::size_t screenWidth)` 

Prints a simple progress-bar to stdout.

This function prints a simple progress-bar to stdout 
#### Parameters
* `progress` Number from 0 to 1 to 

* `screenWidth` Optional. The maximum length of the progress-bar in the symbols. Default is 80, should be at least 20 

#### Exceptions
* `std::runtime_error` If `screenWidth` is less than 20

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printLine`](#d2/dbc/group___interface_functions_1ga6f11920ba7b795a79ada930be98f6214)`(const std::string line,const std::size_t screenWidth)` 

Prints a line with specified width.

This function prints a line with specified width. Can be useful to print output when progress-bar is displayed (function [showProgressBar()](#d2/dbc/group___interface_functions_1gabb30a31da7b0671b01ffbb94206b4a03)). 
#### Parameters
* `line` Text to print 

* `screenWidth` Optional. The maximum length of the progress-bar in the symbols. Default is 80, should be at least 20 

#### Exceptions
* `std::runtime_error` If `screenWidth` is less than 20

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`parseFileInMatrix`](#df/d73/group___read_functions_1gae9d45625612ddcd2581e26843f141213)`(const std::string filename,const char separator,std::vector< std::vector< T > > & matrix)` 

> Todo: Add description. Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`parseFileInVector`](#df/d73/group___read_functions_1ga90ae1cfa3d587cdd7d5cb1db70f2621f)`(const std::string filename,const char separator,std::vector< T > & vector)` 

> Todo: Add description. Add tests

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`parseFileIntoString`](#df/d73/group___read_functions_1gac8b3d3c1db1973ae2d57265e435d2066)`(const std::string filename,std::string & content)` 

> Todo: Add description. Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`accumulateFileInMatrix`](#df/d73/group___read_functions_1ga9ad08eb45ba0cb425d25e8644bc33a69)`(const std::string filename,const char separator,std::vector< std::vector< T > > & matrix)` 

> Todo: Add description. Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`accumulateFileInVector`](#df/d73/group___read_functions_1ga6dc3993c11c7e8af3c3847b1efbe7a4b)`(const std::string filename,const char separator,std::vector< T > & vector,const bool checkForNaN)` 

> Todo: Add description. Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printMatrix`](#dc/d09/group___print_functions_1gacfdc757b2fffba082e869a7f757b98c1)`(const std::vector< std::vector< T > > matrix,const int precision)` 

> Todo: Add description. Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printVector`](#dc/d09/group___print_functions_1gad94bd2a44c60fbbbf17dfa5fa0a61f4e)`(const std::vector< T > vector,const int precision)` 

> Todo: Add description. Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveMatrix`](#d3/d61/group___save_functions_1ga5449f1c55c95e463304de13863fcebb1)`(const std::string filename,const std::vector< std::vector< T > > matrix,std::string comment,std::string type,std::string delimiter,const std::size_t tokenWidth)` 

> Todo: Add description. Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveVector`](#d3/d61/group___save_functions_1gadfa0dcf506d109993e759e87c833f836)`(const std::string filename,const std::vector< T > vector,std::string comment,std::string type,std::string delimiter)` 

> Todo: Add description. Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveLine`](#d3/d61/group___save_functions_1gaa2e0414f205aea2097386fb41d146a61)`(const std::string filename,const std::string line,std::string comment)` 

> Todo: Add description. Add tests

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`saveA3R`](#d3/d61/group___save_functions_1gac5228a4f8019bb3deceb503e0e03a678)`(const std::string filename,std::vector< std::vector< T > > positions,const double radius)` 

> Todo: Add description. Add tests

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`folderExists`](#df/dae/group___file_functions_1ga53c41d1ee4cccd4e3b69243362c82129)`(const std::string name)` 

> Todo: Add description. Add tests

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::size_t `[`countLinesInFile`](#df/dae/group___file_functions_1gadf09232474a3c9e0da8ca89f9a792abe)`(const std::string filename,const std::string token)` 

> Todo: Add description. Add tests

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::vector< std::string > `[`listFilesWithExtension`](#df/dae/group___file_functions_1ga46c6f8665ce9034fa718b3958dcfe123)`(const std::string path,const std::string extension,const std::string prefix)` 

> Todo: Add description. Add tests

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`execute`](#d9/d59/group___shell_functions_1ga92245db9096637e0aae3d8dcd77a4d3f)`(const std::string command)` 

> Todo: Add description. Add tests. Add more options to bufferSize

Generated by [Moxygen](https://sourcey.com/moxygen)