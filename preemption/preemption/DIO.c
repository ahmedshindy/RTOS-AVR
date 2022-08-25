#include <avr/io.h>

void DIO_vsetPINDir(char portname,char pinnumber,char direction)
{
	switch(portname)
	{
		
	
	case 'A':
	if(direction==1)
	{
		DDRA|=(1<<pinnumber);
	}
	else
	{
		DDRA&=(~(1<<pinnumber));
	}
	break;
	case 'B':
	if(direction==1)
	{
		DDRB|=(1<<pinnumber);
	}
	else
	{
		DDRB&=(~(1<<pinnumber));
	}
	break;
	case 'C':
	if(direction==1)
	{
		DDRC|=(1<<pinnumber);
	}
	else
	{
		DDRC&=(~(1<<pinnumber));
	}
	break;
	case 'D':
	if(direction==1)
	{
		DDRD|=(1<<pinnumber);
	}
	else
	{
		DDRD&=(~(1<<pinnumber));
	}
	break;
	default: break;
	}	
}


void DIO_write(char portname,char pinnumber,char outputvalue)
{
	switch(portname)
	{
		case 'A' :
		
			if(outputvalue==1)
			{
				PORTA|=(1<<pinnumber);
			}
			else
			{
				PORTA&=(~(1<<pinnumber));
			}
			break ;
			case 'B':
			
			if(outputvalue==1)
			{
				PORTB|=(1<<pinnumber);
			}
			else
			{
				PORTB&=(~(1<<pinnumber));
			}
			break ;
			case 'C' :
			
			if(outputvalue==1)
			{
				PORTC|=(1<<pinnumber);
			}
			else
			{
				PORTC&=(~(1<<pinnumber));
			}
			break ;
		case 'D':
		
		if(outputvalue==1)
		{
			PORTD|=(1<<pinnumber);
		}
		else
	{
			PORTD&=(~(1<<pinnumber));
		}
		break ;
		default: break ;
	}
}


char DIO_u8read(char portname,char pinnumber)
{
	char x ;
	switch(portname)
	{
		case 'A' :
		x=((PINA&(1<<pinnumber))>>pinnumber);
		break;
		
	case 'B' :
	x=((PINB&(1<<pinnumber))>>pinnumber) ;
	break;
	
	case 'C' :
	x=((PINC&(1<<pinnumber))>>pinnumber) ;
	break;
	
	case 'D' :
	x=((PIND&(1<<pinnumber))>>pinnumber) ;
	break;
	default: break;
}
return x ;
}
void DIO_toggle(char portname,char pinnumber)
{
	switch(portname)
	{
		case 'A':
		PORTA^=(1<<pinnumber);
		break;
		case 'B':
		PORTB^=(1<<pinnumber);
		break;
		case 'C':
		PORTC^=(1<<pinnumber);
		break;
		case 'D':
		PORTD^=(1<<pinnumber);
		break;
		default: break;
	}
}
void DIO_write_port(char portname,char portvalue)
{
	switch(portname)
	{
		case 'A' :
		PORTA=portvalue;
		break ;
		case 'B':
		PORTB=portvalue;
		break ;
		case 'C' :
		PORTC=portvalue;
		break ;
		case 'D':
		PORTD=portvalue;
		break ;
		default: break ;
	}
}
void dio_write_highnibble(char portname,char value)
{
		switch(portname)
		{
			case 'A' :
			PORTA|=(value&0xf0);
			break ;
			case 'B':
			PORTB|=(value&0xf0);
			break ;
			case 'C' :
			PORTC|=(value&0xf0);
			break ;
			case 'D':
			PORTD|=(value&0xf0);
			break ;
			default: break ;
	
}
}
void clear_high_nibble(char portname)
{
	switch(portname)
	{
		case 'A' :
		PORTA&=0x0f;
		break ;
		case 'B':
		PORTB&=0x0f;
		break ;
		case 'C' :
		PORTC&=0x0f;
		break ;
		case 'D':
		PORTD&=0x0f;
		break ;
		default: break ;
		
	}
}