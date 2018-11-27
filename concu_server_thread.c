#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<pthread.h>

void str_echo(int s)
{
	char buf[20];
	
	while(1)
	{
		recv(s,buf,50,0);
		puts("\nMessage from Client...\n");

		puts(buf);
		send(s,buf,20,0);
	}
}

static void *doit(void *arg)
{
	//pthread_detach(pthread_self());
	str_echo((int)arg);
	close((int)arg);
	pthread_exit(0);
	return NULL;
}

int main()
{
	int ls,cs,len;
	struct sockaddr_in serv,cli;
	pid_t pid;
	pthread_t th;
	puts("I am Server...");

	//creating socket
	ls=socket(AF_INET,SOCK_STREAM,0);
	puts("Socket Created Successfully...");

	//socket address structure
	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=INADDR_ANY;
	serv.sin_port=htons(5000);

	bind(ls,(struct sockaddr*)&serv,sizeof(serv));
	puts("Binding Done...");
	listen(ls,3);
	puts("Listening for Client...");

	for(; ;)
	{

		len=sizeof(cli);
		cs=accept(ls,(struct sockaddr*)&cli,&len);
		puts("Connected to Client...");

		//creating thread          
		pthread_create(&th,NULL,&doit,(void *)cs);

	}

	return 0;
}




