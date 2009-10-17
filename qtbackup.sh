#!/bin/sh

cat qtbackup.conf | xargs tar zcf /media/card/qtbackup.tgz > /dev/null 2>&1
