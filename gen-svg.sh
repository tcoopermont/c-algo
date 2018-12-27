#!/bin/bash
./gen-seg > run.txt
cat grid-st.part > grid.html
cat run.txt  | ./find-points >> grid.html
cat grid-end.part >> grid.html

cat grid-st.part > grid2.html
cat run.txt  | ./track-segs >> grid2.html
cat grid-end.part >> grid2.html
