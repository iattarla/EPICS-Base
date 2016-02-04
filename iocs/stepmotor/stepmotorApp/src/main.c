#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/sysinfo.h>

#include "alarm.h"
#include "cvtTable.h"
#include "dbDefs.h"
#include "dbAccess.h"
#include "recGbl.h"
#include "recSup.h"
#include "devSup.h"
#include "link.h"

#include "longinRecord.h"
#include "longoutRecord.h"
#include "aoRecord.h"
#include "aiRecord.h"
#include "calcoutRecord.h"

#include "epicsExport.h"
#include "epicsThread.h"
#include "epicsVersion.h"



void readCoordinate();
void int_to_hex();

int motorcor[20]; // 3 coordinate for each motor 

double old_coordinate = 0;
double  coordinate = 1;

struct { 
	double		number;
	DEVSUPFUN	report;
	DEVSUPFUN	init;
	DEVSUPFUN	init_record; 
	DEVSUPFUN	get_ioint_info;
	DEVSUPFUN	write_ao;
} integer_converter={
        5,
        NULL,
        NULL,
        NULL,
        NULL,
        int_to_hex
};
epicsExportAddress(dset,integer_converter);

struct { 
	double	    number;
	DEVSUPFUN	report;
	DEVSUPFUN	init;
	DEVSUPFUN	init_record; 
	DEVSUPFUN	get_ioint_info;
	DEVSUPFUN	write_ao;
} saveCoordinate={
        5,
        NULL,
        NULL,
        NULL,
        NULL,
        readCoordinate
};
epicsExportAddress(dset,saveCoordinate);



void int_to_hex(calcoutRecord *calcout){

	int  int_value = calcout->a;

	int_value = int_value*35; // tam tur 12600/ 360 = 35
	short hex1,hex2;
 	
	// integer değişkeni 2 byte olarak ikiye ayırıyoruz.
	hex1 =  (int_value >> 8) & 0xFF;
	hex2 =  int_value & 0xFF;

	calcout->b = hex1;
	calcout->c = hex2;

	printf("integer = %d hex1 = %X hex2 = %X \n",int_value,hex1,hex2);


}

void readCoordinate(calcoutRecord *calcout){
	
	//coordinate = calcout->a;
	 
	printf("reading coordinates from file...\n");
	
	FILE *file = fopen("coordinate.dat", "r");
    	//int integers[20];

    	int i=0;
    	int num;
    	
	while(fscanf(file, "%d", &num) > 0) {
		printf("-%d\n",num);
	        motorcor[i] = num;
	        i++;
	    }
    	
	fclose(file);

	calcout->a = motorcor[0];
	calcout->b = motorcor[1];
	calcout->c = motorcor[2];

	calcout->d = motorcor[3];	
	calcout->e = motorcor[4];
	calcout->f = motorcor[5];
	
	calcout->g = motorcor[6];
	calcout->h = motorcor[7];	
	calcout->i = motorcor[8];


//	printf("old:%f new:%f \n",old_coordinate,coordinate); 
		



/*
			FILE *fp; 
			fp = fopen("coordinate.dat","r+"); 
			//fseek(fp,0, SEEK_END);  

		   
			if(fp == NULL){ 
				puts("dosya acilmiyor"); 
	    			exit(1); 
	  		}else { 
	  			fprintf(fp,"%f\n",coordinate);	 
				printf("printer:%f\n",coordinate); 
  				fclose(fp); 
    			} 
				 
	old_coordinate = coordinate; 
*/

}
