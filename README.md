# libhal-library

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
