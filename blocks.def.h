//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"Bat:", "awk '{print $1 \"%\"}' /sys/class/power_supply/BAT0/capacity",		10,		0},
	{"Wifi:", " cat /sys/class/net/wlan0/operstate",					10,		0},
	{"", "awk '/32 host/{print a}{a=$2}' /proc/net/fib_trie | awk 'NR==4{print}'",		10,		0},
	{"Mem:", "free -h | awk '/^Mem/{print $3}' | sed s/i//g",				10,		0},
	{"/:", "df -h | awk '/root/{print $4}'",						60,		0},
	{"", "date '+%b %d (%a) %I:%M%p'",							5,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
