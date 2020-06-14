#pragma once
#include <array>
#include <memory>

#include "test_case_interface.h"
#include "manufacture_interface.h"

class TestCaseClient final : public TestCaseInterface
	{
	public:
		TestCaseClient();
		~TestCaseClient();
		int PostTestCase(TestCaseProps prop) override;

	private:
		int init();

		bool init_done_;
		std::array<std::unique_ptr<ManufactureInterface>, kTestCaseMax> call_obj_array_;

	};

