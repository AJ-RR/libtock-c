#include "led_syscalls.h"

bool libtock_led_driver_exists(void) {
  int count;
  int ret;

  ret = libtock_led_command_count(&count);
  if (ret != RETURNCODE_SUCCESS) return false;

  return count > 0;
}

returncode_t libtock_led_command_count(int* count) {
  syscall_return_t rval = command(DRIVER_NUM_LED, 0, 0, 0);
  return tock_command_return_u32_to_returncode(rval, (uint32_t*) count);
}

returncode_t libtock_led_command_on(int led_num) {
  syscall_return_t rval = command(DRIVER_NUM_LED, 1, led_num, 0);
  return tock_command_return_novalue_to_returncode(rval);
}

returncode_t libtock_led_command_off(int led_num) {
  syscall_return_t rval = command(DRIVER_NUM_LED, 2, led_num, 0);
  return tock_command_return_novalue_to_returncode(rval);
}

returncode_t libtock_led_command_toggle(int led_num) {
  syscall_return_t rval = command(DRIVER_NUM_LED, 3, led_num, 0);
  return tock_command_return_novalue_to_returncode(rval);
}

returncode_t libtock_rgb_led_command_set(uint8_t red, uint8_t green, uint8_t blue) {
  syscall_return_t rval = command(DRIVER_NUM_LED, 5, 0, red);
  command(DRIVER_NUM_LED, 5, 1, green);
  command(DRIVER_NUM_LED, 5, 2, blue);
  return tock_command_return_novalue_to_returncode(rval);
}
