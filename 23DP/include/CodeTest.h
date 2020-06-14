#pragma once
#include <array>
#include "manufacture_interface.h"

class CodeTest;
typedef int (CodeTest::*Func)();
class CodeTest final : public ManufactureInterface
{
public:
	CodeTest();
	~CodeTest();

	int SetFunc(ProcessProps) override;
	int GetFunc(ProcessProps) override;
	int Process(ProcessProps) override;

private:
	int init();
	int test_case_1();

	bool init_done_;
	std::array<Func, kProcessPropsMax> process_func_;
};