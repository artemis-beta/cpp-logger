# Logger

This project is mirrored from the `PKTools-cpp` repository, I realise how useful loggers are within Python so decided to construct a similar object within C++. Usage of this logger requires the Boost library.

## Usage

There are six levels of logging: `Fatal`, `Critical`, `Error`, `Warning`, `Info` and `Debug`. All of these are called in an identical manner:

```
Logger my_logger;
my_logger.Info("Running operation on value '%1%'", my_val); // Arguments are represented using %var%
...
my_logger.Error("Failed to complete operation");
```
