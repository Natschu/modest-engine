//NullPrinter.cpp
#include "common/console/NullPrinter.h"

NullPrinter::NullPrinter() {}
NullPrinter::~NullPrinter() {}

void NullPrinter::print(const C8* message){}
void NullPrinter::print(const std::string message){}

