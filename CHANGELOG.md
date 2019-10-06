# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [1.4.0] - 2019-10

Today we pass the 100K symbols mark! (yep, I count comments also, blame me)

### Added
- Macros: `forN`, `forS`
- File functions: `fileExists`, `exists`, `isFolder`, `isFile`
- String functions: `applyRepeat`, `repeat`, `split`, `stringToHex`, `stringFromHex`
- Math functions: `c`, `g`, `epsilon`, `fill`, `negate`, `sum`, `average`, `round`, `gaussElimination`, `randomReal`, `randomInteger`, `randomIndex`, `random`, `getRandomIndex`, `getRandomElement`
- Time functions: `sleep`, `getTimeAndDate`
- Print functions: `info`, `warning`, `error`, `redirectCoutToFile`, `restoreCoutFromFile`, `killCout`

### Changed
- Now `print` functions allow to specify the name of your variable
- Functions `parseFileInMatrix`, `parseFileInVector`, `accumulateFileInMatrix`, `accumulateFileInVector` allow to skip N first lines when reading a file (comment lines are also counted)
- Use std::mt19937 for `generateRandomVector` and `generateRandomMatrix`
- Set precision when use `saveMatrix` and `saveVector`

### Fixed
- Matrix with different column lengths was killing `saveMatrix` when transposing
- Empty vector was killing `saveVector`
- Size check in `fft` could give a warning
- Properly work with negative values in `prependNumber`

## [1.3.0] - 2019-02-10

### Added
- Macros: `STRINGIFY`, `TO_STRING`, `PRINT_LINE`
- String functions: `toUpperCase`, `toLowerCase`, `prependNumber`
- Math functions: `e`, `pi`, `rotateMatrix`, `inverseMatrix`, `generateCirculantMatrix`, `multiply`, `multiplyElementWise`, `multiplyComplexElementWise`, `complexIntoString`, `conjugate`, `fft`, `ifft`
- Time functions: `systemTime`, `printDuration`, `getDateAndTime`, `getDate`, `getTime`
- Interface functions: `clearScreen`, `setLocale`
- Print functions: `print`, `black`, `red`, `green`, `yellow`, `blue`, `magenta`, `cyan`, `white`, `bold`, `underline`, `reset`, `printStyle`, `printBlack`, `printRed`, `printGreen`, `printYellow`, `printBlue`, `printMagenta`, `printCyan`, `printWhite`, `printBold`, `printUnderline`, `printAllStyles`, `clearStyles`
- Save functions: `save`, `saveLog`, `loadA3R`, `loadXYZ`, `saveXYZ`

### Changed
- Now `duration` supports hours, minutes and nanoseconds
- The third parameter for `saveMatrix` is `transpose` now
- Replace `pragma once` with `if defined`
- Define special variables to access `listFilesWithExtension` and `execute`

## [1.2.0] - 2018-08-17

### Added
- String functions: `equal`, `applyReplace`
- Math functions: `isSquare`, `generateRandomVector`, `generateRandomMatrix`, `translateMatrixIntoVector`, `translateVectorIntoSquareMatrix`
- Parameter function: `assignByCheckingParameter`
- `AI_FUTURE` section

### Changed
- Change comments to create docs with
- Replace `inline` with a defined `INLINE`
- Add `INLINE` status to all the functions (for now)
- Now `printLine` throws an exception if screen width is less than 20 just like `showProgressBar`

### Fixed
- Functions `counter` and `marker` no londer increase value right after reset

## [1.1.0] - 2018-08-06

### Added
- `min` functions to correspond with `max`
- Debug functions: `counter`, `marker`, `printMarker`
- String functions: `contains`, `replace`
- Parameter functions: `parseParameter`, `assignBooleanParameter`, `assignCharParameter`, `assignParameter`
- Read functions: `parseFileIntoString`, `accumulateFileInMatrix`, `accumulateFileInVector`
- Save function: `saveA3R`
- File functions: `countLinesInFile`, `listFilesWithExtension`
- Shell function: `execute`

## 1.0.0 - 2018-06-24

Original release

[Unreleased]: https://github.com/starobinskii/ailibrary/compare/v1.4.0...HEAD
[1.4.0]: https://github.com/starobinskii/ailibrary/compare/v1.3.0...v1.4.0
[1.3.0]: https://github.com/starobinskii/ailibrary/compare/v1.2.0...v1.3.0
[1.2.0]: https://github.com/starobinskii/ailibrary/compare/v1.1.0...v1.2.0
[1.1.0]: https://github.com/starobinskii/ailibrary/compare/v1.0...v1.1.0