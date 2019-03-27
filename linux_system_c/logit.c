/*
 * logit.c - Demonstrate the syslog interface
 */

#include <syslog.h>
#include <stdio.h>
#include <unistd.h> /* getuid() */
#include <sys/types.h> /* getuid() */
#include <stdlib.h>

int main(void)
{
    int cmask; /* The old priority mask */

    openlog("logit",LOG_PID, LOG_USER);
    syslog(LOG_INFO, "This message countesy of UID #%d\n",getuid());
    syslog(LOG_NOTICE, "Hopefully, you see this\n");
    closelog(); /* Reset the facility */
    /* Don't want to see DEBUG and INFO message */
    cmask = setlogmask(LOG_UPTO(LOG_NOTICE));
    syslog(LOG_INFO, "YOu should not be seeing this\n");
    syslog(LOG_DEBUG, "I hope dont see this\n");
    syslog(LOG_NOTICE, "Restoring the old priority mask\n");
    /* Restore original priority mask */
    setlogmask(cmask);
    syslog(LOG_INFO, "You  should see this");
    syslog(LOG_DEBUG, "I hope you see this");
    exit(EXIT_SUCCESS);
}
