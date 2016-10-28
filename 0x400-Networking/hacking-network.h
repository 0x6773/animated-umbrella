#ifndef __HACKING_NETWORK_H__
#define __HACKING_NETWORK_H__ 1

/* This function accepts a socket FD and a ptr to the null terminated
 * string to send. The function will make sure all the bytes of the
 * string are sent. Returns 1 on success and 0 a failure.
 */
#include <string.h>
#include <sys/socket.h>
int send_string(int sockfd, char* buffer)
{
	int sent_bytes, bytes_to_send;
	bytes_to_send = strlen(buffer);

	while(bytes_to_send > 0)
	{
		sent_bytes = send(sockfd, buffer, bytes_to_send, 0);
		if(sent_bytes == -1)
			return 0;
		bytes_to_send -= sent_bytes;
		buffer += sent_bytes;
	}
	return 1;
}

/* This function accepts a socket FD and a ptr to a destination
 * buffer. It will receive from the socket until the EOL byte
 * sequence is seen. The EOL bytes are read from the socket, but
 * the destination buffer is terminated before these bytes.
 * Returns the size of the read line(without EOL bytes).
 */
int recv_line(int sockfd, char* dest_buffer)
{
#define EOL "\r\n"
#define EOL_SIZE 2
	char *ptr;
	int eol_matched = 0;

	ptr = dest_buffer;
	while(recv(sockfd, ptr, 1, 0) == 1)
	{
		if(*ptr == EOL[eol_matched])
		{
			eol_matched++;
			if(eol_matched == EOL_SIZE)
			{
				*(ptr + 1 - EOL_SIZE) = '\0';
				return strlen(dest_buffer);
			}
		}
		else
			eol_matched = 0;
		ptr++;
	}
	return 0;
}

#define ETHER_ADDR_LEN 6
#define ETHER_HDR_LEN 14

struct ether_hdr
{
	unsigned char ether_dest_addr[ETHER_ADDR_LEN]; // Destination MAC Address
	unsigned char ether_src_addr[ETHER_ADDR_LEN];  // Source MAC Address
	unsigned short ether_type; // Type of Ethernet packet
};

struct ip_hdr
{
	unsigned char ip_version_and_header_length; // Version and header length
	unsigned char ip_tos;			// Type of Service
	unsigned short ip_len;		// Total Length
	unsigned short ip_id;			// Identification number
	unsigned short ip_frag_offset; // Fragment offset and flags
	unsigned char ip_ttl;			// Time to live
	unsigned char ip_type;		// Protocol type
	unsigned short ip_checksum;	// Checksum
	unsigned int ip_src_addr;	// Source IP Address
	unsigned int ip_dest_addr;	// Destination IP Address
};

struct tcp_hdr
{
	unsigned short tcp_src_port;	// Source TCP Port
	unsigned short tcp_dst_port;	// Destination TCP Port
	unsigned int tcp_seq;					// TCP sequence number
	unsigned int tcp_ack;					// TCP acknowledgment number
	unsigned char reserved:4;			// 4 bits from the 6 bits of reserved space
	unsigned char tcp_offset:4;		// TCP data offset for little-endian host
	unsigned char tcp_flags;			// TCP flags(and 2 bits from reserted space)
#define TCP_FIN 0x01
#define TCP_SYN 0x02
#define TCP_RST 0x04
#define TCP_PUSH 0x08
#define TCP_ACK 0x10
#define TCP_URG 0x20
	unsigned short tcp_window;		// TCP window size
	unsigned short tcp_checksum;	// TCP checksum
	unsigned short tcp_urgent;		// TCP urgent pointer
};

#endif
