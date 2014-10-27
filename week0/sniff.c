#include <pcap/pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

static char errbuf[PCAP_ERRBUF_SIZE];

void print_all_devs() 
{
	pcap_if_t *devs, *ff;
	if (pcap_findalldevs(&devs, errbuf) == -1) {
		fprintf(stderr, "Well, fuck.\n");
		exit(EXIT_FAILURE);
	}
	ff = devs;
	while (1) {
		if (devs == NULL) 
			break;
		printf("Dev: %s; %s\n", devs->name, devs->description);
		devs = devs->next;
	}
	pcap_freealldevs(ff);
}

pcap_t *sniff_init(const char *if_name) 
{
	pcap_t *iface;
	if ((iface = pcap_create(if_name, errbuf)) == NULL) {
	 	fprintf(stderr, "Interface creation failed. \nYou might need to run this as either root or with a superuser priviledges.\n");
		pcap_perror(iface, "SEX");
		exit(EXIT_FAILURE);
	}
	if (pcap_activate(iface) != 0) {
		fprintf(stderr, "The interface might be activated, but with warnings.\nWhatever, exiting with a failure.\n");
		pcap_perror(iface, "SEX");
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "Interface initialization of `%s` successful.\n", if_name);
return iface;
}

void sniff_close(pcap_t *iface) 
{
	if (iface == NULL) 
		return;
	fprintf(stderr, "Closing interface.\n");
	pcap_close(iface);
}

int main(int argc, const char *argv[]) {
	pcap_t *iface;
	struct pcap_pkthdr **w = (struct pcap_pkthdr **) malloc(1 * sizeof(struct pcap_pkthdr *)); 
	u_char **what = (u_char **) malloc(1 * sizeof(u_char *)); 
	long long cc = 0;
	if (argc != 2) {
		fprintf(stderr, "Usage: `%s <interface>`\n", *argv);
		exit(EXIT_FAILURE);
	}
	/*
	print_all_devs();
	sleep(3);
	*/
	iface = sniff_init(argv[1]);
	while (1) {
		/*printf("%d\n", */pcap_next_ex(iface, w,(const u_char **) what)/*)*/;
		/*printf("%lld: %d: %s\n", cc, (*w)->caplen, *what);*/
		puts(*what);
		cc++;
	}
	free(w);
	free(what);
	sniff_close(iface);
return 0;
}

