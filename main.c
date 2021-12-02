#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "lcd_2004_i2c.h"

static char *message[] =
            {
                    "Cherie Hsieh",
                    "Software Engineer", "at PUFsecurity",
                    "Golang", "Community",
                    "GDG Group", "Thank You",
            };

int main() {
    struct lcd_device lcd = {.i2c = i2c_default, .addr = 0x3F};
    size_t message_len;

    i2c_init(lcd.i2c, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));

    if (!lcd_init(&lcd))
    {
        printf("failed to init LCD device\n");
        return 1;
    }

    message_len = sizeof(message) / sizeof(message[0]);

    while (true) {
        for (int m = 0; m < message_len; m += MAX_LINES) {
            for (int line = 0; line < MAX_LINES && (m + line) < message_len; line++) {
                lcd_set_cursor(&lcd, line, (MAX_CHARS / 2) - strlen(message[m + line]) / 2);
                lcd_string(&lcd, message[m + line]);
            }
            sleep_ms(5000);
            lcd_clear(&lcd);
        }
    }
    return 0;
}
