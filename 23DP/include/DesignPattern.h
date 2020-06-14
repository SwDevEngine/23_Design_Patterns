#pragma once
#include <array>
#include "manufacture_interface.h"

class DesignPattern;
typedef int (DesignPattern::*DesignPatternProcessFunc)();
class DesignPattern final : public ManufactureInterface
{
public:
	DesignPattern();
	~DesignPattern();

	int SetFunc(ProcessProps) override;
	int GetFunc(ProcessProps) override;
	int Process(ProcessProps) override;

private:
	int init();
	int test_case_1();

	bool init_done_;
	std::array<DesignPatternProcessFunc, kProcessPropsMax> process_func_;
};