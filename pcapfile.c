#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>

#define LINE_LEN 16



#define IP_VERSION_START 12
#define IP_VERSION_END 13


//ipv4

#define IPV4_SRC_IP_START 26
#define IPV4_SRC_IP_END 29
#define IPV4_DST_IP_START 30
#define IPV4_DST_IP_END 33

#define IPV4_SRC_PORT_START 34
#define IPV4_SRC_PORT_END 35
#define IPV4_DST_PORT_START 36
#define IPV4_DST_PORT_END 37

#define IPV4_SRC_MAC_START 0
#define IPV4_SRC_MAC_END 5
#define IPV4_DST_MAC_START 6
#define IPV4_DST_MAC_END 11

#define IPV4_PROTOCOL_TYPE 23

//ipv6

#define IPV6_SRC_IP_START 22
#define IPV6_SRC_IP_END 37
#define IPV6_DST_IP_START 38
#define IPV6_DST_IP_END 53

#define IPV6_SRC_PORT_START 54
#define IPV6_SRC_PORT_END 55
#define IPV6_DST_PORT_START 56
#define IPV6_DST_PORT_END 57

#define IPV6_SRC_MAC_START 0
#define IPV6_SRC_MAC_END 5
#define IPV6_DST_MAC_START 6
#define IPV6_DST_MAC_END 11

#define IPV6_PROTOCOL_TYPE 21

int j=0;



struct ipfields
{



};	 


// substring of packet

void substring(int start_index ,int end_index,const u_char *pkt_data,int result[])
{

	u_int i;
     
	int index;

	if(start_index <= end_index)
	{
		for (i=start_index ,index=0; i <= end_index  ; i++,index++)
	    	{
		
			result[index]=pkt_data[i];

		}

		printf("   ");	

	}
	else
	{
		printf("Err in index value");
		exit;		
	}

}


//ip version

int ip_version(const u_char *pkt_data)
{
	   
	j=j+1;
	printf("%d\n",j);

    	printf("\n ip version --->    ");	

        int ip_version[2]={0};
    
        substring(IP_VERSION_START,IP_VERSION_END,pkt_data ,ip_version);

        for(int i=0;i<2;i++)
        {
    		printf("%.2x ",ip_version[i]);
        }
	
}


//ipv4 source ip address

int ipv4_src_ipaddress(const u_char *pkt_data)
{
	   

    	printf("\n src ipaddress --->    ");  

        int src_ipaddress[4]={0};
    
        substring(IPV4_SRC_IP_START,IPV4_SRC_IP_END,pkt_data ,src_ipaddress);

        for(int i=0;i<4;i++)
        {

		printf("%d ",src_ipaddress[i]);
    		
        }
	
}


//ipv4 destination ip address

int ipv4_dst_ipaddress(const u_char *pkt_data)
{

    	printf("\n dst ipaddress --->    ");	

	int dst_ipaddress[4]={0};
    
        substring(IPV4_DST_IP_START,IPV4_DST_IP_END,pkt_data,dst_ipaddress);

        for(int i=0;i<4;i++)
        {
    		printf("%d ",dst_ipaddress[i]);
		
        }

}

//ipv4 source port number

int ipv4_src_port(const u_char *pkt_data)
{

    	printf("\n src port --->    ");	
	
	int k=0;

	int src_port[2]={0};
    
        substring(IPV4_SRC_PORT_START,IPV4_SRC_PORT_END,pkt_data,src_port);

        for(int i=0;i<2;i++)
        {

		//k = 10 * k + src_port[i];
		
		//printf("-->>%d",k);

    		printf("%.2x ",src_port[i]);
		
        }

}

//ipv4 destination port number

int ipv4_dst_port(const u_char *pkt_data)
{
	
    	printf("\n dst port --->    ");	

	int dst_port[2]={0};
    
        substring(IPV4_DST_PORT_START,IPV4_DST_PORT_END,pkt_data,dst_port);

        for(int i=0;i<2;i++)
        {
    		printf("%.2x ",dst_port[i]);
		
        }

}


//ipv4 source mac address

int ipv4_src_mac(const u_char *pkt_data)
{
	
    	printf("\n src mac --->    ");	

	int src_mac[6]={0};
    
        substring(IPV4_SRC_MAC_START,IPV4_SRC_MAC_END,pkt_data,src_mac);

        for(int i=0;i<6;i++)
        {
    		printf("%.2x ",src_mac[i]);
		
        }

}

//ipv4 destination mac address

int ipv4_dst_mac(const u_char *pkt_data)
{


    	printf("\n dst mac --->    ");	

	int dst_mac[6]={0};
    
        substring(IPV4_DST_MAC_START,IPV4_DST_MAC_END,pkt_data,dst_mac);

        for(int i=0;i<6;i++)
        {
    		printf("%.2x ",dst_mac[i]);		
	}

}


//ipv4 protocols types  ex: tcp,udp,arp etc..,

int ipv4_protocol_types(const u_char *pkt_data)
{

    	printf("\n protocol --->    ");	

	int protocol[1]={0};
    
        substring(IPV4_PROTOCOL_TYPE,IPV4_PROTOCOL_TYPE,pkt_data,protocol);

        for(int i=0;i<1;i++)
        {
    		printf("%.2x ",protocol[i]);		
	}

	printf("\n\n");

}


