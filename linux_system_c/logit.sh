#!/bin/sh

# logger.sh - Demonstrate the shell command interface to syslog

echo "Type the log message and press ENTER"
read MSG
logger -is -t logger.sh $MSG
