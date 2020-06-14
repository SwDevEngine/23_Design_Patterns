#include <iostream>
#include "DesignPattern.h"

DesignPattern::DesignPattern() : init_done_(false)
{
	printf("%s\n", __FUNCTION__);
	if (init())
		printf("%s: failed to init", __FUNCTION__);
	else
		init_done_ = true;
}

DesignPattern::~DesignPattern()
{
	printf("%s\n", __FUNCTION__);
}

int DesignPattern::init() {
	process_func_[kCodeTest_1] = &DesignPattern::test_case_1;
	return 0;
}

int DesignPattern::SetFunc(ProcessProps)
{
	printf("%s\n", __FUNCTION__);
	return 0;
}

int DesignPattern::GetFunc(ProcessProps)
{
	printf("%s\n", __FUNCTION__);
	return 0;
}

int DesignPattern::Process(ProcessProps prop)
{
	printf("%s\n", __FUNCTION__);
	if (!init_done_ && prop >= kProcessPropsMax) {
		printf("%s: not init this obj\n", __FUNCTION__);
		return -EINVAL;
	}

	int ret = (this->*process_func_[prop])();
	if (ret)
		printf("%s: failed to process prop", __FUNCTION__);
	return ret;
}

int DesignPattern::test_case_1()
{
	printf("%s\n", __FUNCTION__);
	return 0;
}