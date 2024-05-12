#include "Exceptions.h"

int_input_str::int_input_str() {
	message = "Xaish Olunur Herif Daxil Edin:";
}

char const* int_input_str::what() const {
	return message.c_str();
}

equal_name::equal_name() {
	message = "Eyni Adli Obyekt Var:";
}

char const* equal_name::what() const {
	return message.c_str();
}

Error::Error() {
	message = "";
}

Error::Error(string error) {
	message == error;
}

char const* Error::what() const {
	return message.c_str();
}
