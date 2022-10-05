#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main(void)
{
    HANDLE hComm;                     
    char ComPortName[] = "\\\\.\\COM3"; //Our port name
    BOOL Status;                       
    DWORD dwEventMask;                  
    char Reader;                 
    char Reader_Button;
    char Storage[256];           
    char Storage_Button[256];
    DWORD NoBytesRead;                
    char sender[10];
    char sender_square[10];
    char sender_button[10];
    int i=0;

    /*---------------------------------- Opening the Serial Port -------------------------------------------*/

    hComm = CreateFile(ComPortName,                  
                       GENERIC_READ | GENERIC_WRITE,
                       0,                            
                       NULL,                         
                       OPEN_EXISTING,               
                       0,                            
                       NULL);                        

    /*------------------------------- Setting the Parameters for the SerialPort ------------------------------*/

    DCB dcbSerialParams = {0}; 
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    Status = GetCommState(hComm, &dcbSerialParams); 

    dcbSerialParams.BaudRate = CBR_9600;   
    dcbSerialParams.ByteSize = 8;          
    dcbSerialParams.StopBits = ONESTOPBIT; 
    dcbSerialParams.Parity = NOPARITY;     

    Status = SetCommState(hComm, &dcbSerialParams);

    /*------------------------------------ Setting Timeouts --------------------------------------------------*/

    COMMTIMEOUTS timeouts = {0};
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    
    if (SetCommTimeouts(hComm, &timeouts) == FALSE)
        printf("\n\n    Error! in Setting Time Outs");

    /*------------------------------------ Setting Receive Mask ----------------------------------------------*/

    Status = SetCommMask(hComm, EV_RXCHAR); //Configure Windows for Character Reception

	/* ---------------------------- Creating a Menu and Variables-----------------------------------------------------------*/
	printf("## WELCOME TO GTU ARDUINO LAB ##\n");
	printf("## STUDENT NAME: ATACAN BASARAN ##\n");
	printf("## PLEASE SELECT FROM THE FOLLOWING ##\n");
	printf("## MENU : ##\n");
	printf("(1) TURN ON LED ON ARDUINO\n");
	printf("(2) TURN OFF LED ON ARDUINO\n");
	printf("(3) FLASH ARDUINO LED 3 TIMES\n");
	printf("(4) SEND A NUMBER TO ARDUINO TO COMPUTE SQUARE BY ARDUINO\n");
	printf("(5) Button press counter\n");
	printf("(0) EXIT\n");

    /*-------------------------- Our main code which communication with Port ------------------------*/
	do{
    	printf("PLEASE SELECT:");
    	scanf("%s",&sender[0]);
    	DWORD dNoOFBytestoWrite;    
    	DWORD dNoOfBytesWritten = 0; 
    	dNoOFBytestoWrite = sizeof(sender);

    	Status = WriteFile(hComm,          //We select our menu number and send arduino         
                       	sender,          
                       	dNoOFBytestoWrite,  
                       	&dNoOfBytesWritten, 
                       	NULL);
                       	
    	if(sender[0]=='4'){
    		printf("Please write a number to compute square:");
			scanf("%s",&sender_square[0]);
			
			Status = WriteFile(hComm,      //We select a number whose square is to be calculated     
                       	sender_square,         
                       	dNoOFBytestoWrite, 
                       	&dNoOfBytesWritten, 
                       	NULL);
	
        	do{
            	Status = ReadFile(hComm, &Reader, sizeof(Reader), &NoBytesRead, NULL);//We read square output on Port
            	Storage[i] = Reader;     
            	i++;
        	} while (NoBytesRead > 0);

        /*------------Printing Arduino square output to Console----------------------*/
        printf("The result is: ");
        int j = 0;
        for (j = 0; j < i - 1; j++) 
            printf("%c",Storage[j]);
        i=0;
    	}
    	/*---------------------------------------------------------------------------*/
    	if(sender[0]=='5'){
    		while(1){
    			printf("Write 9 to see button counter output(0 to back menu):");
            	scanf("%s",&sender_button[0]);
            
            	if(sender_button[0]=='0')
					break; 
					
         		Status = WriteFile(hComm,  //We send 9 or 0 to doing process       
                       	sender_button,          
                       	dNoOFBytestoWrite, 
                       	&dNoOfBytesWritten,
                       	NULL);
    			do{
            		Status = ReadFile(hComm, &Reader_Button, sizeof(Reader_Button), &NoBytesRead, NULL);//We read button count on Port
            		Storage_Button[i] = Reader_Button;
            		i++;
        		} while (NoBytesRead > 0);
        		int j = 0;
        		for (j = 0; j < i - 1; j++)
            		printf("%c",Storage_Button[j]);
         		i=0;
    
        /*------------Printing Arduino button output to Console----------------------*/
        		printf("\n\n    ");
        		for (j = 0; j < i - 1; j++) 
            		printf("%c",Storage_Button[j]); 
			} 
   		}
		/*---------------------------------------------------------------------------*/
        if(sender[0]=='0'){
 			printf("\n===================\n");
 			printf("PROGRAM IS CLOSING\n");
 			printf("===================");
			CloseHandle(hComm);  
			break;} //Closing the Serial Port             
    }while(sender[0]!='0');
    return 0;
} 
