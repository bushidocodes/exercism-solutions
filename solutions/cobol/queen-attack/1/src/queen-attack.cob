      * Queen Attack Program
      * Implements the Exercism Queen Attack exercise
      * Validates queen positions and checks attack possibilities 
      * on 8x8 chessboard
       IDENTIFICATION DIVISION.
       PROGRAM-ID. QUEEN-ATTACK.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
      * Input variables for queen positions and operation type
       01 WS-QUEEN             PIC X(9).
       01 WS-WHITE_QUEEN       PIC X(9).
       01 WS-BLACK_QUEEN       PIC X(9).
       01 WS-PROPERTY          PIC X(11).
      * Output variable: 1 = true/valid, 0 = false/invalid
       01 WS-RESULT            PIC 9.
      * Parsed coordinates for queen positions
       01 WS-ROW               PIC S99.
       01 WS-COL               PIC S99.
       01 WS-WHITE-ROW         PIC S99.
       01 WS-BLACK-ROW         PIC S99.
       01 WS-WHITE-COL         PIC S99.
       01 WS-BLACK-COL         PIC S99.
      * Temporary variables for position parsing
       01 WS-COMMA-POS         PIC 99.
       01 WS-CURRENT-POSITION  PIC X(9).
       01 WS-CURRENT-ROW       PIC S99.
       01 WS-CURRENT-COL       PIC S99.
       
       PROCEDURE DIVISION.
      * Main program entry point - dispatches based on operation type
       QUEEN-ATTACK.
           EVALUATE WS-PROPERTY
           WHEN "create"
                PERFORM VALIDATE-QUEEN
           WHEN "canAttack"
                PERFORM CHECK-ATTACK
           END-EVALUATE
           .
           
      * Validates if queen pos is on the 8x8 board (rows/cols 0-7)
       VALIDATE-QUEEN.
           MOVE WS-QUEEN TO WS-CURRENT-POSITION
           PERFORM PARSE-POSITION
           MOVE WS-CURRENT-ROW TO WS-ROW
           MOVE WS-CURRENT-COL TO WS-COL
           IF WS-ROW >= 0 AND WS-ROW <= 7 AND WS-COL >= 0
              AND WS-COL <= 7
              MOVE 1 TO WS-RESULT
           ELSE
              MOVE 0 TO WS-RESULT
           END-IF
           .

      * Checks if white and black queens can attack each other
      * Queens attack on same row, column, or diagonal
       CHECK-ATTACK.
           MOVE WS-WHITE_QUEEN TO WS-CURRENT-POSITION
           PERFORM PARSE-POSITION
           MOVE WS-CURRENT-ROW TO WS-WHITE-ROW
           MOVE WS-CURRENT-COL TO WS-WHITE-COL
           MOVE WS-BLACK_QUEEN TO WS-CURRENT-POSITION
           PERFORM PARSE-POSITION
           MOVE WS-CURRENT-ROW TO WS-BLACK-ROW
           MOVE WS-CURRENT-COL TO WS-BLACK-COL
           IF WS-WHITE-ROW = WS-BLACK-ROW
              OR WS-WHITE-COL = WS-BLACK-COL OR
              FUNCTION ABS(WS-WHITE-ROW - WS-BLACK-ROW) =
              FUNCTION ABS(WS-WHITE-COL - WS-BLACK-COL)
              MOVE 1 TO WS-RESULT
           ELSE
              MOVE 0 TO WS-RESULT
           END-IF
           .

      * Parses position string "row,col" into numeric row and column
       PARSE-POSITION.
           MOVE 0 TO WS-COMMA-POS
           INSPECT WS-CURRENT-POSITION TALLYING WS-COMMA-POS
              FOR CHARACTERS BEFORE ','
           COMPUTE WS-COMMA-POS = WS-COMMA-POS + 1
           COMPUTE WS-CURRENT-ROW =
              FUNCTION NUMVAL(WS-CURRENT-POSITION(1:WS-COMMA-POS - 1))
           COMPUTE WS-CURRENT-COL =
              FUNCTION NUMVAL(WS-CURRENT-POSITION(WS-COMMA-POS + 1:))
           .