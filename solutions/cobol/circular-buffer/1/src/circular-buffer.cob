       IDENTIFICATION DIVISION.
       PROGRAM-ID. CIRCULAR-BUFFER.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-CAPACITY        PIC 999.
       01 WS-ITEM            PIC 9.
       01 WS-RESULT          PIC 9.
       01 WS-SUCCESS         PIC 9.

       01 WS-EMPTY-FLAG      PIC 9   VALUE 1.
          88 IS-EMPTY                VALUE 1 FALSE 0.

       01 WS-TABLE.
          05 WS-TABLE-ENTRY  PIC 9 OCCURS 1 TO 999 TIMES
                DEPENDING ON WS-CAPACITY
                INDEXED BY START-IDX, END-IDX.
            

       PROCEDURE DIVISION. 
       CREATE-BUFFER.
      *    Assumes WS-CAPACITY > 0
           MOVE 1 TO START-IDX
           MOVE 1 TO END-IDX
           SET IS-EMPTY TO TRUE
           .
           
      

       READ-BUFFER.
           IF IS-EMPTY
              MOVE 0 TO WS-SUCCESS
           ELSE 
              MOVE WS-TABLE-ENTRY(START-IDX) TO WS-RESULT
              COMPUTE START-IDX = FUNCTION MOD(
                 START-IDX + 1, WS-CAPACITY + 1)
              IF START-IDX = 0
                 MOVE 1 TO START-IDX
              END-IF
              IF START-IDX = END-IDX
                 SET IS-EMPTY TO TRUE
              END-IF
              MOVE 1 TO WS-SUCCESS               
           END-IF
           .


       WRITE-BUFFER.
           IF NOT IS-EMPTY AND START-IDX = END-IDX
              MOVE 0 TO WS-SUCCESS 
           ELSE 
              MOVE WS-ITEM TO WS-TABLE-ENTRY(END-IDX)
              COMPUTE END-IDX = FUNCTION MOD(
                 END-IDX + 1, WS-CAPACITY + 1)
              IF END-IDX = 0
                 MOVE 1 TO END-IDX
              END-IF
              SET IS-EMPTY TO FALSE
              MOVE 1 TO WS-SUCCESS        
           END-IF
           .


       OVERWRITE-BUFFER.
           IF NOT IS-EMPTY AND START-IDX = END-IDX
              COMPUTE START-IDX = FUNCTION MOD(
                 START-IDX + 1, WS-CAPACITY + 1)
              IF START-IDX = 0
                 MOVE 1 TO START-IDX
              END-IF
           END-IF
           
           MOVE WS-ITEM TO WS-TABLE-ENTRY(END-IDX)
           COMPUTE END-IDX = FUNCTION MOD(
              END-IDX + 1, WS-CAPACITY + 1)
           IF END-IDX = 0
              MOVE 1 TO END-IDX
           END-IF
           SET IS-EMPTY TO FALSE
           MOVE 1 TO WS-SUCCESS        
           .


       CLEAR-BUFFER.
           MOVE 1 TO START-IDX
           MOVE 1 TO END-IDX
           SET IS-EMPTY TO TRUE
           .