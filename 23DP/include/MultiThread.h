#pragma once
#include <array>
#include "manufacture_interface.h"

class MultiThread;
typedef int (MultiThread::*MultiThreadProcessFunc)();
class MultiThread final : public ManufactureInterface
{
public:
	MultiThread();
	~MultiThread();

	int SetFunc(ProcessProps) override;
	int GetFunc(ProcessProps) override;
	int Process(ProcessProps) override;

private:
	int init();
	int test_case_1();

	bool init_done_;
	std::array<MultiThreadProcessFunc, kProcessPropsMax> process_func_;
};

