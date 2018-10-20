#!/bin/sh
ldapsearch -xLLL '(uid=z*)' | grep "^cn: " | sort -r -d | cut -c5-
