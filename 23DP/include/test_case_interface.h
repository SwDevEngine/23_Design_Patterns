#pragma once
#include "props.h"

class TestCaseInterface
{
public:
	TestCaseInterface() {}
	virtual ~TestCaseInterface() {}
	virtual int PostTestCase(TestCaseProps prop) = 0;
};