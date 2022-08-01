#include "hw.h"
#include "ms2_control.h"

int main() {
  hw_setup();
  run_app();

  return 1; // normally never reached...
}
