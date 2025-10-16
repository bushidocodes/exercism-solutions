       IDENTIFICATION DIVISION.
       PROGRAM-ID. ROBOT-SIMULATOR.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
      * Input and Output
       01 WS-X-COORD           PIC S999.
       01 WS-Y-COORD           PIC S999.
       01 WS-DIRECTION         PIC X(20).
       01 WS-INSTRUCTIONS      PIC X(60).
      * Locals
       77 WS-INSTRUCTIONS-LEN  PIC 99.
       77 I                    PIC 99.
       
       PROCEDURE DIVISION.
       
       CREATE-ROBOT.
      *Nothing to do!

       MOVE-ROBOT.
           MOVE FUNCTION LENGTH(FUNCTION TRIM(WS-INSTRUCTIONS))
              TO WS-INSTRUCTIONS-LEN

           PERFORM VARYING I FROM 1 BY 1 UNTIL I > WS-INSTRUCTIONS-LEN
                   EVALUATE WS-INSTRUCTIONS(I:1)
                   WHEN 'R'
                        PERFORM TURN-RIGHT 
                   WHEN 'L'
                        PERFORM TURN-LEFT 
                   WHEN 'A'
                        PERFORM ADVANCE 
                   END-EVALUATE
           END-PERFORM
           .

       TURN-RIGHT.
           EVALUATE WS-DIRECTION
           WHEN "north"
                MOVE "east" TO WS-DIRECTION
           WHEN "east"
                MOVE "south" TO WS-DIRECTION
           WHEN "south"
                MOVE "west" TO WS-DIRECTION
           WHEN "west"
                MOVE "north" TO WS-DIRECTION
           END-EVALUATE
           .

       TURN-LEFT.
           EVALUATE WS-DIRECTION
           WHEN "north"
                MOVE "west" TO WS-DIRECTION
           WHEN "west"
                MOVE "south" TO WS-DIRECTION
           WHEN "south"
                MOVE "east" TO WS-DIRECTION
           WHEN "east"
                MOVE "north" TO WS-DIRECTION
           END-EVALUATE
           .

       ADVANCE.
           EVALUATE WS-DIRECTION
           WHEN "north"
                ADD 1 TO WS-Y-COORD
           WHEN "west"
                SUBTRACT 1 FROM WS-X-COORD
           WHEN "south"
                SUBTRACT 1 FROM WS-Y-COORD
           WHEN "east"
                ADD 1 TO WS-X-COORD
           END-EVALUATE
           .