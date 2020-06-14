#include <iostream>
#include "MultiThread.h"

MultiThread::MultiThread() : init_done_(false)
{
	printf("%s\n", __FUNCTION__);
	if (init())
		printf("%s: failed to init", __FUNCTION__);
	else
		init_done_ = true;
}

MultiThread::~MultiThread()
{
	printf("%s\n", __FUNCTION__);
}

int MultiThread::init() {
	process_func_[kCodeTest_1] = &MultiThread::test_case_1;
	return 0;
}

int MultiThread::SetFunc(ProcessProps)
{
	printf("%s\n", __FUNCTION__);
	return 0;
}

int MultiThread::GetFunc(ProcessProps)
{
	printf("%s\n", __FUNCTION__);
	return 0;
}

int MultiThread::Process(ProcessProps prop)
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

int MultiThread::test_case_1()
{
	printf("%s\n", __FUNCTION__);
	return 0;
}