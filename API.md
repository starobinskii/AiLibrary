# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`define `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)            | If defined, funstions will be marked as inline.
`define `[`AI_DIRENT_SUPPORT`](#de/d9e/ai_8hh_1a08ab4858c793965290f01379fdce3260)            | 
`define `[`AI_GCC5_SUPPORT`](#de/d9e/ai_8hh_1a24ab0b03c9edebe84cc71e1afccc1acb)            | 
`define `[`AI_SHELL_SUPPORT`](#de/d9e/ai_8hh_1a6c539823cbc5afcffc0db69070e04adf)            | 
`define `[`STRINGIFY`](#d1/dec/group___macros_group_1ga6df1d22fb5f09eccc23b9f399670cfd7)            | Convert a variable name into text.
`define `[`TO_STRING`](#d1/dec/group___macros_group_1gaa49b6a1041bf80c96599056af0bc5b4a)            | Convert a variable value into text.
`define `[`PRINT_LINE`](#d1/dec/group___macros_group_1ga1e1e978a9034dcad8231ac096f9a4902)            | Print the line number.
`namespace `[`ai`](#de/d58/namespaceai) | Main namespace.

## Members

#### `define `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116) 

If defined, funstions will be marked as inline.

If defined, funstions will be marked as inline. Comment the line if you want to omit this behavior

#### `define `[`AI_DIRENT_SUPPORT`](#de/d9e/ai_8hh_1a08ab4858c793965290f01379fdce3260) 

#### `define `[`AI_GCC5_SUPPORT`](#de/d9e/ai_8hh_1a24ab0b03c9edebe84cc71e1afccc1acb) 

#### `define `[`AI_SHELL_SUPPORT`](#de/d9e/ai_8hh_1a6c539823cbc5afcffc0db69070e04adf) 

#### `define `[`STRINGIFY`](#d1/dec/group___macros_group_1ga6df1d22fb5f09eccc23b9f399670cfd7) 

Convert a variable name into text.

This macro converts a variable name into text, which is useful for debugging

#### `define `[`TO_STRING`](#d1/dec/group___macros_group_1gaa49b6a1041bf80c96599056af0bc5b4a) 

Convert a variable value into text.

This macro converts a variable value into text, so you can access the constants defined at compile time as std::string

#### `define `[`PRINT_LINE`](#d1/dec/group___macros_group_1ga1e1e978a9034dcad8231ac096f9a4902) 

Print the line number.

This macro prints the line number on which it was called

# namespace `ai` 

Main namespace.

Main namespace containing all the functions of AiLibrary

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`getVersion`](#d5/dd6/group___library_info_1gae81b57260fe20a158b0226ca9b51610e)`()`            | Get version of the library.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`string`](#d4/d65/group___string_functions_1gac77e5243b1f905e34f4e34214ebc0d47)`(const T value)`            | Converts input into a string.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`hasPrefix`](#d4/d65/group___string_functions_1gae7d7fb0e302e9de48a24b1134149f2eb)`(const std::string & text,const std::string & prefix)`            | Checks if a string begins with a substring.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`hasSuffix`](#d4/d65/group___string_functions_1ga5ffb87ef7304cf15de933db0ef8dbb5a)`(const std::string & text,const std::string & suffix)`            | Checks if a string ends with a substring.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`contains`](#d4/d65/group___string_functions_1ga1a7fafa4ef8edd8b49b461840ca42dd6)`(const std::string & text,const std::string & substring)`            | Checks if a string contains a substring.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`replace`](#d4/d65/group___string_functions_1gaa3ee3ad75450b355f177173739343c01)`(std::string text,const std::string & substring,const std::string & replacement)`            | Replaces all occurrences of a substring in a copy of the initial string with your text.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`applyReplace`](#d4/d65/group___string_functions_1ga716112bcf505ef4c86f65619afe573a5)`(std::string & text,const std::string & substring,const std::string & replacement)`            | Modifies your string by replacing all occurrences of a substring string with your text.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`equal`](#d4/d65/group___string_functions_1gab125482b04497d2b9d7880cdfd51ccff)`(const char * charString,const std::string string1)`            | Checks if a char string is equal to a std::string.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`toUpperCase`](#d4/d65/group___string_functions_1gafa7403264826a98706779d24c37135f7)`(std::string input)`            | Convert a string to upper case.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`toLowerCase`](#d4/d65/group___string_functions_1ga8b0ea59a58d4a8fc91a45a9c6b497900)`(std::string input)`            | Convert a string to lower case.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`prependNumber`](#d4/d65/group___string_functions_1ga558ddc85d7fcebb82d31fdf2f701f24e)`(const T value,const std::size_t symbolsBeforePoint,const char symbolToPrepend)`            | 
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::size_t `[`counter`](#d3/ddf/group___debug_functions_1ga5ad831a383f32b3f7f66f1259ff239ee)`(const std::size_t value)`            | Returns ID starting from zero or the specified value.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`marker`](#d3/ddf/group___debug_functions_1ga345351c64f543f9459af2a4449f59cfe)`(const std::size_t value)`            | Returns a string containing the word "Marker" and its ID.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printMarker`](#d3/ddf/group___debug_functions_1ga9c430bdce23c1a7e9c9d9de3ce6b4b38)`(const std::size_t value)`            | Calls [marker()](#d3/ddf/group___debug_functions_1ga345351c64f543f9459af2a4449f59cfe) and prints result to stdout.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`sign`](#d5/d12/group___math_functions_1ga59e445549490377e66c6c2719b65cc0e)`(const T value)`            | Returns signum of the value.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`min`](#d5/d12/group___math_functions_1ga4ff9e753d095c1ca70b0ec517b0c919e)`(const T a,const T b)`            | Returns minimum of two values.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`max`](#d5/d12/group___math_functions_1gab4363f54de7131a1530189fdfb614334)`(const T a,const T b)`            | Returns maximum of two values.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`min`](#d5/d12/group___math_functions_1gab855a677ddeab67056d5316bc95ef683)`(const std::vector< T > & input)`            | Returns minimum of vector values.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`max`](#d5/d12/group___math_functions_1ga38d9271ac8875ee2e73f7393e791ad55)`(const std::vector< T > & input)`            | Returns maximum of vector values.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`min`](#d5/d12/group___math_functions_1gad56ff7c2618a4cb19a5b451663b42394)`(const std::vector< std::vector< T > > & input)`            | Returns minimum of matrix values.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`max`](#d5/d12/group___math_functions_1gac41228d2f55e89ea0cbf721d8ee076ff)`(const std::vector< std::vector< T > > & input)`            | Returns maximum of matrix values.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`isSquare`](#d5/d12/group___math_functions_1gac521d17c2aff565fbc375f2f9c611dcd)`(const T value)`            | Checks if number is square.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`isSquare`](#d5/d12/group___math_functions_1gaa78e52e15c1e9c7de3243ad6791ea8e2)`(const std::vector< std::vector< T > > & matrix)`            | Checks if matrix is square.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`generateRandomVector`](#d5/d12/group___math_functions_1ga2cf03512823864f49bb5255c97d40ed7)`(std::vector< T > & vector,const std::size_t length,const T min,const T max)`            | 
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`generateRandomMatrix`](#d5/d12/group___math_functions_1ga5fc76a6aabb72285b3269132e30597a2)`(std::vector< std::vector< T > > & matrix,const std::size_t xSize,const std::size_t ySize,const T min,const T max)`            | Fill matrix with random values.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`generateRandomMatrix`](#d5/d12/group___math_functions_1ga1776f29fc7629ca51c451bf411acb8a5)`(std::vector< std::vector< T > > & matrix,const std::size_t size,const T min,const T max)`            | Fill matrix with random values.
`public template<>`  <br/>`void `[`rotateMatrix`](#d5/d12/group___math_functions_1ga7d70bb658337d2d2b53ff7aef9e75dac)`(std::vector< std::vector< T > > & matrix,const bool rotateClockwise)`            | Rotate square matrix.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`inverseMatrix`](#d5/d12/group___math_functions_1ga22896aadb82739145e85dfa39290d14b)`(std::vector< std::vector< T > > matrix,std::vector< std::vector< T > > & inverse)`            | 
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`inverseMatrix`](#d5/d12/group___math_functions_1gada879df08132090166f65118ae8ca81e)`(std::vector< std::vector< T > > & matrix)`            | 
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`translateMatrixIntoVector`](#d5/d12/group___math_functions_1ga277c02074c8e0dc2c4ef67b8bc2371ce)`(std::vector< std::vector< T > > & matrix,std::vector< T > & vector)`            | Elongates matrix into a vector.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`translateVectorIntoSquareMatrix`](#d5/d12/group___math_functions_1ga43c134aa8eab9d5edb498016ee891646)`(std::vector< T > & vector,std::vector< std::vector< T > > & matrix)`            | Transform vector into a square matrix (if possible)
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`generateCirculantMatrix`](#d5/d12/group___math_functions_1ga27a6217153189fe16cf421ab3fe07ca8)`(std::vector< std::vector< T > > & matrix,std::vector< T > & source,const bool moveToTheRight)`            | 
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`multiply`](#d5/d12/group___math_functions_1ga50bf5a5c329516b044d4553f1dce69e5)`(const std::vector< std::vector< T > > & left,const std::vector< std::vector< T > > & right,std::vector< std::vector< T > > & result)`            | 
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`multiply`](#d5/d12/group___math_functions_1ga5aa2e148dcac9b79642b3708a501fc8d)`(const std::vector< std::vector< T > > & left,const std::vector< T > & right,std::vector< T > & result)`            | 
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`multiply`](#d5/d12/group___math_functions_1ga8f0f988a4b13e3b6ad1a6e5d6f4c6f95)`(const std::vector< T > & left,const std::vector< T > & right,T & result)`            | Calculate vector-vector multiplication.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`multiplyElementWise`](#d5/d12/group___math_functions_1ga8bc34f17df4fc867bf0eee3de8f6aabb)`(const std::vector< std::vector< T > > & left,const std::vector< std::vector< T > > & right,std::vector< std::vector< T > > & result)`            | 
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`multiplyElementWise`](#d5/d12/group___math_functions_1gaea3bca561dbdcd13aaf74531a3649319)`(const std::vector< T > & left,const std::vector< T > & right,std::vector< T > & result)`            | 
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`multiplyComplexElementWise`](#d5/d12/group___math_functions_1gae066365ce568fab84880facf6297b67a)`(const std::vector< std::vector< T > > & left,const std::vector< std::vector< T > > & right,std::vector< std::vector< T > > & result)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`complexIntoString`](#d5/d12/group___math_functions_1ga781cfb9e924621b4e18cb0473366d368)`(const std::vector< T > complexValue)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`conjugate`](#d5/d12/group___math_functions_1ga6422b6dcd8d8a187a979b8207d2f2243)`(std::vector< std::vector< T > > & complexVector)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`fft`](#d5/d12/group___math_functions_1ga46e87531b41eba547be604d1e34b7b27)`(std::vector< std::vector< T > > & complexVector)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`ifft`](#d5/d12/group___math_functions_1gaf04c96b76dd1bceb79fecf325838604b)`(std::vector< std::vector< T > > & complexVector)`            | #### Parameters
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::chrono::high_resolution_clock::time_point `[`time`](#dd/dd0/group___time_functions_1ga54195a75b5598d4078f9f4cc57628f2b)`()`            | Returns current time point.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::chrono::system_clock::time_point `[`systemTime`](#dd/dd0/group___time_functions_1ga35b9e10e815e1b62585d4c1f07b71faf)`()`            | Returns current time point.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` double `[`duration`](#dd/dd0/group___time_functions_1ga2093a6b79f8831e98746f31c6cd66d5c)`(const std::chrono::high_resolution_clock::time_point start,const std::chrono::high_resolution_clock::time_point finish,const std::string scale)`            | 
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` double `[`duration`](#dd/dd0/group___time_functions_1gac39f52c9c5983eba7db340a5469eaa83)`(const std::chrono::high_resolution_clock::time_point start,const std::string scale)`            | 
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printDuration`](#dd/dd0/group___time_functions_1gafce472052309d5d843fd24a7fcaad589)`(const std::chrono::high_resolution_clock::time_point start,const std::chrono::high_resolution_clock::time_point finish,const std::string scale,const std::size_t count)`            | 
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printDuration`](#dd/dd0/group___time_functions_1gaee849e5398ad0b85aee9de35d0f4deb2)`(const std::chrono::high_resolution_clock::time_point start,const std::string scale,const std::size_t count)`            | 
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`getDateAndTime`](#dd/dd0/group___time_functions_1ga6fd823c420070d11541efef69420011f)`(std::chrono::system_clock::time_point timePoint)`            | Get date and time.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`getDate`](#dd/dd0/group___time_functions_1ga4af5bcf9bf9c84e563cac5f8366e1a22)`(std::chrono::system_clock::time_point timePoint)`            | Get date.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`getTime`](#dd/dd0/group___time_functions_1ga09b52a9378428e8a6127c5605bd79694)`(std::chrono::system_clock::time_point timePoint)`            | Get time.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`parseParameter`](#df/dab/group___parameter_functions_1ga2d54d56130ff4b251fd09a33c307d924)`(const char * input,const std::string name)`            | 
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`assignFromVectorByIntervalCondition`](#df/dab/group___parameter_functions_1ga4de411233451db390ce475f2f3916962)`(T & value,const T parameter,const std::vector< std::vector< T > > intervals)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`assignFromVectorByIntervalCondition`](#df/dab/group___parameter_functions_1ga59fc20819b5d0024c784c62bb75bb6b4)`(T & firstValue,T & secondValue,const T parameter,const std::vector< std::vector< T > > intervals)`            | #### Parameters
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignBooleanParameter`](#df/dab/group___parameter_functions_1gaf22400542606a991705af80aacd216e7)`(const char * input,const std::string name,bool & value)`            | 
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignCharParameter`](#df/dab/group___parameter_functions_1ga02eb74222c6c05c9ef731358f3afcc70)`(const char * input,const std::string name,char & value)`            | 
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignStringParameter`](#df/dab/group___parameter_functions_1ga66fb81eb3a9d18a05eebf2188ebfa7d1)`(const char * input,const std::string name,std::string & value)`            | 
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignParameter`](#df/dab/group___parameter_functions_1ga39965300f2ee700f23af9cfb984a4dab)`(const char * input,const std::string name,T & value)`            | #### Parameters
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignAbsDoubleParameter`](#df/dab/group___parameter_functions_1ga4034a69ed57b29d70857115c16e36074)`(const char * input,const std::string name,double & value)`            | 
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignByCheckingParameter`](#df/dab/group___parameter_functions_1gaca17fe10d6c287a14c243e674df8b87f)`(const char * input,const std::string parameter,T & value,const T supposed)`            | #### Parameters
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`clearScreen`](#d2/dbc/group___interface_functions_1gaf19bb9cf544cb5bc7a010b9e6693ebf7)`()`            | 
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`setLocale`](#d2/dbc/group___interface_functions_1ga1f7fff63e38f3ce8ccc98f3a47c42a1c)`(const std::string locale)`            | 
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`showProgressBar`](#d2/dbc/group___interface_functions_1ga1763f8f8d0df5cae7fbf79e18a0d20c3)`(double progress,const int screenWidth)`            | 
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printLine`](#d2/dbc/group___interface_functions_1ga5a0c49b9088cdfaf6749cdfc7d0a8628)`(const std::string line,const int screenWidth)`            | 
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`parseFileInMatrix`](#df/d73/group___read_functions_1gae9d45625612ddcd2581e26843f141213)`(const std::string filename,const char separator,std::vector< std::vector< T > > & matrix)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`parseFileInVector`](#df/d73/group___read_functions_1ga90ae1cfa3d587cdd7d5cb1db70f2621f)`(const std::string filename,const char separator,std::vector< T > & vector)`            | #### Parameters
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`parseFileIntoString`](#df/d73/group___read_functions_1gac8b3d3c1db1973ae2d57265e435d2066)`(const std::string filename,std::string & content)`            | #### Exceptions
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`accumulateFileInMatrix`](#df/d73/group___read_functions_1ga9ad08eb45ba0cb425d25e8644bc33a69)`(const std::string filename,const char separator,std::vector< std::vector< T > > & matrix)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`accumulateFileInVector`](#df/d73/group___read_functions_1ga6dc3993c11c7e8af3c3847b1efbe7a4b)`(const std::string filename,const char separator,std::vector< T > & vector,const bool checkForNaN)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printMatrix`](#dc/d09/group___print_functions_1ga2cfb640704df7c1b859c440482d26ffe)`(const std::vector< std::vector< T > > & matrix,const bool transpose,const int precision)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printVector`](#dc/d09/group___print_functions_1gaf8a54b522733a2ef8f15be72b715189e)`(const std::vector< T > & vector,const int precision)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`print`](#dc/d09/group___print_functions_1ga65fd54001ef1807b57d277ce02342320)`(const std::vector< std::vector< T > > & matrix,const bool transpose,const int precision)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`print`](#dc/d09/group___print_functions_1gadd02d38ccafa18ef83b6c4b8cb3c0e6d)`(const std::vector< T > & vector,const int precision)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`print`](#dc/d09/group___print_functions_1ga220a82c64afd994f2b3df3ec62a191b0)`(const T value,const std::string name)`            | #### Parameters
`public static std::string `[`black`](#dc/d09/group___print_functions_1gabfd87c66472aeceefdb7160941151984)`("\30m")`            | Terminal color code for black.
`public static std::string `[`red`](#dc/d09/group___print_functions_1gad99c58f6ae82527a3b8b7623aaed1dda)`("\31m")`            | Terminal color code for red.
`public static std::string `[`green`](#dc/d09/group___print_functions_1ga6ba6ceca5f659cd8eb528255d9a06d89)`("\32m")`            | Terminal color code for green.
`public static std::string `[`yellow`](#dc/d09/group___print_functions_1gaafa6d780856c3981c59dff706ab3a779)`("\33m")`            | Terminal color code for yellow.
`public static std::string `[`blue`](#dc/d09/group___print_functions_1ga01e5278053d7b4fcef7ed016636fda53)`("\34m")`            | Terminal color code for blue.
`public static std::string `[`magenta`](#dc/d09/group___print_functions_1ga79ac3cbc99ea2004650b1f146b7ca594)`("\35m")`            | Terminal color code for magenta.
`public static std::string `[`cyan`](#dc/d09/group___print_functions_1ga009e72aadeaea320f5b4caeaa75ca5cc)`("\36m")`            | Terminal color code for cyan.
`public static std::string `[`white`](#dc/d09/group___print_functions_1gabec8a45ab6396d631ceb8cb735898db0)`("\37m")`            | Terminal color code for white.
`public static std::string `[`bold`](#dc/d09/group___print_functions_1ga5d203a3b01eb3ddd02d16c44a4d0a0ac)`("\1m")`            | Terminal style code for bold.
`public static std::string `[`underline`](#dc/d09/group___print_functions_1ga097737edf4c47b879ba1d5496491c99f)`("\4m")`            | Terminal style code for underline.
`public static std::string `[`reset`](#dc/d09/group___print_functions_1gafd29639906f2b68a089fa138ced3573d)`("\0m")`            | Terminal code to reset special formatting.
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printStyle`](#dc/d09/group___print_functions_1ga7ff2bacd4f2a9d135b2aafd98bdbe0c4)`(const T income,const std::string style)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printBlack`](#dc/d09/group___print_functions_1gab6f521475a753414f6bf45078cf48ab5)`(const T income)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printRed`](#dc/d09/group___print_functions_1ga2b4475f05e8cc55937f6e221f405958c)`(const T income)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printGreen`](#dc/d09/group___print_functions_1ga07fa81a8cb8ab7d421b1a800f94d1081)`(const T income)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printYellow`](#dc/d09/group___print_functions_1ga07b54a9f07528dfa7e773d3e3fdff204)`(const T income)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printBlue`](#dc/d09/group___print_functions_1ga9fcad4197880190707a92af69c46bc08)`(const T income)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printMagenta`](#dc/d09/group___print_functions_1gac4e42b689aa599e752e0aea52018e116)`(const T income)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printCyan`](#dc/d09/group___print_functions_1ga78f30d9d4be61d13adcdc82fd5fc2063)`(const T income)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printWhite`](#dc/d09/group___print_functions_1gafcfd509b465c49152eafcde8cc34e070)`(const T income)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printBold`](#dc/d09/group___print_functions_1ga25352c4ec3330619999839da9db08d08)`(const T income)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printUnderline`](#dc/d09/group___print_functions_1gacc772a4b5f8d155be9e51a5f281631e5)`(const T income)`            | #### Parameters
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printAllStyles`](#dc/d09/group___print_functions_1ga7556924152a0169023770c1bc7483798)`()`            | 
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`clearStyles`](#dc/d09/group___print_functions_1gad50537e36fafbcbe00e8266d54def15b)`()`            | 
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveMatrix`](#d3/d61/group___save_functions_1gae8654153fbe57dfa3c2b5de4f170ecad)`(const std::string filename,const std::vector< std::vector< T > > & matrix,std::string comment,const bool transpose,std::string type,std::string delimiter,const std::size_t tokenWidth)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveVector`](#d3/d61/group___save_functions_1ga197b81a404c6975ae1723bdbf09631e8)`(const std::string filename,const std::vector< T > & vector,std::string comment,std::string type,std::string delimiter)`            | #### Parameters
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveLine`](#d3/d61/group___save_functions_1gac4fc9847a1a5f7dfde1fe3e85d114c96)`(const std::string filename,const std::string line,std::string comment)`            | #### Exceptions
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`save`](#d3/d61/group___save_functions_1gaef81b7961fc1be246f6e4a8eb6d1ca49)`(const std::string filename,const std::vector< std::vector< T > > & matrix,std::string comment)`            | 
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`save`](#d3/d61/group___save_functions_1ga8975beceb2982ba69ff101e880378d39)`(const std::string filename,const std::vector< T > & vector,std::string comment)`            | 
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`save`](#d3/d61/group___save_functions_1gaa3e574e06eec5c52773e36dde3054750)`(const std::string filename,const std::string line,std::string comment)`            | 
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveLog`](#d3/d61/group___save_functions_1ga93d532cc68bebde4dfa9ae49f452d73c)`(const std::string filename,std::string log,const bool timestamp,const std::string stampSeparator)`            | #### Exceptions
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveLog`](#d3/d61/group___save_functions_1ga63d2d9249c72ac8cfbe020b5d31a7038)`(const std::string filename,std::vector< std::string > & logs,const bool timestamp,const std::string stampSeparator)`            | #### Exceptions
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`loadA3R`](#d3/d61/group___save_functions_1gaa7fb8088fb5f4ee8be91230cdf349191)`(const std::string filename,std::vector< std::vector< T > > & positions,double & radius)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`saveA3R`](#d3/d61/group___save_functions_1gac06ef8f071a2e9fd43dfd141ffc587b8)`(const std::string filename,const std::vector< std::vector< T > > & positions,const double radius)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`loadXYZ`](#d3/d61/group___save_functions_1gae9ab360f2c606513c0c7760ce8952c01)`(const std::string filename,std::vector< std::vector< T > > & matrix)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveXYZ`](#d3/d61/group___save_functions_1gada3dd60c5633f7c05ca8220fc442a648)`(const std::string filename,const std::vector< std::vector< T > > & matrix,const std::vector< T > & tones,std::string elementName)`            | #### Parameters
`public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveXYZ`](#d3/d61/group___save_functions_1gab5f2ddd8b0db956871224880ec9986b7)`(const std::string filename,const std::vector< std::vector< T > > & matrix,std::string elementName)`            | #### Parameters
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`folderExists`](#df/dae/group___file_functions_1gabdca7c6a359e842551fa1fd59511d95b)`(const std::string name)`            | Check if folder exists.
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::size_t `[`countLinesInFile`](#df/dae/group___file_functions_1gadf09232474a3c9e0da8ca89f9a792abe)`(const std::string filename,const std::string token)`            | 
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::vector< std::string > `[`listFilesWithExtension`](#df/dae/group___file_functions_1gaf94066defcee711b34d5cc712585840b)`(std::string path,const std::string extension,const std::string prefix,const bool addPathToFileNames)`            | 
`public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`execute`](#d9/d59/group___shell_functions_1ga92245db9096637e0aae3d8dcd77a4d3f)`(const std::string command)`            | 

## Members

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`getVersion`](#d5/dd6/group___library_info_1gae81b57260fe20a158b0226ca9b51610e)`()` 

Get version of the library.

This function returns version of the AiLibrary (we use SemVer) 
#### Returns
Version as a string 

**See also**: [https://semver.org](https://semver.org)

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`string`](#d4/d65/group___string_functions_1gac77e5243b1f905e34f4e34214ebc0d47)`(const T value)` 

Converts input into a string.

This function converts your variable into std::string using std::ostringstream 
#### Parameters
* `T` Any printable type 

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

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`toUpperCase`](#d4/d65/group___string_functions_1gafa7403264826a98706779d24c37135f7)`(std::string input)` 

Convert a string to upper case.

This function converts the given string to upper case and returns the result 
#### Parameters
* `input` String to convert 

#### Returns
Uppercase string

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`toLowerCase`](#d4/d65/group___string_functions_1ga8b0ea59a58d4a8fc91a45a9c6b497900)`(std::string input)` 

Convert a string to lower case.

This function converts the given string to lower case and returns the result 
#### Parameters
* `input` String to convert 

#### Returns
Lowercase string

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`prependNumber`](#d4/d65/group___string_functions_1ga558ddc85d7fcebb82d31fdf2f701f24e)`(const T value,const std::size_t symbolsBeforePoint,const char symbolToPrepend)` 

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::size_t `[`counter`](#d3/ddf/group___debug_functions_1ga5ad831a383f32b3f7f66f1259ff239ee)`(const std::size_t value)` 

Returns ID starting from zero or the specified value.

This function returns ID (increases it at each call) starting from zero or the specified non-negative value 
#### Parameters
* `value` Optional. The non-negative value to which the counter should be reset. Zero by default 

#### Returns
Counter value

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`marker`](#d3/ddf/group___debug_functions_1ga345351c64f543f9459af2a4449f59cfe)`(const std::size_t value)` 

Returns a string containing the word "Marker" and its ID.

This function returns a string containing the word "marker" and its ID (increases it at each call). ID specified in the same way as in the function [counter()](#d3/ddf/group___debug_functions_1ga5ad831a383f32b3f7f66f1259ff239ee)
#### Parameters
* `value` Optional. The non-negative value to which the counter should be reset. Zero by default 

#### Returns
Marker string

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printMarker`](#d3/ddf/group___debug_functions_1ga9c430bdce23c1a7e9c9d9de3ce6b4b38)`(const std::size_t value)` 

Calls [marker()](#d3/ddf/group___debug_functions_1ga345351c64f543f9459af2a4449f59cfe) and prints result to stdout.

This function calls [marker()](#d3/ddf/group___debug_functions_1ga345351c64f543f9459af2a4449f59cfe) and prints result to stdout 
#### Parameters
* `value` Optional. The non-negative value to which the counter should be reset. Zero by default

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`sign`](#d5/d12/group___math_functions_1ga59e445549490377e66c6c2719b65cc0e)`(const T value)` 

Returns signum of the value.

This function returns signum of the number value (usign copysign()) 
#### Parameters
* `T` A number type 

#### Parameters
* `value` The number to which signum is applied 

#### Returns
-1 for negative values, +1 for positive, 0 for zero

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`min`](#d5/d12/group___math_functions_1ga4ff9e753d095c1ca70b0ec517b0c919e)`(const T a,const T b)` 

Returns minimum of two values.

This function compares two values and returns a minimum 
#### Parameters
* `T` A number type 

#### Parameters
* `a` First number 

* `b` Second number 

#### Returns
Minimum of two values

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`max`](#d5/d12/group___math_functions_1gab4363f54de7131a1530189fdfb614334)`(const T a,const T b)` 

Returns maximum of two values.

This function compares two values and returns a maximum 
#### Parameters
* `T` A number type 

#### Parameters
* `a` First number 

* `b` Second number 

#### Returns
Maximum of two values

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`min`](#d5/d12/group___math_functions_1gab855a677ddeab67056d5316bc95ef683)`(const std::vector< T > & input)` 

Returns minimum of vector values.

This function compares vector values using [min()](#d5/d12/group___math_functions_1ga4ff9e753d095c1ca70b0ec517b0c919e) and returns a minimum 
#### Parameters
* `T` A number type 

#### Parameters
* `input` Vector to search for a minimum value 

#### Returns
Minimum of vector values

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`max`](#d5/d12/group___math_functions_1ga38d9271ac8875ee2e73f7393e791ad55)`(const std::vector< T > & input)` 

Returns maximum of vector values.

This function compares vector values using [max()](#d5/d12/group___math_functions_1gab4363f54de7131a1530189fdfb614334) and returns a maximum 
#### Parameters
* `T` A number type 

#### Parameters
* `input` Vector to search for a maximum value 

#### Returns
Maximum of vector values

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`min`](#d5/d12/group___math_functions_1gad56ff7c2618a4cb19a5b451663b42394)`(const std::vector< std::vector< T > > & input)` 

Returns minimum of matrix values.

This function compares matrix values using [min()](#d5/d12/group___math_functions_1ga4ff9e753d095c1ca70b0ec517b0c919e) and returns a minimum 
#### Parameters
* `T` A number type 

#### Parameters
* `input` Matrix to search for a minimum value 

#### Returns
Minimum of matrix values

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` T `[`max`](#d5/d12/group___math_functions_1gac41228d2f55e89ea0cbf721d8ee076ff)`(const std::vector< std::vector< T > > & input)` 

Returns maximum of matrix values.

This function compares matrix values using [max()](#d5/d12/group___math_functions_1gab4363f54de7131a1530189fdfb614334) and returns a maximum 
#### Parameters
* `T` A number type 

#### Parameters
* `input` Matrix to search for a maximum value 

#### Returns
Maximum of matrix values

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`isSquare`](#d5/d12/group___math_functions_1gac521d17c2aff565fbc375f2f9c611dcd)`(const T value)` 

Checks if number is square.

This function checks if number is square 
#### Parameters
* `T` A number type 

#### Parameters
* `value` Number to test 

#### Returns
True if number is a square, false otherwise

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`isSquare`](#d5/d12/group___math_functions_1gaa78e52e15c1e9c7de3243ad6791ea8e2)`(const std::vector< std::vector< T > > & matrix)` 

Checks if matrix is square.

This function checks if matrix is square 
#### Parameters
* `T` A number type 

#### Parameters
* `matrix` Matrix to test 

#### Returns
True if matrix is square, false otherwise

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`generateRandomVector`](#d5/d12/group___math_functions_1ga2cf03512823864f49bb5255c97d40ed7)`(std::vector< T > & vector,const std::size_t length,const T min,const T max)` 

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`generateRandomMatrix`](#d5/d12/group___math_functions_1ga5fc76a6aabb72285b3269132e30597a2)`(std::vector< std::vector< T > > & matrix,const std::size_t xSize,const std::size_t ySize,const T min,const T max)` 

Fill matrix with random values.

This function fills the matrix of given sizes with random values using std::random_device and [generateRandomVector()](#d5/d12/group___math_functions_1ga2cf03512823864f49bb5255c97d40ed7)
#### Parameters
* `T` A number type 

#### Parameters
* `matrix` Matrix to fill 

* `xSize` Required length of the matrix 

* `ySize` Required height of the matrix 

* `min` Lower limit of generated values, no limitation by default 

* `max` Upper limit of generated values, no limitation by default

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`generateRandomMatrix`](#d5/d12/group___math_functions_1ga1776f29fc7629ca51c451bf411acb8a5)`(std::vector< std::vector< T > > & matrix,const std::size_t size,const T min,const T max)` 

Fill matrix with random values.

This function fills the square matrix of given sizes with random values using std::random_device and [generateRandomVector()](#d5/d12/group___math_functions_1ga2cf03512823864f49bb5255c97d40ed7)
#### Parameters
* `T` A number type 

#### Parameters
* `matrix` Matrix to fill 

* `size` Required size of the square matrix 

* `min` Lower limit of generated values, no limitation by default 

* `max` Upper limit of generated values, no limitation by default

#### `public template<>`  <br/>`void `[`rotateMatrix`](#d5/d12/group___math_functions_1ga7d70bb658337d2d2b53ff7aef9e75dac)`(std::vector< std::vector< T > > & matrix,const bool rotateClockwise)` 

Rotate square matrix.

This function rotates the square matrix 90 degrees clockwise or anticlockwise 
#### Parameters
* `T` Any copiable type 

#### Parameters
* `matrix` Matrix to rotate 

* `rotateClockwise` Optional. If true, rotate clockwise. Otherwise, rotate anticlockwise (default)

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`inverseMatrix`](#d5/d12/group___math_functions_1ga22896aadb82739145e85dfa39290d14b)`(std::vector< std::vector< T > > matrix,std::vector< std::vector< T > > & inverse)` 

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`inverseMatrix`](#d5/d12/group___math_functions_1gada879df08132090166f65118ae8ca81e)`(std::vector< std::vector< T > > & matrix)` 

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`translateMatrixIntoVector`](#d5/d12/group___math_functions_1ga277c02074c8e0dc2c4ef67b8bc2371ce)`(std::vector< std::vector< T > > & matrix,std::vector< T > & vector)` 

Elongates matrix into a vector.

This function converts the matrix into a vector, writing each row one after another in a line 
#### Parameters
* `T` A number type 

#### Parameters
* `matrix` Matrix to tranform 

* `vector` Vector to store the result

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`translateVectorIntoSquareMatrix`](#d5/d12/group___math_functions_1ga43c134aa8eab9d5edb498016ee891646)`(std::vector< T > & vector,std::vector< std::vector< T > > & matrix)` 

Transform vector into a square matrix (if possible)

This function converts the vector into a matrix, if possible. Otherwise, an exception will be thrown at runtime 
#### Parameters
* `T` A number type 

#### Parameters
* `vector` Vector to tranform 

* `matrix` Matrix to store the result 

#### Exceptions
* `std::runtime_error` If `matrix` is not square

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`generateCirculantMatrix`](#d5/d12/group___math_functions_1ga27a6217153189fe16cf421ab3fe07ca8)`(std::vector< std::vector< T > > & matrix,std::vector< T > & source,const bool moveToTheRight)` 

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`multiply`](#d5/d12/group___math_functions_1ga50bf5a5c329516b044d4553f1dce69e5)`(const std::vector< std::vector< T > > & left,const std::vector< std::vector< T > > & right,std::vector< std::vector< T > > & result)` 

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`multiply`](#d5/d12/group___math_functions_1ga5aa2e148dcac9b79642b3708a501fc8d)`(const std::vector< std::vector< T > > & left,const std::vector< T > & right,std::vector< T > & result)` 

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`multiply`](#d5/d12/group___math_functions_1ga8f0f988a4b13e3b6ad1a6e5d6f4c6f95)`(const std::vector< T > & left,const std::vector< T > & right,T & result)` 

Calculate vector-vector multiplication.

This function calculates vector-vector multiplication 
#### Parameters
* `T` A number type 

#### Parameters
* `left` Left vector to multiply 

* `right` Right vector to multiply 

* `result` Variable to store result 

#### Exceptions
* `std::runtime_error` If input sizes are inappropriate

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`multiplyElementWise`](#d5/d12/group___math_functions_1ga8bc34f17df4fc867bf0eee3de8f6aabb)`(const std::vector< std::vector< T > > & left,const std::vector< std::vector< T > > & right,std::vector< std::vector< T > > & result)` 

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`multiplyElementWise`](#d5/d12/group___math_functions_1gaea3bca561dbdcd13aaf74531a3649319)`(const std::vector< T > & left,const std::vector< T > & right,std::vector< T > & result)` 

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`multiplyComplexElementWise`](#d5/d12/group___math_functions_1gae066365ce568fab84880facf6297b67a)`(const std::vector< std::vector< T > > & left,const std::vector< std::vector< T > > & right,std::vector< std::vector< T > > & result)` 

#### Parameters
* `T` A number type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`complexIntoString`](#d5/d12/group___math_functions_1ga781cfb9e924621b4e18cb0473366d368)`(const std::vector< T > complexValue)` 

#### Parameters
* `T` A number type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`conjugate`](#d5/d12/group___math_functions_1ga6422b6dcd8d8a187a979b8207d2f2243)`(std::vector< std::vector< T > > & complexVector)` 

#### Parameters
* `T` A number type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`fft`](#d5/d12/group___math_functions_1ga46e87531b41eba547be604d1e34b7b27)`(std::vector< std::vector< T > > & complexVector)` 

#### Parameters
* `T` A number type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`ifft`](#d5/d12/group___math_functions_1gaf04c96b76dd1bceb79fecf325838604b)`(std::vector< std::vector< T > > & complexVector)` 

#### Parameters
* `T` A number type

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::chrono::high_resolution_clock::time_point `[`time`](#dd/dd0/group___time_functions_1ga54195a75b5598d4078f9f4cc57628f2b)`()` 

Returns current time point.

This function returns current time point using std::chrono 
#### Returns
std::chrono::high_resolution_clock entity

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::chrono::system_clock::time_point `[`systemTime`](#dd/dd0/group___time_functions_1ga35b9e10e815e1b62585d4c1f07b71faf)`()` 

Returns current time point.

This function returns current time point using std::chrono 
#### Returns
std::chrono::system_clock entity

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` double `[`duration`](#dd/dd0/group___time_functions_1ga2093a6b79f8831e98746f31c6cd66d5c)`(const std::chrono::high_resolution_clock::time_point start,const std::chrono::high_resolution_clock::time_point finish,const std::string scale)` 

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` double `[`duration`](#dd/dd0/group___time_functions_1gac39f52c9c5983eba7db340a5469eaa83)`(const std::chrono::high_resolution_clock::time_point start,const std::string scale)` 

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printDuration`](#dd/dd0/group___time_functions_1gafce472052309d5d843fd24a7fcaad589)`(const std::chrono::high_resolution_clock::time_point start,const std::chrono::high_resolution_clock::time_point finish,const std::string scale,const std::size_t count)` 

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printDuration`](#dd/dd0/group___time_functions_1gaee849e5398ad0b85aee9de35d0f4deb2)`(const std::chrono::high_resolution_clock::time_point start,const std::string scale,const std::size_t count)` 

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`getDateAndTime`](#dd/dd0/group___time_functions_1ga6fd823c420070d11541efef69420011f)`(std::chrono::system_clock::time_point timePoint)` 

Get date and time.

This function converts the given moment to std::string containing the passed date and time 
#### Parameters
* `timePoint` Optional. The moment on the system clock to be converted, the current time by default 

#### Returns
std::string with date and time in the format yyyy.mm.dd HH:MM:SS

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`getDate`](#dd/dd0/group___time_functions_1ga4af5bcf9bf9c84e563cac5f8366e1a22)`(std::chrono::system_clock::time_point timePoint)` 

Get date.

This function converts the given moment to std::string containing the passed date 
#### Parameters
* `timePoint` Optional. The moment on the system clock to be converted, the current time by default 

#### Returns
std::string with date in the format yyyy.mm.dd

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`getTime`](#dd/dd0/group___time_functions_1ga09b52a9378428e8a6127c5605bd79694)`(std::chrono::system_clock::time_point timePoint)` 

Get time.

This function converts the given moment to std::string containing the passed time 
#### Parameters
* `timePoint` Optional. The moment on the system clock to be converted, the current time by default 

#### Returns
std::string with date time in the format HH:MM:SS

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`parseParameter`](#df/dab/group___parameter_functions_1ga2d54d56130ff4b251fd09a33c307d924)`(const char * input,const std::string name)` 

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`assignFromVectorByIntervalCondition`](#df/dab/group___parameter_functions_1ga4de411233451db390ce475f2f3916962)`(T & value,const T parameter,const std::vector< std::vector< T > > intervals)` 

#### Parameters
* `T` Any comparable type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`assignFromVectorByIntervalCondition`](#df/dab/group___parameter_functions_1ga59fc20819b5d0024c784c62bb75bb6b4)`(T & firstValue,T & secondValue,const T parameter,const std::vector< std::vector< T > > intervals)` 

#### Parameters
* `T` Any comparable type

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignBooleanParameter`](#df/dab/group___parameter_functions_1gaf22400542606a991705af80aacd216e7)`(const char * input,const std::string name,bool & value)` 

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignCharParameter`](#df/dab/group___parameter_functions_1ga02eb74222c6c05c9ef731358f3afcc70)`(const char * input,const std::string name,char & value)` 

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignStringParameter`](#df/dab/group___parameter_functions_1ga66fb81eb3a9d18a05eebf2188ebfa7d1)`(const char * input,const std::string name,std::string & value)` 

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignParameter`](#df/dab/group___parameter_functions_1ga39965300f2ee700f23af9cfb984a4dab)`(const char * input,const std::string name,T & value)` 

#### Parameters
* `T` Any printable type

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignAbsDoubleParameter`](#df/dab/group___parameter_functions_1ga4034a69ed57b29d70857115c16e36074)`(const char * input,const std::string name,double & value)` 

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`assignByCheckingParameter`](#df/dab/group___parameter_functions_1gaca17fe10d6c287a14c243e674df8b87f)`(const char * input,const std::string parameter,T & value,const T supposed)` 

#### Parameters
* `T` Any type

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`clearScreen`](#d2/dbc/group___interface_functions_1gaf19bb9cf544cb5bc7a010b9e6693ebf7)`()` 

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`setLocale`](#d2/dbc/group___interface_functions_1ga1f7fff63e38f3ce8ccc98f3a47c42a1c)`(const std::string locale)` 

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`showProgressBar`](#d2/dbc/group___interface_functions_1ga1763f8f8d0df5cae7fbf79e18a0d20c3)`(double progress,const int screenWidth)` 

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printLine`](#d2/dbc/group___interface_functions_1ga5a0c49b9088cdfaf6749cdfc7d0a8628)`(const std::string line,const int screenWidth)` 

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`parseFileInMatrix`](#df/d73/group___read_functions_1gae9d45625612ddcd2581e26843f141213)`(const std::string filename,const char separator,std::vector< std::vector< T > > & matrix)` 

#### Parameters
* `T` Any printable type 

#### Exceptions
* `std::runtime_error` If file could not be open

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`parseFileInVector`](#df/d73/group___read_functions_1ga90ae1cfa3d587cdd7d5cb1db70f2621f)`(const std::string filename,const char separator,std::vector< T > & vector)` 

#### Parameters
* `T` Any printable type 

#### Exceptions
* `std::runtime_error` If file could not be open

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`parseFileIntoString`](#df/d73/group___read_functions_1gac8b3d3c1db1973ae2d57265e435d2066)`(const std::string filename,std::string & content)` 

#### Exceptions
* `std::runtime_error` If file could not be open

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`accumulateFileInMatrix`](#df/d73/group___read_functions_1ga9ad08eb45ba0cb425d25e8644bc33a69)`(const std::string filename,const char separator,std::vector< std::vector< T > > & matrix)` 

#### Parameters
* `T` A number type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`accumulateFileInVector`](#df/d73/group___read_functions_1ga6dc3993c11c7e8af3c3847b1efbe7a4b)`(const std::string filename,const char separator,std::vector< T > & vector,const bool checkForNaN)` 

#### Parameters
* `T` A number type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printMatrix`](#dc/d09/group___print_functions_1ga2cfb640704df7c1b859c440482d26ffe)`(const std::vector< std::vector< T > > & matrix,const bool transpose,const int precision)` 

#### Parameters
* `T` Any printable type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printVector`](#dc/d09/group___print_functions_1gaf8a54b522733a2ef8f15be72b715189e)`(const std::vector< T > & vector,const int precision)` 

#### Parameters
* `T` Any printable type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`print`](#dc/d09/group___print_functions_1ga65fd54001ef1807b57d277ce02342320)`(const std::vector< std::vector< T > > & matrix,const bool transpose,const int precision)` 

#### Parameters
* `T` Any printable type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`print`](#dc/d09/group___print_functions_1gadd02d38ccafa18ef83b6c4b8cb3c0e6d)`(const std::vector< T > & vector,const int precision)` 

#### Parameters
* `T` Any printable type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`print`](#dc/d09/group___print_functions_1ga220a82c64afd994f2b3df3ec62a191b0)`(const T value,const std::string name)` 

#### Parameters
* `T` Any printable type

#### `public static std::string `[`black`](#dc/d09/group___print_functions_1gabfd87c66472aeceefdb7160941151984)`("\30m")` 

Terminal color code for black.

This terminal control sequences sets black font color

#### `public static std::string `[`red`](#dc/d09/group___print_functions_1gad99c58f6ae82527a3b8b7623aaed1dda)`("\31m")` 

Terminal color code for red.

This terminal control sequences sets red font color

#### `public static std::string `[`green`](#dc/d09/group___print_functions_1ga6ba6ceca5f659cd8eb528255d9a06d89)`("\32m")` 

Terminal color code for green.

This terminal control sequences sets green font color

#### `public static std::string `[`yellow`](#dc/d09/group___print_functions_1gaafa6d780856c3981c59dff706ab3a779)`("\33m")` 

Terminal color code for yellow.

This terminal control sequences sets yellow font color

#### `public static std::string `[`blue`](#dc/d09/group___print_functions_1ga01e5278053d7b4fcef7ed016636fda53)`("\34m")` 

Terminal color code for blue.

This terminal control sequences sets blue font color

#### `public static std::string `[`magenta`](#dc/d09/group___print_functions_1ga79ac3cbc99ea2004650b1f146b7ca594)`("\35m")` 

Terminal color code for magenta.

This terminal control sequences sets magenta font color

#### `public static std::string `[`cyan`](#dc/d09/group___print_functions_1ga009e72aadeaea320f5b4caeaa75ca5cc)`("\36m")` 

Terminal color code for cyan.

This terminal control sequences sets cyan font color

#### `public static std::string `[`white`](#dc/d09/group___print_functions_1gabec8a45ab6396d631ceb8cb735898db0)`("\37m")` 

Terminal color code for white.

This terminal control sequences sets white font color

#### `public static std::string `[`bold`](#dc/d09/group___print_functions_1ga5d203a3b01eb3ddd02d16c44a4d0a0ac)`("\1m")` 

Terminal style code for bold.

This terminal control sequences sets bold font style

#### `public static std::string `[`underline`](#dc/d09/group___print_functions_1ga097737edf4c47b879ba1d5496491c99f)`("\4m")` 

Terminal style code for underline.

This terminal control sequences sets underline font style

#### `public static std::string `[`reset`](#dc/d09/group___print_functions_1gafd29639906f2b68a089fa138ced3573d)`("\0m")` 

Terminal code to reset special formatting.

This terminal control sequences resets font to the default state

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printStyle`](#dc/d09/group___print_functions_1ga7ff2bacd4f2a9d135b2aafd98bdbe0c4)`(const T income,const std::string style)` 

#### Parameters
* `T` Any printable type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printBlack`](#dc/d09/group___print_functions_1gab6f521475a753414f6bf45078cf48ab5)`(const T income)` 

#### Parameters
* `T` Any printable type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printRed`](#dc/d09/group___print_functions_1ga2b4475f05e8cc55937f6e221f405958c)`(const T income)` 

#### Parameters
* `T` Any printable type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printGreen`](#dc/d09/group___print_functions_1ga07fa81a8cb8ab7d421b1a800f94d1081)`(const T income)` 

#### Parameters
* `T` Any printable type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printYellow`](#dc/d09/group___print_functions_1ga07b54a9f07528dfa7e773d3e3fdff204)`(const T income)` 

#### Parameters
* `T` Any printable type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printBlue`](#dc/d09/group___print_functions_1ga9fcad4197880190707a92af69c46bc08)`(const T income)` 

#### Parameters
* `T` Any printable type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printMagenta`](#dc/d09/group___print_functions_1gac4e42b689aa599e752e0aea52018e116)`(const T income)` 

#### Parameters
* `T` Any printable type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printCyan`](#dc/d09/group___print_functions_1ga78f30d9d4be61d13adcdc82fd5fc2063)`(const T income)` 

#### Parameters
* `T` Any printable type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printWhite`](#dc/d09/group___print_functions_1gafcfd509b465c49152eafcde8cc34e070)`(const T income)` 

#### Parameters
* `T` Any printable type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printBold`](#dc/d09/group___print_functions_1ga25352c4ec3330619999839da9db08d08)`(const T income)` 

#### Parameters
* `T` Any printable type

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printUnderline`](#dc/d09/group___print_functions_1gacc772a4b5f8d155be9e51a5f281631e5)`(const T income)` 

#### Parameters
* `T` Any printable type

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`printAllStyles`](#dc/d09/group___print_functions_1ga7556924152a0169023770c1bc7483798)`()` 

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`clearStyles`](#dc/d09/group___print_functions_1gad50537e36fafbcbe00e8266d54def15b)`()` 

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveMatrix`](#d3/d61/group___save_functions_1gae8654153fbe57dfa3c2b5de4f170ecad)`(const std::string filename,const std::vector< std::vector< T > > & matrix,std::string comment,const bool transpose,std::string type,std::string delimiter,const std::size_t tokenWidth)` 

#### Parameters
* `T` Any printable type 

#### Exceptions
* `std::runtime_error` If file could not be open

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveVector`](#d3/d61/group___save_functions_1ga197b81a404c6975ae1723bdbf09631e8)`(const std::string filename,const std::vector< T > & vector,std::string comment,std::string type,std::string delimiter)` 

#### Parameters
* `T` Any printable type 

#### Exceptions
* `std::runtime_error` If file could not be open

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveLine`](#d3/d61/group___save_functions_1gac4fc9847a1a5f7dfde1fe3e85d114c96)`(const std::string filename,const std::string line,std::string comment)` 

#### Exceptions
* `std::runtime_error` If file could not be open

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`save`](#d3/d61/group___save_functions_1gaef81b7961fc1be246f6e4a8eb6d1ca49)`(const std::string filename,const std::vector< std::vector< T > > & matrix,std::string comment)` 

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`save`](#d3/d61/group___save_functions_1ga8975beceb2982ba69ff101e880378d39)`(const std::string filename,const std::vector< T > & vector,std::string comment)` 

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`save`](#d3/d61/group___save_functions_1gaa3e574e06eec5c52773e36dde3054750)`(const std::string filename,const std::string line,std::string comment)` 

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveLog`](#d3/d61/group___save_functions_1ga93d532cc68bebde4dfa9ae49f452d73c)`(const std::string filename,std::string log,const bool timestamp,const std::string stampSeparator)` 

#### Exceptions
* `std::runtime_error` If file could not be open

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveLog`](#d3/d61/group___save_functions_1ga63d2d9249c72ac8cfbe020b5d31a7038)`(const std::string filename,std::vector< std::string > & logs,const bool timestamp,const std::string stampSeparator)` 

#### Exceptions
* `std::runtime_error` If file could not be open

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`loadA3R`](#d3/d61/group___save_functions_1gaa7fb8088fb5f4ee8be91230cdf349191)`(const std::string filename,std::vector< std::vector< T > > & positions,double & radius)` 

#### Parameters
* `T` A number type 

#### Exceptions
* `std::runtime_error` If file could not be open

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`saveA3R`](#d3/d61/group___save_functions_1gac06ef8f071a2e9fd43dfd141ffc587b8)`(const std::string filename,const std::vector< std::vector< T > > & positions,const double radius)` 

#### Parameters
* `T` A number type 

#### Exceptions
* `std::runtime_error` If file could not be open

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`loadXYZ`](#d3/d61/group___save_functions_1gae9ab360f2c606513c0c7760ce8952c01)`(const std::string filename,std::vector< std::vector< T > > & matrix)` 

#### Parameters
* `T` Any printable type 

#### Exceptions
* `std::runtime_error` If file could not be open 

**See also**: [https://en.wikipedia.org/wiki/XYZ_file_format](https://en.wikipedia.org/wiki/XYZ_file_format)

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveXYZ`](#d3/d61/group___save_functions_1gada3dd60c5633f7c05ca8220fc442a648)`(const std::string filename,const std::vector< std::vector< T > > & matrix,const std::vector< T > & tones,std::string elementName)` 

#### Parameters
* `T` A number type 

#### Exceptions
* `std::runtime_error` If file could not be open

#### `public template<>`  <br/>[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` void `[`saveXYZ`](#d3/d61/group___save_functions_1gab5f2ddd8b0db956871224880ec9986b7)`(const std::string filename,const std::vector< std::vector< T > > & matrix,std::string elementName)` 

#### Parameters
* `T` Any printable type

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` bool `[`folderExists`](#df/dae/group___file_functions_1gabdca7c6a359e842551fa1fd59511d95b)`(const std::string name)` 

Check if folder exists.

This function checks if the given directory actually exists 
#### Parameters
* `name` Path to the folder 

#### Returns
True if folder exists, false otherwise

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::size_t `[`countLinesInFile`](#df/dae/group___file_functions_1gadf09232474a3c9e0da8ca89f9a792abe)`(const std::string filename,const std::string token)` 

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::vector< std::string > `[`listFilesWithExtension`](#df/dae/group___file_functions_1gaf94066defcee711b34d5cc712585840b)`(std::string path,const std::string extension,const std::string prefix,const bool addPathToFileNames)` 

#### `public `[`INLINE`](#de/d9e/ai_8hh_1a2eb6f9e0395b47b8d5e3eeae4fe0c116)` std::string `[`execute`](#d9/d59/group___shell_functions_1ga92245db9096637e0aae3d8dcd77a4d3f)`(const std::string command)` 

Generated by [Moxygen](https://sourcey.com/moxygen)