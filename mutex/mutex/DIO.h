

#ifndef DIO_H_
#define DIO_H_
#define F_CPU 8000000ul 
#include <util/delay.h>
void DIO_vsetPINDir(char portname,char pinnumber,char direction);
void DIO_write(char portname,char pinnumber,char outputvalue);
char DIO_u8read(char portname,char pinnumber);
void DIO_toggle(char portname,char pinnumber);
void DIO_write_port(char portname,char portvalue);
void clear_high_nibble(char portname) ;
void dio_write_highnibble(char portname,char value);




#endif /* DIO_H_ */