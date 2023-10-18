#!/bin/bash 
LOGBOOK='log.run999'
RUN_ID=999
start=`date +%s`
sleep 1s

ts -S 40
echo "Init RUN $RUNID" >> $LOGBOOK
date >> $LOGBOOK
echo "Start GRATE" >> $LOGBOOK
#$exe_grate $RUN_ID
echo "End GRATE" >> $LOGBOOK
date >> $LOGBOOK
echo "Sleep 1h" >> $LOGBOOK
sleep 1s
date >> $LOGBOOK
echo "Start TER X" >> $LOGBOOK
#$exe_ter -X $RUN_ID
echo "End TER X" >> $LOGBOOK
date >> $LOGBOOK
echo "Sleep 5h" >> $LOGBOOK
sleep 5s
date >> $LOGBOOK
echo "Start LUT" >> $LOGBOOK
#$exe_grate -L $RUN_ID
echo "Start QAQC" >> $LOGBOOK
#ts -df $exe_grate -Q $RUN_ID
date >> $LOGBOOK


date >> $LOGBOOK
echo "$RUN_ID" >> $LOGBOOK
echo "Duration: $((($(date +%s)-$start))) seconds" >> $LOGBOOK

