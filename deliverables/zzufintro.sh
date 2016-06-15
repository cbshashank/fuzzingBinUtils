#/bin/bash
cat input.txt


sleep 5s

zzuf -s0:4 -r.01  cat input.txt

sleep 2s

zzuf -s0:4 -m -r.01 cat input.txt



