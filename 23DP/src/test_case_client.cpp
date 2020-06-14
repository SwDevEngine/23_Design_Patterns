#include <iostream>
#include <algorithm>
#include <memory>
#include <array>
#include "test_case_client.h"
#include "props.h"
#include "CodeTest.h"
#include "DesignPattern.h"
#include "MultiThread.h"
#include "StandardTemplateLib.h"

using namespace std;

TestCaseClient::TestCaseClient() : init_done_(false)
{
	printf("%s\n", __FUNCTION__);
	int ret = init();
	if (!ret)
		init_done_ = true;
	else
		printf("failed to init DesignPattrenClient ret %d\n", ret);
}

TestCaseClient::~TestCaseClient()
{
	printf("%s\n", __FUNCTION__);
}

int TestCaseClient::init()
{
	printf("%s\n", __FUNCTION__);
	call_obj_array_[kCodeTest] = std::move(std::make_unique<CodeTest>());
	call_obj_array_[kDesignPattern] = std::move(std::make_unique<DesignPattern>());
	call_obj_array_[kStl] = std::move(std::make_unique<StandardTemplateLib>());
	call_obj_array_[kMultiThread] = std::move(std::make_unique<MultiThread>());

	return 0;
}

int TestCaseClient::PostTestCase(TestCaseProps prop)
{
	printf("%s\n", __FUNCTION__);
	if (!init_done_ && prop >= kTestCaseMax) {
		printf("not init this obj %s\n", __FUNCTION__);
		return -EINVAL;
	}

	call_obj_array_[prop]->Process(ProcessProps::kCodeTest_1);

	return 0;
}