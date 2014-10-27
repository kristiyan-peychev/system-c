#Getting logs from your pulseaudio
##The hard ~~core~~ way

First off, pulseaudio does _not_ create logs by default, unless something really bad happens, in which case it will send a log in usually /var/log/messages, but this depends on your distro.

The way I saw one could get logs from pulseaudo is: 
1. Kill the pulseaudio process, it wasn't a service on my Fedora.
2. Start the process with the same arguments as before and add a -v argument for a verbose output.
	* Adding more v's will result in more and more verbose output, with a maximum of 4 v's, or at least this is how much my version of pulseaudio supports.
3. You will be wise to redirect _stderr_ to some file, because that's where you'll be getting your logs.

**Warning**: This might ruin your sound and may require extensive killing _or_ at worst a system reboot. But will dump a lot of info about pulse.

##Note
The **one.c** file in this directory will just create a few logs in your default log file and is mostly unrelated to the topic mentioned above.

