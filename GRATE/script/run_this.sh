#!/bin/sh 
LOGBOOK='log.time'
start=`date +%s`
sleep 1s
$exe_ter -X 338
date >> $LOGBOOK
echo "Duration: $((($(date +%s)-$start))) seconds" >> $LOGBOOK

start=`date +%s`
sleep 1s
$exe_ter -X 387
date >> $LOGBOOK
echo "Duration: $((($(date +%s)-$start))) seconds" >> $LOGBOOK

start=`date +%s`
sleep 1s
$exe_ter -X 383
date >> $LOGBOOK
echo "Duration: $((($(date +%s)-$start))) seconds" >> $LOGBOOK

start=`date +%s`
sleep 1s
$exe_ter -X 384
date >> $LOGBOOK
echo "Duration: $((($(date +%s)-$start))) seconds" >> $LOGBOOK

start=`date +%s`
sleep 1s
$exe_ter -X 385
date >> $LOGBOOK
echo "Duration: $((($(date +%s)-$start))) seconds" >> $LOGBOOK
