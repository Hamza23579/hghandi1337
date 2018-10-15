#!/bin/sh
find . -name "*.sh" | cut -c3- | rev | cut -c4- | rev | sed  's/.*\///g'
