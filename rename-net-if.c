// Rename network interface.
// Run: ./rename-net-if ORIGINAL_IF_NAME NEW_IF_NAME
//
// NOTE: interface should be in DOWN state
// NOTE: requires root permissions
//
// LICENSE: MIT

#include <stdio.h>
#include <string.h>

#include <net/if.h>
#include <sys/ioctl.h>

int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("Please specify original and new interface names\n");
		return 1;
	}

	int fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (fd == -1) {
		perror("Failed to open network socket");
		return 1;
	}

	char const * original_name = argv[1];
	char const * new_name = argv[2];

	struct ifreq ifr;
	memset(&ifr, 0, sizeof(struct ifreq));
	strncpy(ifr.ifr_name, original_name, IFNAMSIZ);
	strncpy(ifr.ifr_newname, new_name, IFNAMSIZ);

	int ret = ioctl(fd, SIOCSIFNAME, &ifr);
	if (ret == 0) {
		printf("Network interface %s renamed to %s\n", original_name, new_name);
		return 0;
	}
	else {
		perror("Failed to rename network interface");
		return 1;
	}
}
