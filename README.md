<div align="center">
<img height="250" src="https://raw.githubusercontent.com/libhal/.github/main/profile/logo.png">
</div>

# libhal-library

[![✅ Checks](https://github.com/libhal/libhal-library/actions/workflows/ci.yml/badge.svg)](https://github.com/libhal/libhal-library/actions/workflows/ci.yml)
[![Coverage](https://libhal.github.io/libhal-library/coverage/coverage.svg)](https://libhal.github.io/libhal-library/coverage/)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/b084e6d5962d49a9afcb275d62cd6586)](https://www.codacy.com/gh/libhal/libhal-library/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=libhal/libhal-library&amp;utm_campaign=Badge_Grade)
[![GitHub stars](https://img.shields.io/github/stars/libhal/libhal-library.svg)](https://github.com/libhal/libhal-library/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/libhal/libhal-library.svg)](https://github.com/libhal/libhal-library/network)
[![GitHub issues](https://img.shields.io/github/issues/libhal/libhal.svg)](https://github.com/libhal/libhal/issues)
[![Latest Version](https://libhal.github.io/libhal-library/latest_version.svg)](https://github.com/libhal/libhal-library/blob/main/conanfile.py)
[![ConanCenter Version](https://repology.org/badge/version-for-repo/conancenter/libhal-library.svg)](https://conan.io/center/libhal-library)

Replace the contents below with the README information for your library.

This is a template library for libhal drivers. It can be used for processor,
target, device, utility and interface libraries. In order to use it, you'll
need to rename every instance of library to the appropriate name. Places to
rename "library" are in the following files:

```
├── LICENSE
├── 👉 README.md
├── 👉 conanfile.py
├── datasheets
│   └── 📛 put_datasheets_here.md
├── demos
│   ├── 👉 CMakeLists.txt
│   ├── applications
│   │   └── 📛 library.cpp
│   ├── 👉 conanfile.txt
│   ├── hardware_map.hpp
│   ├── main.cpp
│   ├── newlib.cpp
│   └── targets
│       ├── lpc4074
│       │   ├── 👉 initializer.cpp
│       │   └── libhal.tweaks.hpp
│       └── lpc4078
│           ├── 👉 initializer.cpp
│           └── libhal.tweaks.hpp
├── docs
│   ├── _config.yml
│   ├── doxygen
│   │   ├── doxygen-awesome-darkmode-toggle.js
│   │   ├── doxygen-awesome-fragment-copy-button.js
│   │   ├── doxygen-awesome-paragraph-link.js
│   │   ├── doxygen-awesome-sidebar-only-darkmode-toggle.css
│   │   ├── doxygen-awesome-sidebar-only.css
│   │   ├── doxygen-awesome.css
│   │   ├── header.html
│   │   └── mainpage.md
│   ├── doxygen.conf
│   └── example_pages
│       ├── hello_world.html
│       └── hello_world.txt
├── include
│   └── 📛 libhal-library
│       └── 📛 library.hpp
├── test_package
│   ├── 👉 CMakeLists.txt
│   ├── conanfile.py
│   ├── libhal.tweaks.hpp
│   └── main.cpp
└── tests
    ├── 👉 CMakeLists.txt
    ├── 👉 conanfile.txt
    ├── libhal.tweaks.hpp
    ├── 📛 library.test.cpp
    ├── main.test.cpp
    └── run.sh
```

* 👉 = Rename instances of "library" to your library name
* 📛 = Same as 👉 but also rename the file
* ✍️  = Means to update these files with the correct information needed

To see more information about how to setup the library see the documentation
at:

- For Device Libraries: https://libhal.github.io/how-to/device/
- For Target Libraries: https://libhal.github.io/how-to/target/
- For Utility Libraries: https://libhal.github.io/how-to/utility/
- For Processor Libraries: ❌ _not available at the moment_
- For Soft Driver Libraries: ❌ _not available at the moment_
