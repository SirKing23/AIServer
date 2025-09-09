

#include <iostream>
#include "AIConnector.h"


AIConnector::AIConnector() : initialized(false)
{
    // Initialize Python interpreter
    Py_Initialize();
    if (Py_IsInitialized()) {
        initialized = true;
        std::cout << "Python interpreter initialized successfully.\n";
    }
    else {
        std::cerr << "Failed to initialize Python interpreter.\n";
    }
}

AIConnector::~AIConnector()
{
    if (initialized) {
        Py_Finalize();
        std::cout << "Python interpreter finalized.\n";
    }
}

std::string AIConnector::callPythonStringFunction(const std::string& moduleName, const std::string& functionName, const std::string& inputString)
{
    if (!initialized) {
        std::cerr << "Python not initialized.\n";
        return "";
    }
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\"../py_scripts\")");  // adjust path

    PyObject* pName = PyUnicode_DecodeFSDefault(moduleName.c_str());
    PyObject* pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule == nullptr) {
        PyErr_Print();
        std::cerr << "Failed to load module: " << moduleName << std::endl;
        return "";
    }

    PyObject* pFunc = PyObject_GetAttrString(pModule, functionName.c_str());

    if (!pFunc || !PyCallable_Check(pFunc)) {
        if (PyErr_Occurred()) PyErr_Print();
        std::cerr << "Cannot find function: " << functionName << std::endl;
        Py_DECREF(pModule);
        return "";
    }

    PyObject* pArgs = PyTuple_New(1);
    PyObject* pValue = PyUnicode_FromString(inputString.c_str());
    PyTuple_SetItem(pArgs, 0, pValue);

    PyObject* pResult = PyObject_CallObject(pFunc, pArgs);
    Py_DECREF(pArgs);
    Py_DECREF(pFunc);
    Py_DECREF(pModule);

    if (pResult == nullptr) {
        PyErr_Print();
        std::cerr << "Call failed\n";
        return "";
    }

    std::string result;
    if (PyUnicode_Check(pResult)) {
        const char* str = PyUnicode_AsUTF8(pResult);
        if (str) {
            result = str;
        }
    }

    Py_DECREF(pResult);
    return result;
}




int main()
{
    AIConnector myAI;

std::string inputstr = "hello";
std::string outputStr = myAI.callPythonStringFunction("strings.py", "reverse_string", inputstr);
std::cout << outputStr;

}