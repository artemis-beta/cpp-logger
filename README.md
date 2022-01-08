# Logger

[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=artemis-beta_cpp-logger&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=artemis-beta_cpp-logger)

This project is mirrored from the `PKTools-cpp` repository, I realise how useful loggers are within Python so decided to construct a similar object within C++.

## Usage

There are six levels of logging: `Fatal`, `Critical`, `Error`, `Warning`, `Info` and `Debug`. All of these are called in an identical manner:

```
Logger my_logger;
my_logger.Info("Running operation on value '%s'", my_val); // Arguments are represented using integers "%s" 
...
my_logger.Error("Failed to complete operation");
```
