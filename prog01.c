#include <stdio.h>
#include <stdlib.h>
//Prints the deciphered array. Used instead of printf("%s",encryptedMessage) because # is used instead of ' '
void printCipher(char *array,int messageSize){
	for (int i = 0;i<messageSize;i++){
		if(array[i]==35)
			printf(" ");
		else
			printf("%c",array[i]);
	}
	printf("\n");
}
//Undoes the Caesar Cipher's dislocation. The Caesar Cipher
//The Caesar Cipher dislocates a letter three positions to the right, this switches it back
//Example : a -> d. This function does the reverse, so d -> a and a -> z
void deCaesar(char *array,int messageSize){
	for (int i = 0;i<messageSize;i++){
		if (array[i]==35){
			array[i]=35;
		}
		else if ((array[i]>=65)&&(array[i]<=90)){
			array[i] = array[i]-3;
			if (array[i]<65){
				switch(array[i]){
					case 64 : array[i] = 90;break;
					case 63 : array[i] = 89;break;
					case 62 : array[i] = 88;break;
				}
			}
		}else if ((array[i]>=97)&&(array[i]<=122)){
			array[i] = array[i]-3;
			if (array[i]<97){
				switch(array[i]){
					case 96 : array[i] = 122;break;
					case 95 : array[i] = 121;break;
					case 94 : array[i] = 120;break;
				}
			}
		}
	}
}
//Swaps the characters of a string in pairs
//Example : "AaBbCc" -> "aAbBcC"
void deSwap(char *array,int messageSize){
	int i = 0;
	while (i < messageSize){
		char aux = array[i+1];
		array[i+1]=array[i];
		array[i]=aux;
		i = i + 2;
	}
}
//Unshuffles every other pair of characters in the way characteristic to the Caesar cipher
//Example : "aAbBcCdDeE" -> "eEbBcCdDaA". With an odd number of pairs, the center one remains unchanged
void deShuffle(char *array,int messageSize){
	int i = 0,j = messageSize - 2;
	char aux[2];
	//Deshuffling works differently whether the number of pairs is even or odd
	if((messageSize/2)%2 == 0){
		while(i<(messageSize/2)){
			aux[0]=array[i];
			aux[1]=array[i+1];
			array[i]=array[j];
			array[i+1]=array[j+1];
			array[j]=aux[0];
			array[j+1]=aux[1];
			i=i+4;
			j=j-4;
		}
	}
	else{
		while(i<((messageSize/2)-1)){
			aux[0]=array[i];
			aux[1]=array[i+1];
			array[i]=array[j];
			array[i+1]=array[j+1];
			array[j]=aux[0];
			array[j+1]=aux[1];
			i=i+4;
			j=j-4;
		}
	}
}

int main (){
	//File opening and setting of variable messageSize
	char fileName[50],*encryptedMessage;
	int messageSize = 0;
	FILE *inputFile;
    printf("Digite o nome do arquivo: ");
	//scanf("%s",fileName);
	printf("\n");
    inputFile = fopen("test.txt","r");
    if (!inputFile){
        printf("Specified file does not exist\n.");
        exit(0);
    }
    encryptedMessage = (char *) malloc(1 * sizeof(char));
    //Reading the file and writing it inside a dynamically allocated array
    encryptedMessage[0] = fgetc(inputFile); /*Note for next session : the use of realloc is causing a "corrupted size vs prev size" type error, so this logic needs to be changed*/
    while (!feof(inputFile)){
    	messageSize++;
    	encryptedMessage = (char *) realloc(encryptedMessage,messageSize);
    	encryptedMessage[messageSize] = fgetc(inputFile);
    }
    fclose(inputFile);

	printf("%s\n",encryptedMessage );
	printf("%d\n",messageSize );

	deSwap(encryptedMessage,messageSize);
		printf("%s\n",encryptedMessage );	
	deShuffle(encryptedMessage,messageSize);		
		printf("%s\n",encryptedMessage );
	deCaesar(encryptedMessage,messageSize);
		printf("%s\n",encryptedMessage );
	printCipher(encryptedMessage,messageSize);
}