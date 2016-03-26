	while(strcmp(commande, "leave")!=0)
	{
		printf("%s@%s:~$ ", user, localhost);
		fgets(commande, 50, stdin);
		commande[strlen(commande)-1] = '\0';
		if(strcmp(commande, "leave")!=0)
		{
			order(analyse());
		}
	}


	int maths::power(long a, long long b)
{
	int i=0;
	unsigned long long tampon=1;
	
	for(i=0; i<b; i++)
	{
		tampon=(tampon*a)%n;
		//if(lama==1) { printf("Test 1 (%d) : %lld\n", i, tampon); }
	}
	return tampon;
}

int maths::pgcd(int a, int b)
{
	while(a!=b)
	{
		if(a>b)
		{
			a=a-b;
		}
		else
		{
			b=b-a;
		}
	}
	
	//printf("Pgcd : %d\n", a);
	return a;
}

/*int maths::factoriser(int n)
{
	int b=2;
	while(n%b!=0)
	{
		b++;
	}
	if(n/b==1)
	{
		p=b;
	}
	p=b;
	q=n/b;
	//printf("Test { n : %d, p : %d, q : %d }\n", n, p, q);
}*/

//int fonctions::~reception();

void fonctions::public_key()
{
	int PGCD=0;
	
	/*printf("Entrez un nombre premier p : ");
	scanf("%i", &p);
	printf("Entrez un nombre premier q : ");
	scanf("%i", &q);*/
	
	n=p*q;
	phin=(p-1)*(q-1);
	//printf("Phin : %d\n", phin);
	
	
	while(PGCD!=1)
	{
		while(e<p)
		{
			e++;
		}
		e++;
		//printf("p : %d | e : %d\n", p, e);
		PGCD=maths::pgcd(e, phin);
	}
	
	//printf("Clef publique : %d , %d\n", e, n);
	
}

void fonctions::prived_key()
{
	int i=0;
	
	//factoriser(n);
	//phin=(p-1)*(q-1);
	
	while(i==0)
	{
		d++;
		if((e*d)%phin==1 && ((e*d)-1)%phin==0)
		{
			i=1;
		}
	}
	
	printf("Clef privée : %d, %d\n", d, n);
}

void fonctions::cryptage(unsigned char message)
{
	int i=0, ascii=0, n_carac=0;
	n_carac=strlen(message);
	printf("Il y a %d caractres.\n", n_carac);
	
	for(i=0; i<n_carac; i++)
	{
		ascii=(int) message[i];
		crypted_message[i]=power(ascii, e);
		//printf("%c : %d : %lld\n", message[i], ascii, crypted_message[i]);
	}
	strcpy(message,document);
}

void fonctions::decryptage()
{
	int i=0, ascii=0, tampon=0;
	
	for(i=0; i<256; i++)
	{
		if(crypted_message[i]!=0)
		{
			tampon++;
		}
	}
	for(i=0; i<tampon; i++)
	{
		ascii=power(crypted_message[i], d);
		message[i]=(char) (ascii);
		//printf("%c : %d : %lld\n", message[i], ascii, crypted_message[i]);
	}
	
}

void cryptage()
{

	p=malloc(sizeof(int));
	q=malloc(sizeof(int));
	if(p==NULL && q==NULL) // On vérifie si la mémoire a été allouée
	{
		exit(0); // Erreur : arrêt du programme.
	}
	free(p); // On n'a plus besoin de la mémoire, on la libère
	free(q);

    return 0;
}