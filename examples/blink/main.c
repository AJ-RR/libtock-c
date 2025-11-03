#include <libtock-sync/services/alarm.h>
#include <libtock/interface/led.h>

int main(void) {
  
  // Original binary pattern LED code
  // Ask the kernel how many LEDs are on this board.
  // int num_leds;
  // int err = libtock_led_count(&num_leds);
  // if (err < 0) return err;

  // // Blink the LEDs in a binary count pattern and scale
  // // to the number of LEDs on the board.
  // for (int count = 0; ; count++) {
  //   for (int i = 0; i < num_leds; i++) {
  //     if (count & (1 << i)) {
  //       libtock_led_on(i);
  //     } else {
  //       libtock_led_off(i);
  //     }
  //   }

  //   // This delay uses an underlying alarm in the kernel.
  //   libtocksync_alarm_delay_ms(250);
  // }
  

  // New RGB LED blinking code
  // Cycle through colors using the count variable like the original
  for (int count = 0; ; count++) {
    // Use count to determine the color pattern
    switch(count % 4) {
      case 0:
        libtock_rgb_led_set(255, 255, 255);  // Red
        printf("Red\n");
        break;
      case 1:
        libtock_rgb_led_set(125, 125, 125);  // Green
        printf("Green\n"); 
        break;
      case 2:
        libtock_rgb_led_set(50, 50, 50);  // Blue
        printf("Blue\n");
        break;
      case 3:
        libtock_rgb_led_set(0, 0, 0);    // Off
        break;
    }
    
    // Use same delay timing as original code
    libtocksync_alarm_delay_ms(250);
  }
}
