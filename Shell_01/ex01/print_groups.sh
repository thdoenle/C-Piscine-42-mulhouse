id -Gn $(printenv FT_USER) | sed "s/ /,/g" | tr -d "\n"
