#include "OperationStack.h"

void OperationStack::pushOperation(const string& op) { operations.push(op); }

string OperationStack::popOperation() {
    if (operations.empty()) return "";
    string op = operations.top();
    operations.pop();
    return op;
}

string OperationStack::undoLast() {
    return popOperation();
}
