# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).


## [1.2.0] - 2018-08-17

### Added
- String functions: `equal`, `applyReplace`.
- Math functions: `isSquare`, `generateRandomVector`, `generateRandomMatrix`, `translateMatrixIntoVector`, `translateVectorIntoSquareMatrix`.
- Parameter function: `assignByCheckingParameter`.
- Add `AI_FUTURE` section

### Changed
- Change comments to create docs with
- Replaced `inline` with a defined `INLINE`
- Add `INLINE` status to all the functions (for now)
- Now `printLine` throws an exception if screen width is less than 20 just like `showProgressBar`.
- Fix: functions `counter` and `marker` no londer increase value right after reset

## [1.1.0] - 2018-08-06

### Added
- `min` functions to correspond with `max`.
- Debug functions: `counter`, `marker`, `printMarker`.
- String functions: `contains`, `replace`.
- Parameter functions: `parseParameter`, `assignBooleanParameter`, `assignCharParameter`, `assignParameter`.
- Read functions: `parseFileIntoString`, `accumulateFileInMatrix`, `accumulateFileInVector`.
- Save function: `saveA3R`.
- File functions: `countLinesInFile`, `listFilesWithExtension`.
- Shell function: `execute`.

[1.2.0]: https://github.com/olivierlacan/keep-a-changelog/compare/v1.2.0...HEAD
[1.1.0]: https://github.com/olivierlacan/keep-a-changelog/compare/v1.1.0...v1.2.0
[1.0]: https://github.com/olivierlacan/keep-a-changelog/compare/v1.0...v1.1.0