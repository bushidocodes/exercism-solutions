       IDENTIFICATION DIVISION.
       PROGRAM-ID. PASCALS-TRIANGLE.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-COUNT              PIC 99.
       
       01 WS-RESULT. 
          02 WS-ROW OCCURS 1 TO 99 DEPENDING ON WS-COUNT.
             05 ROWELEM         PIC X(60).
       
      *>   Working variables for Pascal's Triangle computation
       01 WS-WORK-AREA.
      *>   Array to store current row values
          02 WS-CURR-ROW.
             03 WS-CURR-VAL     PIC 999 OCCURS 99 TIMES.
                                
      *>   Array to store previous row values
          02 WS-PREV-ROW.
             03 WS-PREV-VAL     PIC 999 OCCURS 99 TIMES.
      *>   Loop counters and indices
          02 WS-ROW-IDX         PIC 99.
          02 WS-COL-IDX         PIC 99.
          02 WS-INIT-IDX        PIC 99.
          02 WS-COPY-IDX        PIC 99.
      *>   Temporary string building area
          02 WS-TEMP-STR        PIC X(60).
          02 WS-NUM-EDIT        PIC ZZZ.
          02 WS-LEADING-SPACES  PIC 99.
       
       PROCEDURE DIVISION.
       
       ROWS.
      *>   Handle zero rows case
           IF WS-COUNT = 0
              EXIT PARAGRAPH
           END-IF
           
      *>   Initialize all arrays to zeros
           INITIALIZE WS-CURR-ROW
           INITIALIZE WS-PREV-ROW
      *>   Initialize the last element separately
           MOVE 0 TO WS-CURR-VAL(99)
           MOVE 0 TO WS-PREV-VAL(99)
           
      *>   Generate each row of Pascal's Triangle
           PERFORM VARYING WS-ROW-IDX FROM 1 BY 1
              UNTIL WS-ROW-IDX > WS-COUNT
              
      *>      First element of each row is always 1
                   MOVE 1 TO WS-CURR-VAL(1)
              
      *>      Calculate middle elements using previous row
                   IF WS-ROW-IDX > 1
                      PERFORM VARYING WS-COL-IDX FROM 2 BY 1
                         UNTIL WS-COL-IDX > WS-ROW-IDX
      *>            Each element = sum of two elements above it
                              ADD WS-PREV-VAL(WS-COL-IDX - 1)
                                  WS-PREV-VAL(WS-COL-IDX)
                                 GIVING WS-CURR-VAL(WS-COL-IDX)
                      END-PERFORM
                   END-IF
              
      *>      Format current row as comma-separated string
                   MOVE SPACES TO WS-TEMP-STR
              
                   PERFORM VARYING WS-COL-IDX FROM 1 BY 1
                      UNTIL WS-COL-IDX > WS-ROW-IDX
                 
      *>         Convert number to edited format to trim leading zeros
                           MOVE WS-CURR-VAL(WS-COL-IDX) TO WS-NUM-EDIT
                 
      *>         Count leading spaces in edited number
                           MOVE ZERO TO WS-LEADING-SPACES
                           INSPECT WS-NUM-EDIT TALLYING
                              WS-LEADING-SPACES
                              FOR LEADING SPACE
                 
      *>         Build comma-separated result string
                           IF WS-COL-IDX > 1
      *>            Add comma separator
                              STRING WS-TEMP-STR DELIMITED BY SPACE
                                     "," DELIMITED BY SIZE
                                     WS-NUM-EDIT(WS-LEADING-SPACES + 1:)
                                 DELIMITED BY SPACE
                                 INTO WS-TEMP-STR
                              END-STRING
                           ELSE
      *>            First element - no comma
                              STRING WS-NUM-EDIT(WS-LEADING-SPACES + 1:)
                                 DELIMITED BY SPACE
                                 INTO WS-TEMP-STR
                              END-STRING
                           END-IF
                   END-PERFORM
              
      *>      Store formatted row in result array
                   MOVE WS-TEMP-STR TO ROWELEM(WS-ROW-IDX)
              
      *>      Copy row for next iteration and clear current values
                   MOVE WS-CURR-ROW TO WS-PREV-ROW
                   INITIALIZE WS-CURR-ROW
           END-PERFORM.