//ipv6 source ip address

int ipv6_src_ipaddress(const u_char *pkt_data)
{
	   

    	printf("\n src ipaddress --->    ");  

        int src_ipaddress[16]={0};
    
        substring(IPV6_SRC_IP_START,IPV6_SRC_IP_END,pkt_data ,src_ipaddress);

        for(int i=0;i<16;i++)
        {

		printf("%.2x ",src_ipaddress[i]);
    		
        }
	
}


//ipv6 destination ip address

int ipv6_dst_ipaddress(const u_char *pkt_data)
{

    	printf("\n dst ipaddress --->    ");	

	int dst_ipaddress[16]={0};
    
        substring(IPV6_DST_IP_START,IPV6_DST_IP_END,pkt_data,dst_ipaddress);

        for(int i=0;i<16;i++)
        {
    		printf("%.2x ",dst_ipaddress[i]);
		
        }

}

//ipv6 source port number

int ipv6_src_port(const u_char *pkt_data)
{

    	printf("\n src port --->    ");	
	
	int k=0;

	int src_port[2]={0};
    
        substring(IPV6_SRC_PORT_START,IPV6_SRC_PORT_END,pkt_data,src_port);

        for(int i=0;i<2;i++)
        {

		//k = 10 * k + src_port[i];
		
		//printf("-->>%d",k);

    		printf("%.2x ",src_port[i]);
		
        }

}

//ipv6 destination port number

int ipv6_dst_port(const u_char *pkt_data)
{
	
    	printf("\n dst port --->    ");	

	int dst_port[2]={0};
    
        substring(IPV6_DST_PORT_START,IPV6_DST_PORT_END,pkt_data,dst_port);

        for(int i=0;i<2;i++)
        {
    		printf("%.2x ",dst_port[i]);
		
        }

}


//ipv6 source mac address

int ipv6_src_mac(const u_char *pkt_data)
{
	
    	printf("\n src mac --->    ");	

	int src_mac[6]={0};
    
        substring(IPV6_SRC_MAC_START,IPV6_SRC_MAC_END,pkt_data,src_mac);

        for(int i=0;i<6;i++)
        {
    		printf("%.2x ",src_mac[i]);
		
        }

}

//ipv6 destination mac address

int ipv6_dst_mac(const u_char *pkt_data)
{


    	printf("\n dst mac --->    ");	

	int dst_mac[6]={0};
    
        substring(IPV6_DST_MAC_START,IPV6_DST_MAC_END,pkt_data,dst_mac);

        for(int i=0;i<6;i++)
        {
    		printf("%.2x ",dst_mac[i]);		
	}

}

//void dispatcher_handler(u_char *, const struct pcap_pkthdr *, const u_char *);

void dispatcher_handler(u_char *temp1,const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    
   // ip_version(pkt_data);


	j=j+1;
	printf("\n%d\n",j);

    	printf("\n ip version --->    ");	


	
        int ip_version[2]={0} ,k=0;
    
        substring(IP_VERSION_START,IP_VERSION_END,pkt_data ,ip_version);

        for(int i=0;i<2;i++)
        {

  		printf("%.2x ",ip_version[i]);
		
        }
	
	

	if(ip_version[0] == 8 && ip_version[1] == 00)  //ipv4
	{
	  
   	    int protocol[1]={0};
    
	    substring(IPV4_PROTOCOL_TYPE,IPV4_PROTOCOL_TYPE,pkt_data,protocol);

            for(int i=0;i<1;i++)
            {
    		printf("%.2x ",protocol[i]);		
	    }

	    //ipv4_protocol_types(pkt_data);
	    
	    if(protocol[0]==6)  //tcp
	    {
	
		    ipv4_src_ipaddress(pkt_data);

		    ipv4_dst_ipaddress(pkt_data);

		    ipv4_src_port(pkt_data);

		    ipv4_dst_port(pkt_data);

		    ipv4_src_mac(pkt_data);
		    
		    ipv4_dst_mac(pkt_data);
	    
	    }
	    else if(protocol[0]==11) //udp
	    {


	    }	  	    

	}

	else if(ip_version[0] == 8 && ip_version[1] == 06) //arp
	{

		printf("arp");

	}

	else if(ip_version[0] == 86 ) // && ip_version[0] == "dd" ) //ipv6
	{

		    ipv6_src_ipaddress(pkt_data);

		    ipv6_dst_ipaddress(pkt_data);

		    ipv6_src_port(pkt_data);

		    ipv6_dst_port(pkt_data);

		    ipv6_src_mac(pkt_data);
		    
		    ipv6_dst_mac(pkt_data);	

	}

}

int main(int argc, char **argv) 
{
    
    pcap_t *fp;
    char errbuf[PCAP_ERRBUF_SIZE];


    if(argc != 2){

        printf("usage: %s filename", argv[0]);
        return -1;

    }
    
    /* Open a capture file */
    if ( (fp = pcap_open_offline(argv[1], errbuf) ) == NULL)
    {
        fprintf(stderr,"\nError opening dump file\n");
        return -1;
    }
    
    // read and dispatch packets until EOF is reached
    pcap_loop(fp, 0, dispatcher_handler, NULL);

    return 0;
}
