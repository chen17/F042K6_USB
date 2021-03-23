#include "mbed.h" 
#include "USBMouseKeyboard.h"

DigitalOut built_in_led(LED1);  // for debug purpose
DigitalOut btn_led(PA_0);  // user-faced status
DigitalIn button(PA_2);  // pull-high. low-activated.
USBMouseKeyboard hid(REL_MOUSE);

void send_enter(int repeat) {
  int i = 0;
  while (i < repeat) {
    hid.keyCode(0x0a);
    wait(0.3);
    i++;
  }
  wait(2);
}

void init() {
    // init I/O
    // button.mode(PullUp);
    built_in_led = 0;
    btn_led = 0;

    // Wait power and USB host to emumerate / initialize this device.    
    built_in_led = 1;
    btn_led = 1;
    wait(3);

    // prompt booting
    built_in_led = 0;
    btn_led = 0;
    wait(0.25);
    built_in_led = 1;
    btn_led = 1;
    wait(0.25);
    built_in_led = 0;
    btn_led = 1;  // keep the button LED to indicate the system is ready to use.
}

int main() {
    init();

    // reset to the top-left corner
    hid.move(-5000, -5000);
    wait(3);
    send_enter(17);
    hid.move(17, 17);
}
