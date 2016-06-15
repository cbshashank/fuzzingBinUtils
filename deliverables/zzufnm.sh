#!/bin/bash
zzuf -mq -s1: objdump -x ./vuln2

sleep 5s


zzuf -s141 <./vuln2> objdumpcrash.file


objdump -x objdumpcrash.file 


