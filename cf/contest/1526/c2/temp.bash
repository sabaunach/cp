#!/bin/bash

while [ true ]; do

    # start java in background &
    PID=$! # last background process started in this shell
    if [[ ! -d "exit_codes" ]]; then
        mkdir "exit_codes";
    fi
    while [true]; do
        
    fi


    java -Xmx$MAXRAM -Xms$MINRAM -jar $JAR nogui
    
    if [[ ! -f "exit_codes/server_exit_codes.log" ]]; then
        touch "exit_codes/server_exit_codes.log";
    fi
    echo "[$(date +"%d.%m.%Y %T")] ExitCode: $?" >> exit_codes/server_exit_codes.log
    echo "----- Press enter to prevent the server from restarting in $TIME seconds -----";
    read -t $TIME input;
    if [ $? == 0 ]; then
        break;
    else
        echo "------------------- SERVER RESTARTS -------------------";
    fi
done
