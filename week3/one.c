#include <syslog.h>

int main(int argc, const char *argv[]) {
	openlog("a.out", LOG_PID, 0);
	syslog(LOG_INFO, "omw?!?!?!?!?");
	openlog("a.out", LOG_PID, 1);
	syslog(LOG_INFO, "omw?!?!?!?!?");
	openlog("a.out", LOG_PID, -1);
	syslog(LOG_SYSLOG, "omw?!?!?!?!?");
	openlog("a.out", LOG_PID, 2);
	syslog(LOG_SYSLOG, "omw?!?!?!?!?");
	openlog("a.out", LOG_PID, LOG_SYSLOG);
	syslog(LOG_SYSLOG, "omw?!?!?!?!?");
	syslog(LOG_EMERG, "omwwww?!?!?!?!?");
	closelog();
return 0;
}
