#include "customer.h"
#include <cstdlib>

void Customer::set(long when){
    arrive = when;
    processtime = rand() % 3 + 1;
}