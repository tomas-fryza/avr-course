// https://github.com/Sylaina/oled-display

#include "lcd.h"

int main(void)
{
    lcd_init(LCD_DISP_ON);
    lcd_clrscr();

    lcd_charMode(DOUBLESIZE);
    lcd_puts("OLED display");
    lcd_gotoxy(0, 2);
    lcd_charMode(NORMALSIZE);
    lcd_puts("128x64, SHH1106");

    lcd_drawLine(0, 25, 120, 25, WHITE);

    lcd_drawRect(20, 35, 100, 40, WHITE);

    lcd_display();

    while (1) {
        ;
    }

    return 0;
}
