#pragma once

#include "executor/executor.h"
#include "loader/loader.h"
#include "vm/result.h"

class RegressionTester {
public:
  RegressionTester() = default;
  ~RegressionTester() = default;

  /// Functions to set expect results.
  bool setExpectResult(SSVM::Result &Res);

  /// Functions to set inputs.
  bool setFilePath(const std::string &FilePath);

  /// Functions for running.
  bool runLoader();
  bool runExecutor();
  bool checkResult();

private:
  Loader::Loader LoaderEngine;
  Executor::Executor ExecutorEngine;
  std::unique_ptr<AST::Module> OutModule;
  std::string WasmPath;
  SSVM::Result InitResult;
  SSVM::Result ExpectResult;
};
