% Rule 1: Resistors in Series

series(R1, R2, Re) :-
    Re is R1 + R2.

% Rule 2: Resistors in Parallel

parallel(R1, R2, Re) :-
    Re is (R1 * R2) / (R1 + R2).

circuit(R5) :-
   
    R_10_40 is 10,
    R_40_is_40 is 40,
    parallel(R_10_40, R_40_is_40, R3),

    R_12_is_12 is 12,
    series(R3, R_12_is_12, R4),

    R_30_is_30 is 30,
    parallel(R4, R_30_is_30, R5).
