#pragma once
#include <array>
#include "manufacture_interface.h"

class StandardTemplateLib;
typedef int (StandardTemplateLib::*StandardTemplateLibProcessFunc)();
class StandardTemplateLib final : public ManufactureInterface
{
public:
	StandardTemplateLib();
	~StandardTemplateLib();

	int SetFunc(ProcessProps) override;
	int GetFunc(ProcessProps) override;
	int Process(ProcessProps) override;

private:
	int init();
	int test_case_1();

	bool init_done_;
	std::array<StandardTemplateLibProcessFunc, kProcessPropsMax> process_func_;
};
