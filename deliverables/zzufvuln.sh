#!/bin/bash

./vuln2 input1.txt


sleep 2s


zzuf -j4 -m -s0: -r.1:1 ./vuln2 input1.txt


sleep 2s

zzuf -s10644 -r.1:1<input1.txt>vulncrash.file

sleep 2s

cat vulncrash.txt

sleep 2s

./vuln2 vulncrash.txt
