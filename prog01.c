#include <stdio.h>
#include <stdlib.h>
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
	int i = 0;j = messageSize - 2;
	char aux[2];
	//Deshuffling works differently whether the number of pairs is even or odd
	if((messageSize/2)%2 == 0){
		while(i<())
	}
	else{

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
    encryptedMessage = (char *) malloc(messageSize * sizeof(char));
    //Reading the file and writing it inside a dynamically allocated array
    encryptedMessage[0] = fgetc(inputFile);
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
}