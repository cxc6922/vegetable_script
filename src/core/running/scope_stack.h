#ifndef VEGETABLE_SCRIPT_CORE_RUNNING_SCOPE_MANAGER_H_
#define VEGETABLE_SCRIPT_CORE_RUNNING_SCOPE_MANAGER_H_

#include <memory>
#include <map>
#include <string>
#include "../ast/all.h"
#include "./scope.h"

namespace vegetable_script {

class ScopeStack {
 public:
  ScopeStack();

  operator Scope::Ptr() { return scope_; }

  operator Scope*() { return scope_.get(); }

  void PutDefinition(std::string name, Definition::Ptr definition);

  void PutVariable(std::string name, double value);

  Definition::Ptr GetDefinition(std::string name);

  double GetVariable(std::string name);

  bool VariableExists(std::string name);

  void PushScope();

  void PushScope(Scope::Ptr scope);

  bool PopScope();

  Scope::Ptr scope() { return scope_; }

 private:
  Scope::Ptr scope_;
};

}  // namespace vegetable_script

#endif  // VEGETABLE_SCRIPT_CORE_RUNNING_SCOPE_MANAGER_H_
