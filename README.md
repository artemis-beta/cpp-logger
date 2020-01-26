# Logger

This project is mirrored from the `PKTools-cpp` repository, I realise how useful loggers are within Python so decided to construct a similar object within C++. Usage of this requires the Boost library, the location of the boost header files should be included when compiling, e.g.:

```
$ export BOOSTINCLUDE=/usr/include/
$ g++ my_project.cxx -I $BOOSTINCLUDE -o my_project
```

alternatively you can include reference to the included `CMakeLists.txt` contained within this repository, the variable `BOOSTINCLUDE` will still need to be set.
