#include <iostream>
#include <memory>
#include "test_case_interface.h"
#include "test_case_client.h"
#include "props.h"

using namespace std;

int main()
{
	std::cout << "main function -- start " << std::endl;

	//std::unique_ptr<TestCaseInterface> client = std::make_unique<TestClient::TestCaseClient>();
	auto client (std::make_unique<TestCaseClient>());
	client->PostTestCase(kCodeTest);
	client->PostTestCase(kDesignPattern);
	client->PostTestCase(kMultiThread);
	client->PostTestCase(kStl);

	std::cout << "main function -- end" << std::endl;
	return 0;
}