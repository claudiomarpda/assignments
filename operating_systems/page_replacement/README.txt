This program simulates the operation of the following algorithms for page replacement:

FIFO (first in, first out)
OPT (optimus)
LRU (least-recently-used)

INPUT
A set of integer numbers, where the first one represents the amount of memory frame that is available in RAM, and the rest represent the sequence of references for the pages, always one number per line.

OUTPUT
The initials of each one of the three algorithms and their respective amount of missing pages.

INPUT EXAMPLE
-----------------------------
4
1
2
3
4
1
2
5
1
2
3
4
5
-----------------------------

OUTPUT EXAMPLE
-----------------------------
FIFO 10
OPT 6
LRU 8
-----------------------------
