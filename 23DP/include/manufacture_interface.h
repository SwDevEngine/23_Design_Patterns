#pragma once
#include "props.h"

class ManufactureInterface
{
public:
	virtual int SetFunc(ProcessProps prop) = 0;
	virtual int GetFunc(ProcessProps prop) = 0;
	virtual int Process(ProcessProps prop) = 0;

	virtual ~ManufactureInterface() {}
};