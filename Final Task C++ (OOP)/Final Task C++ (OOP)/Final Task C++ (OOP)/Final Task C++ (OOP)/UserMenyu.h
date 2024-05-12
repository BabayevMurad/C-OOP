#pragma once

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "color.h"
#include "enum.h"
#include "UserLoginMenyu.h"



using namespace std;

namespace UserMenyu {
	void menyu(short index);
	void control(short choice, short index_menyu);
}