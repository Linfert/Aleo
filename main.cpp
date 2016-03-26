#include <iostream>


int main(int argc, char** argv)
{
	
	/*public_key();
	prived_key();*/
	
	printf("linfert@Edwend:~$ ");
	fgets(message, 128, stdin);
	message[strlen(message)-1]='\0';
	cryptage();
	decryptage();
	
	printf("linfert@Edwend:~$ %s", message);
	printf("LOLILOL\n");
	
	return 0;
}