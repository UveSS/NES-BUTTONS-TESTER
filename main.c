#include <string.h>
#include <conio.h>

typedef unsigned char u8;
#define address(add) (*(u8 *)(add))

#define button_A    0x80
#define button_B    0x40
#define button_SELECT   0x20
#define button_START    0x10
#define button_UP   0x08
#define button_DOWN 0x04
#define button_LEFT 0x02
#define button_RIGHT    0x01

int read_input1(){
 u8 n=8, joy_state=0;
 address(0x4016)=01;
 address(0x4016)=00;
 while(n){
 	joy_state = (joy_state <<1)|address(0x4016) &1;
 	--n;
 }
 return joy_state;
}

void main(){
	unsigned char key;
	int d;
	unsigned char i=0;

	int state_A=0;
	int state_B=0;
	int state_SELECT=0;
	int state_START=0;
	int state_UP=0;
	int state_DOWN=0;
	int state_LEFT=0;
	int state_RIGHT=0;


	int mustQuit=0;
	while(mustQuit!=1){
		gotoxy(1,1);
		clrscr();
		key = read_input1();

		if(key & (button_A)){
			state_A=1;
		}
		else if(key & (button_B)){
			state_B=1;
		}
		else if(key & (button_SELECT)){
			state_SELECT=1;
		}
		else if(key & (button_START)){
			state_START=1;
		}
		else if(key & (button_UP)){
			state_UP=1;
		}
		else if(key & (button_DOWN)){
			state_DOWN=1;
		}
		else if(key & (button_LEFT)){
			state_LEFT=1;
		}
		else if(key & (button_RIGHT)){
			state_RIGHT=1;
		}
		cprintf("\r\nNES Button Test\r\n");
		cprintf("Coded by UveSS\r\n\r\n");
		cprintf("\r\nPRESS THE KEYS\r\n1:The key has been pressed\r\n2:The key hasn't be pressed\r\n");
		cprintf("\r\nPress UP %i \r\n",state_UP);
		cprintf("Press DOWN %i\r\n",state_DOWN);
		cprintf("Press RIGHT %i \r\n",state_RIGHT);
		cprintf("Press LEFT %i \r\n",state_LEFT);
		cprintf("\r\nPress START %i \r\n",state_START);
		cprintf("Press SELECT %i \r\n",state_SELECT);
		cprintf("\r\nPress A %i \r\n",state_A);
		cprintf("Press B %i \r\n",state_B);

		if(state_A==1 && state_B==1 && state_SELECT==1 && state_START==1 && state_UP==1 && state_DOWN==1 && state_LEFT==1 && state_RIGHT==1){
			for(d=0;d<=500;d++){
				clrscr();
				gotoxy(1,1);
				cprintf("Your controller works well! \r\n Reset or repeat");
			}
			break;
		}else{

	bgcolor(COLOR_BLUE);
	for(d=0;d<=10;d++)
	waitvblank();
}
	}
	

}