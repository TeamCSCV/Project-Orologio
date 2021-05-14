#ifndef DS1307_H
#define DS1307_H

//definitions
#define DS1307_ADDR (0x68<<1) //device address

//path to i2c fleury lib
#define DS1307_I2CFLEURYPATH "i2cmaster.h" //define the path to i2c fleury lib
#define DS1307_I2CINIT 1 //init i2c

//functions
extern void ds1307_init();
extern uint8_t ds1307_setdate(uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);
extern void ds1307_getdate(uint8_t *year, uint8_t *month, uint8_t *day, uint8_t *hour, uint8_t *minute, uint8_t *second);

#endif

