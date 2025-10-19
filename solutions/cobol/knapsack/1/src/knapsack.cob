000100 IDENTIFICATION DIVISION.
000110 PROGRAM-ID. KNAPSACK.
000120 ENVIRONMENT DIVISION.
000130 DATA DIVISION.
000140 WORKING-STORAGE SECTION.
000150 01 WS-INPUTS.
000160    05 MAXIMUM-WEIGHT  PIC 999.
000170    05 NO-OF-ITEMS     PIC 99.
000180    05 KNAPSACKTABLE.
000190       10 WS-WEIGHT OCCURS 20 TIMES
                             PIC 999.
000200       10 WS-VALUE OCCURS 20 TIMES
                             PIC 999.
000220 01 WS-OUTPUTS.
000230    05 WS-RESULT       PIC 9(5).
000240*---------------------------------------------------------------*
000250* Dynamic programming working storage                           *
000260*---------------------------------------------------------------*
000270 01 DP-TABLE.
000280    05 DP-CELL OCCURS 1001 TIMES
                             PIC 9(5) VALUE ZERO.
000290 01 DP-VARS.
000300    05 I               PIC 99.
000310    05 W               PIC 999.
000320    05 W-ITEM          PIC 999.
000330    05 V-ITEM          PIC 999.
000340    05 NEW-VAL         PIC 9(5).
000350    05 DP-W-INDEX      PIC 999.
000360    05 DP-SUB-INDEX    PIC 999.

000370 PROCEDURE DIVISION.

000380 MAXIMUM-VALUE.
000390* Initialize DP table to zero: DP-CELL(1) represents weight 0.
000400     INITIALIZE DP-TABLE.

000410* Iterate over each item supplied by the tests.
000420     PERFORM VARYING I FROM 1 BY 1 UNTIL I > NO-OF-ITEMS
000430             MOVE WS-WEIGHT(I) TO W-ITEM
000440             MOVE WS-VALUE(I) TO V-ITEM
000450             IF W-ITEM > 0 THEN
000460* Capacity loop runs backwards so each item is used at most once.
000470             PERFORM VARYING W FROM MAXIMUM-WEIGHT BY -1
000480-                    UNTIL W < W-ITEM
000490                        COMPUTE DP-W-INDEX = W + 1
000500                        COMPUTE DP-SUB-INDEX = W - W-ITEM + 1
000510                        COMPUTE NEW-VAL = V-ITEM + DP-CELL
                                 (DP-SUB-INDEX)
000520                        IF NEW-VAL > DP-CELL(DP-W-INDEX)
000530                           MOVE NEW-VAL TO DP-CELL(DP-W-INDEX)
000540                        END-IF
000550                END-PERFORM
000560             END-IF
000570     END-PERFORM.

000580* The DP entry at capacity MAXIMUM-WEIGHT holds the best value.
000590     MOVE DP-CELL(MAXIMUM-WEIGHT + 1) TO WS-RESULT.