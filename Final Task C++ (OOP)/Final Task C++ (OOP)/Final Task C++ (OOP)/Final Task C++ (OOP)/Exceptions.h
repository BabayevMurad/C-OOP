#pragma once

#include <iostream>
using namespace std;

class int_input_str : public exception {
	string message;

public:

	int_input_str();

	char const* what() const override;

};

class equal_name : public exception {
	string message;

public:

	equal_name();

	char const* what() const override;

};

class Error: public exception {
	string message;

public:

	Error();

	Error(string error);

	char const* what() const override;

};