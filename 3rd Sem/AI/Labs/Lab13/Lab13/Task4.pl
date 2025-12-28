inside(b2, b1).
inside(b3, b2).
inside(b6, b3).
inside(b4, b2).
% Base case: direct
encloses(A, B) :-
    inside(B, A).

% Recursive case
encloses(A, B) :-
    inside(C, A),
    encloses(C, B).
