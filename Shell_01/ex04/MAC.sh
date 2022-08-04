ifconfig -a | grep -e ether | awk -F " " '{ print $2 }'
