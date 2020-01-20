#!/bin/sh
#
# Examlple of using options in scripts
#
QUI=$PWD
NROC=14
NSUB=1000

#if [ $# -eq 0 ]
#then
#    echo "Missing options!"
#    echo "(run $0 -h for help)"
#    echo ""
#    exit 0
#fi
run_number_no_opt=$1
run_number_opt=$2
echo $run_number
while getopts "heDAE" OPTION; do
    case $OPTION in

	e)
	    echo " Hello world !"
	    exit 0
	    ;;

	h)
	    echo "Usage:"
	    echo ""
	    echo "   -e     to execute echo \"hello world\""
	    echo "   -h     help (this output)"
	    echo "   -D     Decode the RUN"
	    echo "   -A     Calibrate the RUN"
	    echo "   -E     Event creation of the RUN"
	    echo "   "
	    echo "   Run it as:"
	    echo "   GRATE Run_Number"
	    echo "   i.e. GRATE 102"
	    exit 0
	    ;;

	D)
	    echo " Decode the RUN"
	    for isub in $(seq 0 $NSUB);
	    do
		bash -c "$exe_ter -D $run_number_opt $isub"
		bash -c "$exe_ter -V $run_number_opt $isub"
	    done
	    echo "Terminated decoding"
	    exit 0
	    ;;
	A)
	    echo " Calibrate the RUN"
            for isub in $(seq 0 $NSUB);
            do
                bash -c "$exe_ter -A $run_number_opt $isub"
            done
            echo "Terminated calibration"
            exit 0
            ;;
        E)
            echo " Event reconstruction of the RUN"
            for isub in $(seq 0 $NSUB);
            do
                bash -c "$exe_ter -E $run_number_opt $isub"
            done
            echo "Terminated event reconstruction"
            exit 0
	    ;;
	


    esac
done

#Purger
cd /home/ihep_data/data/raw_dat
python purger.py
cd -
#
if [ -z $run_number_no_opt ]; then echo "Use the command 'GRATE Run_Number'"; exit; fi
if [    $run_number_no_opt ]; then cd; bash -c "source WenGraal.sh ${run_number_no_opt}"; cd $QUI; exit; fi

