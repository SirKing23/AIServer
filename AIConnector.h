#pragma once
#ifdef _DEBUG
#undef _DEBUG
#include <Python.h>
#define _DEBUG
#else
#include <Python.h>
#endif
// code above is declared because the python312.lib is release version
//we cant run this file because we are in debug mode 
#include <iostream>
#include <string>
#include <vector>



class AIConnector
{
private:
	bool initialized;

public:
	AIConnector();
	virtual ~AIConnector();

	bool isInitialized() const
	{
		return initialized;
	}

	std::string callPythonStringFunction(const std::string& moduleName, const std::string& functionName, const std::string& inputString);

};