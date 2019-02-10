# AiLibrary
This is a single-header C++ Library from Ailurus Studio that brings you extra time to admire life instead of coding the same functions again and again.

But try not to forget that with great power comes great responsibility.

## Integration

[`ai.hh`](https://github.com/starobinskii/AiLibrary/blob/master/ai.hh) is the single header. Install it with simple `make install` from a [release](https://github.com/starobinskii/AiLibrary/releases) or using one of the package managers below. You need to add

```cpp
#include <ai>
```

to the files you want to upgrade with ai.hh functions and set the necessary switches to enable C++11 (e.g., `-std=c++11` for GCC and Clang).

### Package Managers

If you are using OS X and [Homebrew](https://brew.sh), just type `brew tap starobinskii/AiLibrary` and `brew install AiLibrary` and you're set. If you want the bleeding edge rather than the latest release, use `brew install AiLibrary --HEAD`.

On Linux you can get Homebrew too! See [Linuxbrew](http://linuxbrew.sh) and use the very same commands to install AiLibrary.

If you are using the [Spancraft](https://snapcraft.io), install with ease by typing `span install ailibrary`.

Also we are looking forward to add our package to [Spack](https://www.spack.io/) and some other managers.

## Documentation
The docs can be found [here](https://starobinskii.github.io/AiLibrary/docs/) (created using [Doxygen](http://www.doxygen.nl)). Do not hesitate to contact us by email `dev@ailurus.ru` if you have questions.

For changes between versions see the [CHANGELOG.md](CHANGELOG.md).

## Tests

We have found [Catch2](https://github.com/catchorg/Catch2) pretty useful to test this library. To run the existing tests type `./Scripts/test.sh`.

Do not forget to install the library before testing.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/starobinskii/AiLibrary/tags). 

## Authors

* **Egor Starobinskii** - *Initial work* - [starobinskii](https://github.com/starobinskii)
* **Nikita Mushchak** - *Fast Fourier Trasfromt (FFT)* - [NikitaMushchak](https://github.com/NikitaMushchak)

See also the list of [contributors](https://github.com/starobinskii/AiLibrary/contributors) who participated in this project.

## License

This project is licensed under the BSD 3-Clause License - see the [LICENSE.md](LICENSE.md) file for details