/*
    Packet sniffer using libpcap library
*/
#include<pcap.h>
#include<stdio.h>
#include<stdlib.h> // for exit()
#include<string.h> //for memset
 
#include<sys/socket.h>
#include<arpa/inet.h> // for inet_ntoa()
#include<net/ethernet.h>



#define LINE_LEN 16

void dispatcher_handler(u_char *, const struct pcap_pkthdr *, const u_char *);
 
int multiple_interface(char * interface);


struct sockaddr_in source,dest;

int j=0; 

int main()
{
    pthread_t tid;
  
    char *a[2]={"lo"};


    for(int i=0;i<2;i++)
    {
	printf("\n%s\n",a[i]);

	pthread_create(&tid, NULL, multiple_interface, (void*)a[i]);
	
    }

 	pthread_join(tid, NULL);

}

int multiple_interface(char *interface)
{

    pcap_if_t *alldevsp , *device;
    pcap_t *handle,*handle1; //Handle of the device that shall be sniffed


    char errbuf[100] , *devname , devs[100][100];
    int count = 1 , n;


  
    //First get the list of available devices
    printf("Finding available devices ... ");
    if( pcap_findalldevs( &alldevsp , errbuf) )
    {
        printf("Error finding devices : %s" , errbuf);
        exit(1);
    }
    printf("Done");
     

    //Print the available devices
    printf("\nAvailable Devices are :\n");
    for(device = alldevsp ; device != NULL ; device = device->next)
    {
        printf("%d. %s - %s\n" , count , device->name , device->description);
        if(device->name != NULL)
        {
            strcpy(devs[count] , device->name);
        }
        count++;
    }

     
    //Ask user which device to sniff
    printf("Enter the number of the device you want to sniff : ");
    scanf("%d" , &n);
    devname = devs[n];
  

    //Open the device for sniffing
    printf("Opening device %s for sniffing ... " , devname);

    handle = pcap_open_live("eth0" , 65536 , 1 , 0 , errbuf);

    //handle1 = pcap_open_live("enp4s0" , 65536 , 1 , 0 , errbuf);

   // handle = pfring_open("enp4s0" , 65536 , 1 , 0 , errbuf);  // pfring
 
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s : %s\n" , devname , errbuf);
        exit(1);
    }
    printf("Done\n");
 

    //Put the device in sniff loop
    pcap_loop(handle , -1 ,dispatcher_handler , NULL);

  //pcap_loop(handle1 , -1 ,dispatcher_handler , NULL);
    
 
    return 0;  


}


void dispatcher_handler(u_char *temp1,const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    u_int i=0;


    /* print pkt timestamp and pkt len */
    printf("%ld:%ld (%ld) (%d)\n", header->ts, header->ts.tv_usec, header->len,header->caplen);          


    // Print the packet 
    for (i=1; (i < header->caplen + 1 ) ; i++)
    {
        printf("%.2x ", pkt_data[i-1]);
        if ( (i % LINE_LEN) == 0) printf("\n");
    }

    j=j+1;
    printf("=====>>%d\n",j);
    printf("\n\n");
}


