#ifndef OPERATIONSTACK_H
#define OPERATIONSTACK_H

#include <stack>
#include <string>
using namespace std;

class OperationStack {
    stack<string> operations;
public:
    void pushOperation(const string&);
    string popOperation();
    string undoLast();
};

#endif
