       IDENTIFICATION DIVISION.
       PROGRAM-ID. PROTEIN-TRANSLATION.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-INPUT        PIC X(60).
       77 WS-INPUT-LEN    PIC 99.
       01 WS-PROTEIN      PIC X(120).
       77 WS-PROTEIN-PTR  PIC 99.
       01 WS-ERROR        PIC X(60).
       77 I               PIC 99.

       PROCEDURE DIVISION.

       TRANSLATE-CODON.
           INITIALIZE WS-PROTEIN
           INITIALIZE WS-ERROR
           MOVE FUNCTION LENGTH(FUNCTION TRIM(WS-INPUT))
              TO WS-INPUT-LEN
           MOVE 1 TO I
           MOVE 1 TO WS-PROTEIN-PTR 
           PERFORM TRANSLATE-CODON-INNER
           .

       TRANSLATE-RNA.
           INITIALIZE WS-PROTEIN
           INITIALIZE WS-ERROR
           MOVE FUNCTION LENGTH(FUNCTION TRIM(WS-INPUT))
              TO WS-INPUT-LEN
           MOVE 1 TO WS-PROTEIN-PTR 

           PERFORM TRANSLATE-CODON-INNER VARYING I FROM 1 BY 3
              UNTIL I > WS-INPUT-LEN OR WS-INPUT(I:3) = "UAA"
              OR WS-INPUT(I:3) = "UAG" OR WS-INPUT(I:3) = "UGA"
              OR WS-ERROR NOT = SPACES
           .

       TRANSLATE-CODON-INNER.
           EVALUATE WS-INPUT(I:3)
           WHEN "AUG"
                PERFORM ADD-COMMA
                STRING "Methionine" DELIMITED BY SIZE
                   INTO WS-PROTEIN WITH POINTER WS-PROTEIN-PTR       
           WHEN "UUU"
           WHEN "UUC"
                PERFORM ADD-COMMA
                STRING "Phenylalanine" DELIMITED BY SIZE
                   INTO WS-PROTEIN WITH POINTER WS-PROTEIN-PTR       
           WHEN "UUA"
           WHEN "UUG"
                PERFORM ADD-COMMA
                STRING "Leucine" DELIMITED BY SIZE
                   INTO WS-PROTEIN WITH POINTER WS-PROTEIN-PTR       
           WHEN "UCU"
           WHEN "UCC"
           WHEN "UCA"
           WHEN "UCG"
                PERFORM ADD-COMMA
                STRING "Serine" DELIMITED BY SIZE
                   INTO WS-PROTEIN WITH POINTER WS-PROTEIN-PTR       
           WHEN "UAU"
           WHEN "UAC"
                PERFORM ADD-COMMA
                STRING "Tyrosine" DELIMITED BY SIZE
                   INTO WS-PROTEIN WITH POINTER WS-PROTEIN-PTR       
           WHEN "UGU"
           WHEN "UGC"
                PERFORM ADD-COMMA
                STRING "Cysteine" DELIMITED BY SIZE
                   INTO WS-PROTEIN WITH POINTER WS-PROTEIN-PTR       
           WHEN "UGG"
                PERFORM ADD-COMMA
                STRING "Tryptophan" DELIMITED BY SIZE
                   INTO WS-PROTEIN WITH POINTER WS-PROTEIN-PTR       
           WHEN "UAA"
           WHEN "UAG"
           WHEN "UGA"
                CONTINUE
           WHEN OTHER
                MOVE "Invalid codon" TO WS-ERROR
           END-EVALUATE
           .

       ADD-COMMA.
           IF WS-PROTEIN-PTR > 1
              STRING "," DELIMITED BY SIZE
                 INTO WS-PROTEIN WITH POINTER
                 WS-PROTEIN-PTR
           END-IF
           .