#!/bin/bash

#for irun in {337,338,339,340,341,343,351,368,370,372,375,355,376,377,378,387,396,397,400}; 
#for irun in {405,406,408,409,410,411,412};
for irun in {420, 421}
do
    for isub in {0..2000}; 
    do 
	if [ -f "/home/ihep_data/data/raw_root/${irun}/Sub_RUN_event_${isub}.root" ]; 
	then echo "Found"; cp /home/ihep_data/data/raw_root/${irun}/Sub_RUN_event_${isub}.root /home/ihep_data/data/raw_graal/subrun/run716392${irun}_${isub}.root; 
	fi; 
    done;
done;
